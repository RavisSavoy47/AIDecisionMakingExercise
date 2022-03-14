#pragma once
#include "Actor.h"

class ShieldRS :
	public Actor
{
public:
    ShieldRS(Actor* owner, const char* name);
    void start() override;
    void update(float deltaTime) override;
    void onCollision(Actor* actor) override;

private:
    Actor* m_owner;
    float m_timer;
};

