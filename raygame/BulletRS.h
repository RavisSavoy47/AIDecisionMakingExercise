#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class BulletRS :
	public Actor
{
public:
    BulletRS(float maxSpeed, Actor* owner, const char* name);

    void start() override;
    void update(float deltaTime) override;
    void onCollision(Actor* actor) override;
private:
    MoveComponent* m_moveComp;
    SpriteComponent* m_spriteComp;

    float m_maxSpeed;
    Actor* m_owner;

    float m_timer;
};

