#pragma once

// controller -> rigidbody -> transform
#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

// Poll for input and apply changes to the rigidbody
class Controller
{

public:
	float turningSpeed;
	float speed;
	float brakePower;

	Controller() : turningSpeed(6000), speed(300), brakePower(8)
	{

	}

	void poll(Rigidbody &rb, const Transform &t)
	{

		if (sfw::getKey('W'))
		{
			vec2 normal = norm(t.getLocalTransform()[1].xy);
			vec2 desiredForce = normal * speed;
			rb.force += desiredForce;
				
		}
		if (sfw::getKey('A'))rb.torque += turningSpeed;
		if (sfw::getKey('D'))rb.torque += -turningSpeed;

		if (sfw::getKey('S')) //breaking force
		{
			rb.force += (-1 * rb.velocity) * brakePower;
			rb.torque += -rb.angularVelocity * brakePower;
		}
	}
};