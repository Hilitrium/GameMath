#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class Player {
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
	void update(float dt);
	void draw();
};

class Ball {
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};

class Wall{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

bool doCollision(Player &player, const Wall &wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(Player &player, Ball &wall);