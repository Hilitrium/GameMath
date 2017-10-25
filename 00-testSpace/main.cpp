#include<iostream>
#include"mathutils.h"
#include"vec2.h"

int main() {
	int val = min(1, 3);

	vec2 test;
	test.x = 5;
	test.y = 20;

	vec2 testB;
	testB.x = 5;
	testB.y = 20;

	vec2 result = test + testB;

	vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	bool eq = num == test;

	while (true) {}
}