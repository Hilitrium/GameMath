#pragma once
#include "vec2.h"
#include "Transform.h"

class Rigidbody {
public:
	float mass;
	vec2 velocity, //speed * direction
		acceleration, // A = F/M
		force,
		impulse;

	float drag;

	float angularVelocity;
	float angularAcceleration, torque;
	float angularDrag;

	Rigidbody() : velocity{ 0,0 }, acceleration{ 0,0 }, force{ 0,0 }, impulse{ 0,0 }, mass(1), drag(1),
		angularVelocity(0), angularAcceleration(0), torque(0), angularDrag(.25f) {

	}


	void integrate(Transform &T, float dt) {
		
		//linear motion
		acceleration = force / mass;
		vec2 tempImp = impulse / mass;
		vec2 tempAccel = acceleration * dt;
		vec2 tempImpAccel = tempAccel + tempImp;
		velocity += tempImpAccel;
		vec2 tempVel = velocity * dt;
		T.position += tempVel;
		impulse = { 0,0 };
		vec2 InverseVel = velocity * -1;
		force = InverseVel * drag;

		//angular motion (sort of)
		angularAcceleration = torque / mass;
		angularVelocity = angularAcceleration * dt;
		T.angle += angularVelocity * dt;

		torque = -angularVelocity * angularDrag;
	}
};