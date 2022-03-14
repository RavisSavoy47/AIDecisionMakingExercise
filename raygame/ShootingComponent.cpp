#include "ShootingComponent.h"
#include  "Bullet.h"
#include "Transform2D.h"
#include "Engine.h"
#include "GameManager.h"
#include "Transform2D.h"

ShootingComponent::ShootingComponent(Actor* target, float cooldown)
{
	m_timer = 0;
	m_cooldown = cooldown;
	m_target = target;
} 

void ShootingComponent::update(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer > m_cooldown) {
		MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
		Bullet* bullet = new Bullet(ownerPos.x, ownerPos.y, "AgentOneBullet", 2000, 2000, GameManager::getInstance()->getAgent2());
		Engine::getCurrentScene()->addActor(bullet);

		m_timer = 0;
	}
}
