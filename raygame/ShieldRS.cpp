#include "ShieldRS.h"
#include "Transform2D.h"
#include "Engine.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

ShieldRS::ShieldRS(Actor* owner, const char* name)
{
	m_owner = owner;
	getTransform()->setScale({ 150,150 });
	CircleCollider* circleCollider = new CircleCollider({ 75, this });
	this->setCollider(circleCollider);
	setName(name);
}

void ShieldRS::start()
{
	Actor::start();
	addComponent(new SpriteComponent("Images/bubble.png"));
	//Gets The Owner Starting Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
}

void ShieldRS::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Fallows The Owner Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());

	//Rotates 
	m_timer += deltaTime;
	getTransform()->setRotation(-m_timer);
}

/// <summary>
/// If the actor collides with an enemy
/// </summary>
/// <param name="actor"></param>
void ShieldRS::onCollision(Actor* actor)
{
	//if the actor is named "enemyBullet". . .
	if (actor->getName() == "Bullet")
	{
		//destroy the actor
		Engine::destroy(actor);
		//destroy this actor
		Engine::destroy(this);
	}
}

