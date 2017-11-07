#pragma once
#include "mat3.h"
#include "vec2.h"

struct AABB {
	vec2 position;
	vec2 extents;

	vec2 min() const { return position - extents; }
	vec2 max() const { return position + extents; }
};

struct circle {
	vec2 position;
	float radius;
};

circle operator*(const mat3 &M, const circle &C);
AABB operator*(const mat3 &M, const AABB &B);

