
#include "sfwdraw.h"
#include "Transform.h"
#include "Rigidbody.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
int main()
{
	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	transform.position = vec2{ 400, 300 };

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		//rigidbody.force = { 0,-1 };//gravity

		//moving jets
		vec2 AppliedForce = transform.getGlobalTransform()[1].xy * 50;
		//std::cout << "X:" << AppliedForce.x << "Y: " << AppliedForce.y << std::endl;
		if (sfw::getKey('W'))rigidbody.force += AppliedForce;
		if (sfw::getKey('A'))rigidbody.torque += 360;
		//if (sfw::getKey('S'))rigidbody.force += { 0, -100 };
		if (sfw::getKey('D'))rigidbody.torque += -360;
		
		DrawMatrix(transform.getGlobalTransform(), 45);
		rigidbody.integrate(transform, dt);
		
		
	}

	sfw::termContext();

	/*sfw::initContext(800,800);

	Transform myTrans;
	myTrans.position = vec2{ 400,300 };
	myTrans.dimension = vec2{ 1,1 };
	myTrans.angle = 0;
	

	while (sfw::stepContext())
	{
		myTrans.angle += sfw::getDeltaTime() * 20;
		DrawMatrix(myTrans.getGlobalTransform(), 30);
	}

	sfw::termContext();*/
}

//#include "sfwdraw.h"
//#include "Transform.h"
//#include "myGuy.h"
//#include "mat3.h"
//#include <cmath>
//
//int main() {
//	sfw::initContext();
//
//	myGuy me(3, 5, vec2{ 300, 400 }, vec2{ 256,256 }, 0);
//
//}