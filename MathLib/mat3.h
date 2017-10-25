#pragma once
#include"vec3.h"

union mat3 {
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	vec3 &operator[](size_t idx) { return c[idx]; } // column accessor
	const vec3 &operator[](size_t idx) const { return c[idx]; }
	

	static mat3 identity() {
		return mat3{ 1,0,0,
					 0,1,0,
					 0,0,1 };
	
	}// creates and returns an identity matrix.
};

bool operator==(const mat3 &A, const mat3 &B);


mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &V);

mat3 transpose(const mat3 &A);

//float dot(vec3 a, vec3 b);
//float cross(vec3 a, vec3 b);
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);
mat3 translate(const vec2 &t);
mat3 scale(const vec2 &s);
mat3 rotate(float deg);

/*
[1 0 x]
[0 1 y]
[0 0 1]

[0 3 6]
[1 4 7]
[2 5 8]

[(0,0) (0,1) (0,2)]
[(1,0) (1,1) (1,2)]
[(2,0) (2,1) (2,2)]

[c1 c2 c3]
*/