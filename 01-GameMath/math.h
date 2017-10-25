#pragma once

float sqr(float v) {
	return v * v;
}

float dbl(float v) {
	return v * 2;
}

float cube(float v) {
	return v * v * v;
}

float degToRad(float deg) {
	return deg * (3.141592654 / 180);
}

float radToDeg(float rad) {
	return rad*(180 / 3.141592654);
}

float quad(float x) {
	return (x * x) + (2 * x) - 7;
}

float lerp(float s, float e, float t) {
	return s + t * (e - s);
}

//float distance(float p1, float p2) {
	//(((p2 - p1) * (p2 - p1)) + ((p2 - p1)))
//}