#include "sfwdraw.h"
#include "Person.h"
#include "DrawShape.h"
#include <Windows.h>
int main() {
	sfw::initContext();

	Player player;

	player.transform.dimension = vec2{ 20, 34 };
	player.transform.position = vec2{ 60,550 };
	player.collider.box.extents = { .5, .5 };
	player.sprite.handle = sfw::loadTextureMap("res/Player.png");

	Wall walls[29];
	walls[0].transform.position = { 0,0 };
	walls[0].transform.dimension = { 40,1200 };
	walls[0].collider.box.extents = { .5,.5 };
	walls[0].sprite.handle = sfw::loadTextureMap("res/BrickWall.png");

	walls[1].transform.position = { 800, 20 };
	walls[1].transform.dimension = { 40,1200 };
	walls[1].collider.box.extents = { .5,.5 };
	walls[1].sprite.handle = walls[0].sprite.handle;

	walls[2].transform.position = { 500,600 };
	walls[2].transform.dimension = { 690,40 };
	walls[2].collider.box.extents = { .5,.5 };
	walls[2].sprite.handle = walls[0].sprite.handle;

	walls[3].transform.position = { 350,0 };
	walls[3].transform.dimension = { 690,40 };
	walls[3].collider.box.extents = { .5,.5 };
	walls[3].sprite.handle = walls[0].sprite.handle;

	walls[4].transform.position = { 0,230 };
	walls[4].transform.dimension = { 300,20 };
	walls[4].collider.box.extents = { .5,.5 };
	walls[4].sprite.handle = walls[0].sprite.handle;

	walls[5].transform.position = { 300,330 };
	walls[5].transform.dimension = { 200,20 };
	walls[5].collider.box.extents = { .5,.5 };
	walls[5].sprite.handle = walls[0].sprite.handle;

	walls[6].transform.position = { 0,230 };
	walls[6].transform.dimension = { 300,20 };
	walls[6].collider.box.extents = { .5,.5 };
	walls[6].sprite.handle = walls[0].sprite.handle;

	walls[7].transform.position = { 300,475 };
	walls[7].transform.dimension = { 20,300 };
	walls[7].collider.box.extents = { .5,.5 };
	walls[7].sprite.handle = walls[0].sprite.handle;

	walls[8].transform.position = { 200,395 };
	walls[8].transform.dimension = { 20,150 };
	walls[8].collider.box.extents = { .5,.5 };
	walls[8].sprite.handle = walls[0].sprite.handle;

	walls[9].transform.position = { 250,268 };
	walls[9].transform.dimension = { 20,100 };
	walls[9].collider.box.extents = { .5,.5 };
	walls[9].sprite.handle = walls[0].sprite.handle;

	walls[10].transform.position = { 400,245 };
	walls[10].transform.dimension = { 20,200 };
	walls[10].collider.box.extents = { .5,.5 };
	walls[10].sprite.handle = walls[0].sprite.handle;

	walls[11].transform.position = { 325,155 };
	walls[11].transform.dimension = { 150,20 };
	walls[11].collider.box.extents = { .5,.5 };
	walls[11].sprite.handle = walls[0].sprite.handle;

	walls[12].transform.position = { 260,130 };
	walls[12].transform.dimension = { 20,50 };
	walls[12].collider.box.extents = { .5,.5 };
	walls[12].sprite.handle = walls[0].sprite.handle;

	walls[13].transform.position = { 196,100 };
	walls[13].transform.dimension = { 150,20 };
	walls[13].collider.box.extents = { .5,.5 };
	walls[13].sprite.handle = walls[0].sprite.handle;

	walls[14].transform.position = { 196,100 };
	walls[14].transform.dimension = { 150,20 };
	walls[14].collider.box.extents = { .5,.5 };
	walls[14].sprite.handle = walls[0].sprite.handle;

	walls[14].transform.position = { 550,100 };
	walls[14].transform.dimension = { 150,20 };
	walls[14].collider.box.extents = { .5,.5 };
	walls[14].sprite.handle = walls[0].sprite.handle;

	walls[15].transform.position = { 550,55 };
	walls[15].transform.dimension = { 20,75 };
	walls[15].collider.box.extents = { .5,.5 };
	walls[15].sprite.handle = walls[0].sprite.handle;

	walls[16].transform.position = { 350,55 };
	walls[16].transform.dimension = { 20,75 };
	walls[16].collider.box.extents = { .5,.5 };
	walls[16].sprite.handle = walls[0].sprite.handle;

	walls[17].transform.position = { 485,149 };
	walls[17].transform.dimension = { 20,75 };
	walls[17].collider.box.extents = { .5,.5 };
	walls[17].sprite.handle = walls[0].sprite.handle;

	walls[18].transform.position = { 615,149 };
	walls[18].transform.dimension = { 20,75 };
	walls[18].collider.box.extents = { .5,.5 };
	walls[18].sprite.handle = walls[0].sprite.handle;

	Ball ball;
//	ball.transform.position = { 400,300 };
//	ball.sprite.handle = sfw::loadTextureMap("../resources/Gungeon.jpg");
//	ball.transform.dimension = { 32,32 };
//	ball.collider.box.extents = { .5,.5 };
//	ball.rigidbody.velocity = { 200,0 };
//	ball.rigidbody.drag = 0;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		//player.controller.poll(player.rigidbody, player.transform);
		player.update(sfw::getDeltaTime());
		player.draw();
		//player.rigidbody.integrate(player.transform, dt);
		//ball.rigidbody.integrate(ball.transform, dt);


		//player.sprite.draw(player.transform);
		//ball.sprite.draw(ball.transform);
		for (int i = 0; i < 29; ++i)
			walls[i].sprite.draw(walls[i].transform);


		for (int i = 0; i < 29; ++i)
		{
			//drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), CYAN);
			doCollision(player, walls[i]);
			doCollision(ball, walls[i]);
		}

		doCollision(player, ball);

		//drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		//for (int i = 0; i < 2; ++i)
			//drawAABB(walls[i].collider.getGlobalBox(walls[i].transform), RED);
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