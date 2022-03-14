#include "Bullet.h"
#include "MoveComponent.h"
#include "Agent2.h"
#include "Transform2D.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

Bullet::Bullet(float x, float y, const char* name, float maxForce, float maxSpeed, Character* target)
 : Agent(x, y, name, maxForce, maxSpeed) {
	m_moveComponent = nullptr;
	m_targetPos = target->getTransform()->getWorldPosition();
	m_originPos = { x, y };
}

void Bullet::start()
{
	setCollider(new CircleCollider(20, this));
	SpriteComponent* spriteComponent = new SpriteComponent("Images/bullet.png");
	addComponent(spriteComponent);
	getTransform()->scale({ 50, 50 });
	m_moveComponent = new MoveComponent();
	addComponent(m_moveComponent);

	Agent::start();
}

void Bullet::update(float deltaTime)
{
	MathLibrary::Vector2 direction =
		(m_targetPos - m_originPos).getNormalized() * 500;

	m_moveComponent->setVelocity(direction);

	Agent::update(deltaTime);
}

void Bullet::onCollision(Actor* actor)
{
	Agent2* agent = dynamic_cast<Agent2*>(actor);
	if (agent)
		agent->takeDamage();
}
