#pragma once


#include "shapes.h"
#include "transform.h"
#include "Collision.h"

class Collider
{
public:
	AABB box;

	AABB getGlobalBox(const Transform &t) const
	{
		return t.getGlobalTransform() * box;
	}

	Collider(const AABB &a_box = { { 0,0 },{ 1,1 } }) : box(a_box)
	{

	}
};


class CircleCollider
{
public:
	circle circ;

	circle getGlobalCircle(const Transform &t) const
	{
		return t.getGlobalTransform() * circ;
	}

	CircleCollider(const circle &a_circ = { { 0,0 }, 1 }) : circ((a_circ))
	{

	}
};


Collision collides(const Transform &At, const Collider &Ac,
	const Transform &Bt, const Collider &Bc);

