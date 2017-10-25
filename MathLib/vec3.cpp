#include "vec3.h"
#include <cmath>
#include <cfloat>


vec3 operator+=(vec3 &lhs, const vec3 &rhs) {
	lhs = lhs + rhs;

	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs) {
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON) {
		return true;
	}
	return false;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs){
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z) < FLT_EPSILON) {
		return false;
	}
	return true;
}

vec3 operator+(const vec3 &lhs, const vec3 &rhs) {
	vec3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.x + rhs.x;
	result.z = lhs.x + rhs.x;

	return result;

	// rewrite?
	for (int i = 0; i < 3; ++i) {
		result.v[i] = lhs.v[i] + rhs.v[i];
	}
}

vec3 operator-(const vec3 &lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.x - rhs.x;
	result.z = lhs.x - rhs.x;

	for (int i = 0; i < 3; ++i) {
		result.v[i] = lhs.v[i] - rhs.v[i];
	}
	return result;
}

vec3 operator*(const vec3 &lhs, const float rhs)
{
	vec3 result;
	result.x = lhs.x * rhs;
	result.y = lhs.x * rhs;
	result.z = lhs.x * rhs;

	for (int i = 0; i < 3; ++i) {
		result.v[i] = lhs.v[i] - rhs;
	}
	return result;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs * rhs.y;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.y;

	for (int i = 0; i < 3; ++i) {
		result.v[i] = lhs - rhs.v[i];
	}
	return result;
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	return vec3();
}

vec3 operator*(const vec3 & lhs, const vec3 & rhs)
{
	return vec3();
}

vec3 cross(const vec3 &a, const vec3 &b) {
	return vec3{ a.y*b.z - a.z*b.y,
				 a.z*b.x - a.x*b.z,
				 a.x*b.y - a.y*b.x };
}

float dot(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}
