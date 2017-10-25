#include "Transform.h"
#include "sfwdraw.h"
Transform::Transform()
{
	position = vec2{ 0,0 };
	dimension = vec2{ 0,0 };
	angle = 0;
	e_Parent = nullptr;
}
mat3 Transform::getLocalTransform() const
{
	return translate(position) * scale(dimension) * rotate(angle) ;
}

mat3 Transform::getGlobalTransform() const
{
	if (e_Parent != nullptr)
	{
		return e_Parent->getGlobalTransform() * getLocalTransform();
	}
	else
	{
		getLocalTransform();
	}
}

void DrawMatrix(const mat3 & t, float drawing_Scale)
{
		mat3 dummy = t;
		vec2 pos = dummy[2].xy;
		vec2 ri = pos;
		vec2 riDir = dummy[0].xy * drawing_Scale;
		ri += riDir;
		vec2 result = ri;

		//vec2 up_ep = (pos + (dummy[1].xy * drawing_Scale));
		vec2 up = pos;
		vec2 upDir = dummy[1].xy * drawing_Scale;
		up += upDir;
		vec2 UpResult = up;
	
		sfw::drawLine(pos.x, pos.y, result.x, result.y, RED);
		sfw::drawLine(pos.x, pos.y, UpResult.x, UpResult.y, GREEN);
	
		sfw::drawCircle(pos.x, pos.y, drawing_Scale / 4);
}
