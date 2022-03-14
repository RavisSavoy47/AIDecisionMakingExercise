#include "Agent2.h"
#include "SpriteComponent.h"
#include "SteeringComponent.h"
#include "SeekBehavior.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "StateMachineRSComponent.h"
#include "BulletRS.h"
#include "Actor.h"
#include "ShieldRS.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
	m_health = health;
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start(); 

	//add steering behaviours here
	SeekBehavior* seekBehavior = new SeekBehavior(GameManager::getInstance()->getBall(), 500);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);
	m_stateMachine = addComponent<StateMachineRSComponent>();
}

void Agent2::update(float deltaTime)
{

	Character::update(deltaTime);
	//Crats a new bullet and it's appointed to the bullet pointer
	m_bullet = new BulletRS(1000, GameManager::getInstance()->getAgent2(), getName());
	//Adds deta time to the current timer 
	m_timer += deltaTime;
	//If the timer is 8 seconds . . .
	if (m_timer > 1.00f)
	{
		//Add ther created actor to the to the current scene 
		Engine::getCurrentScene()->addActor(m_bullet);
		//Sets the timer to be zero again 
		m_timer = 0;
	}
	//other wise. . .
	else
		//delete whatever was asigned to m_bulllet
		delete m_bullet;

	m_shield = new ShieldRS(this, "Shield");

	if (getName() == "Bullet" && m_timer > 5.00f)
	{
		Engine::getCurrentScene()->addActor(m_shield);
		//Sets the timer to be zero again 
		m_timer = 0;
	}

}

void Agent2::onDeath()
{
	Character::onDeath();
}