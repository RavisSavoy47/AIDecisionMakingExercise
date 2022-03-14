#pragma once
#include "Component.h"
class ShootingComponent :
	public Component
{
public:
	ShootingComponent(Actor* target, float cooldown);
	~ShootingComponent() {};

	void update(float deltaTime) override;
	
private:
	Actor* m_target;
	float m_timer; 
	float m_cooldown;
};

