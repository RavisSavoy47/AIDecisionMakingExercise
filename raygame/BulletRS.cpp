#include "BulletRS.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "GameManager.h"
#include "Agent1.h"

BulletRS::BulletRS(float maxSpeed, Actor* owner, const char* name = "Bullet") : Actor::Actor(0, 0, name)
{
	//Sets the scale
	getTransform()->setScale({ 50,50 });
	//Gets the actors owner
	getTransform()->setWorldPostion(owner->getTransform()->getWorldPosition());

	CircleCollider* circleCollider = new CircleCollider({ 30, this });
	this->setCollider(circleCollider);

	m_owner = owner;
	m_maxSpeed = maxSpeed;
}

void BulletRS::start()
{
	Actor::start();

	/// <summary>
	/// Gives the bullet asseces to the move component and a sprite component
	/// </summary>
	m_moveComp = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_spriteComp = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bullet.png")));

	/// <summary>
	/// Sets the the movement
	/// </summary>
	MathLibrary::Vector2 moveDirection = (GameManager::getInstance()->getAgent1()->getTransform()->getWorldPosition() -  m_owner->getTransform()->getWorldPosition()).getNormalized();
	m_moveComp->setVelocity(moveDirection * m_maxSpeed);


}

void BulletRS::update(float deltaTime)
{
	Actor::update(deltaTime);
	/// <summary>
	/// destorys the bullet after a certain time
	/// </summary>
	m_timer += deltaTime;
	if (m_timer >= 5.0f)
		Engine::destroy(this);
}

void BulletRS::onCollision(Actor* actor)
{
	if (getName() == "Agent1")
	{
		GameManager::getInstance()->getAgent1()->takeDamage();
		//destroy this actor
		Engine::destroy(this);
	}
}
