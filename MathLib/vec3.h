#pragma once

#include "vec2.h"

union vec3 {
	// access by array
	float v[3];

	// access by individual component
	struct { float x, y, z; };
	
	// access to vec3 by index
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;

	// access as vec2
	vec2 xy;
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator+=(const vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 & lhs, const vec3 &rhs);
bool operator!=(const vec3 & lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, const float rhs);
vec3 operator*(const float lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, const vec3 &rhs);
vec3 cross(const vec3 &a, const vec3 &b);
float dot(const vec3 &lhs, const vec3 &rhs);