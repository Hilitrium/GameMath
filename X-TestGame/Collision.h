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