#pragma once
#include "mat3.h"
#include "vec2.h"

class Transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	Transform();
	Transform *e_Parent;

	//Transform(vec2 a_pos = {0,0})

	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
	
};

void DrawMatrix(const mat3 &t, float drawing_Scale);
void DrawTexture(unsigned sprite, const mat3 &t);
//void DrawTexture(unsigned sprite, const mat3 &t);

//Transform::Transform() {
//	position = vec2{ 0,0 };
//	dimension = vec2{ 0,0 };
//	angle = 0;
//}
//
//mat3::Transform::getLocalTransform() const {
//	return scale(dimension) * rotate(angle) * translate(position);
//}
//
//void DrawMatrix(const mat3 &t, float drawing_scale) {
//	vec2 pos = t[2].xy;
//	vec2 right_ep = pos + t[0].xy * drawing_scale;
//	vec2 up_ep = pos + t[1].xy * drawing_scale;
//
//	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
//	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);
//
//	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
//}