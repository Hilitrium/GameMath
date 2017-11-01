#pragma once
#include "mathutils.h"
#include "shapes.h"
#include "vec2.h"
#include <cmath>

struct Collision {
	float penetrationDepth;
	float handedness;
	vec2 axis;
};


Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);
Collision intersect_AABB(const AABB &A, const AABB &B);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity = 1.0f);

void dynamic_resolution(vec2 &Apos, vec2 &Avel, vec2&Bpos, vec2 &Bvel, const Collision &hit, float elasticity);