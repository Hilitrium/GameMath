#include"vec2.h"
#include"mathutils.h"
//#include<climits>
#include<cmath>
#include<cfloat>

vec2 operator+(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	//return result;

	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}


//vec2 operator-(const vec2 &lhs, const vec2 &rhs) {
//	vec2 result;
//	result.x = lhs.x - rhs.x;
//	result.y = lhs.y - rhs.y;
//
//	return result;
//
//	//return{ lhs.x + rhs.x, lhs.y + rhs.y };
//}

vec2 &operator*(const vec2 & lhs,  float rhs)
{
	vec2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;

	return result;

}

vec2 & operator*( float lhs, const vec2 & rhs)
{
	vec2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

vec2 operator/(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.x / rhs.x;

	return result;
}

vec2 & operator-(const vec2 & lhs, const vec2 & rhs)
{
	vec2 result;
		result.x = lhs.x - rhs.x;
		result.y = lhs.y - rhs.y;
	
		return result;
	
		//return{ lhs.x + rhs.x, lhs.y + rhs.y };
}

bool operator==(const vec2 &lhs, const vec2 &rhs) {
	//return lhs.x == rhs.x && lhs.y == rhs.y;
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON) {
		return true;
	}
	return false;
}

bool operator!=(const vec2 &lhs, const vec2 &rhs) {
	//return lhs.x != rhs.x && lhs.y != rhs.y
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON) {
		return false;
	}
	return true;
}

float mag(const vec2 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;

	return sqrt(aSqr + bSqr);
}

vec2 norm(const vec2 & v)
{
	vec2 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}

vec2 & normalize(vec2 & v)
{
	v = norm(v);

	return v;
}

float dot(const vec2 & a, const vec2 & b)
{
	return a.x * b.x + a.y * b.y;
}

float dist(const vec2 & a, const vec2 & b)
{
	return mag(b - a);
}

vec2 perp(const vec2 & v)
{
	return vec2{ v.y, -v.x };
}

vec2 lerp(const vec2 & s, const vec2 & e, float a)
{
	return s + a * (e - s);
}

vec2 min(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = fmin(a.x, b.x);
	temp.y = fmin(a.y, b.y);

	return temp;
}

vec2 max(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = fmax(a.x, b.x);
	temp.y = fmax(a.y, b.y);

	return temp;
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	lhs = lhs + rhs;

	return lhs;
}

vec2 &operator-=(vec2 &lhs, const vec2 &rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	lhs = lhs - rhs;

	return lhs;
}

vec2 &operator*=(vec2 &lhs, const float rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;

	//lhs = lhs * rhs;

	return lhs;
}

vec2 &operator/=(vec2 &lhs, const float rhs) {
	lhs.x /= rhs;
	lhs.y /= rhs;

	//lhs = lhs * rhs;

	return lhs;
}

//vec2 operator && (const vec2 &lhs, const vec2 &rhs) {
//	lhs.x && rhs.x;
//	lhs.y && rhs.y;
//
//	
//}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}
