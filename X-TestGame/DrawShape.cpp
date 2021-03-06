#include "shapes.h"
#include "sfwdraw.h"
#include "vec2.h"
#include "DrawShape.h"

void drawCircle(const circle &C) {
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}



void DrawVecLine(const vec2 &a, const vec2 &b) {
	sfw::drawLine(a.x, a.y, b.x, b.y, BLUE);
}

void drawAABB(const AABB & box, int color) {
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	DrawVecLine(TR, TL);
	DrawVecLine(TL, BL);
	DrawVecLine(BL, BR);
	DrawVecLine(BR, TR);
}