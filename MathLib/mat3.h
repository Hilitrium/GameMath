#pragma once

#include "vec3.h"

union mat3
{
	vec3  c[3];
	float m[9];
	float mm[3][3]; // [col(y)][row(x)]


	vec3 &operator[](size_t idx) { return c[idx]; }
	const vec3 &operator[](size_t idx) const { return c[idx]; }

	static mat3 identity()
	{
		return mat3{ 1,0,0,
			0,1,0,
			0,0,1 };
	}

	static mat3 zero()
	{
		return mat3{ 0,0,0,
			0,0,0,
			0,0,0 };
	}
};

// A[2][1]

bool operator==(const mat3 &A, const mat3 &B);


mat3 operator+(const mat3 &A, const mat3 &B); // not really used 
mat3 operator-(const mat3 &A, const mat3 &B); // not really used 

											  // I(T) == I
mat3 transpose(const mat3 &A); // flip the rows and columns!

mat3 operator*(const mat3 &A, const mat3 &B); 
vec3 operator*(const mat3 &A, const vec3 &V); 

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 translate(const vec2 &t);

mat3 scale(const vec2 &s);

mat3 rotate(float deg);