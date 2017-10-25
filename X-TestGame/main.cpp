
#include "sfwdraw.h"
#include "Transform.h"
int main() 
{
	sfw::initContext(800,800);

	Transform myTrans;
	myTrans.position = vec2{ 400,300 };
	myTrans.dimension = vec2{ 1,1 };
	myTrans.angle = 0;
	

	while (sfw::stepContext())
	{
		myTrans.angle += sfw::getDeltaTime() * 20;
		DrawMatrix(myTrans.getGlobalTransform(), 30);
	}

	sfw::termContext();
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