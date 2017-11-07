#include "shapes.h"
#include <cmath>


AABB operator*(const mat3 &M, const AABB &B) {

	AABB retval;

	vec2 TL = { B.position.x - B.extents.x, B.position.y + B.extents.y };
	vec2 TR = B.position + B.extents;
	vec2 BL = B.position - B.extents;
	vec2 BR = { TR.x, BL.y };

	TR = (M * vec3{ TR.x, TR.y, 1 }).xy;
	BL = (M * vec3{ BL.x, BL.y, 1 }).xy;
	TL = (M * vec3{ TL.x, TL.y, 1 }).xy;
	BR = (M * vec3{ BR.x, BR.y, 1 }).xy;

	vec2 MinCorner = min(TR, min(BL, min(TL, BR)));
	vec2 MaxCorner = max(TR, max(BL, max(TL, BR)));

	retval.position = (MaxCorner + MinCorner) / 2;
	retval.extents = (MaxCorner - MinCorner) / 2;

	return retval;
}

circle operator*(const mat3 & M, const circle & C) {
	circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;

	vec2 scale;
	scale.x = mag(M[0].xy);
	scale.y = mag(M[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}