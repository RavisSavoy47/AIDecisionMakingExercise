#pragma once
#include "Agent.h"
class Character;
class MoveComponent;
class Bullet :
	public Agent
{
public:
	Bullet(float x, float y, const char* name, float maxForce, float maxSpeed, Character* target);
	~Bullet() {};

	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* actor) override;

private:
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_targetPos;
	MathLibrary::Vector2 m_originPos;
};

