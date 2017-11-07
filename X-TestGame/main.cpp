#include "sfwdraw.h"
#include "Person.h"
#include "DrawShape.h"
#include <Windows.h>
int main() {
	sfw::initContext();

	Player player;

	player.draw();
	player.transform.dimension = vec2{ 64, 64 };
	player.transform.position = vec2{ 400,300 };
	player.collider.box.extents = { .5, .5 };

	Wall walls[2];
	walls[0].transform.position = { 600,300 };
	walls[0].transform.dimension = { 80,240 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("../resources/Giant_Tree.png");

	walls[1].transform.position = { 200,300 };
	walls[1].transform.dimension = { 80,240 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = walls[0].sprite.handle;

	Ball ball;//ihavenoideawhatiamdoing
	ball.transform.position = { 400,300 };
	ball.sprite.handle = sfw::loadTextureMap("../resources/Gungeon.jpg");
	ball.transform.dimension = { 32,32 };
	ball.collider.box.extents = { .5,.5 };
	ball.rigidbody.velocity = { 200,0 };
	ball.rigidbody.drag = 0;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		// update controllers0
		player.controller.poll(player.rigidbody, player.transform);

		// update rigibodies
		player.rigidbody.integrate(player.transform, dt);
		ball.rigidbody.integrate(ball.transform, dt);

		// draw stuff
		player.sprite.draw(player.transform);
		ball.sprite.draw(ball.transform);
		for (int i = 0; i < 2; ++i)
			walls[i].sprite.draw(walls[i].transform);

		// Collision resolution
		for (int i = 0; i < 2; ++i)
		{
			doCollision(player, walls[i]);
			doCollision(ball, walls[i]);
		}

		doCollision(player, ball);

		// Debug boxes
		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		for (int i = 0; i < 2; ++i)
			drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
	}
	sfw::termContext();

}
















 
//int main()
//{
//	sfw::initContext();
//
//	Transform transform;
//	Rigidbody rigidbody;
//	circle c = { {0,0},1 };
//	transform.position = vec2{ 400, 300 };
//	
//	while (sfw::stepContext())
//	{
//		float dt = sfw::getDeltaTime();
//
//		//rigidbody.force = { 0,-1 };//gravity
//
//		//moving jets
//		vec2 AppliedForce = transform.getGlobalTransform()[1].xy * 50;
//		//std::cout << "X:" << AppliedForce.x << "Y: " << AppliedForce.y << std::endl;
//		if (sfw::getKey('W'))rigidbody.force += AppliedForce;
//		if (sfw::getKey('A'))rigidbody.torque += (720 * 2);
//		//if (sfw::getKey('S'))rigidbody.force += { 0, -100 };
//		if (sfw::getKey('D'))rigidbody.torque += (-720 * 2);
//		
//		DrawMatrix(transform.getGlobalTransform(), 45);
//		rigidbody.integrate(transform, dt);
//		
//		
//	}
//
//	sfw::termContext();

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
//}

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