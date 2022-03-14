#include "Agent1.h"
#include "SpriteComponent.h"
#include "SeekBehavior.h"
#include "Goal.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "AgentOneStateComponent.h"
#include "ShootingComponent.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start(); //Calls the base character's start function

	//Creates a new seekBehavior and seeks the ballPosition actor
	SeekBehavior* seekBehavior = new SeekBehavior(nullptr, 200);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	//Component that handles the agent's game states
	AgentOneStateComponent* stateComponent = new AgentOneStateComponent();
	addComponent(stateComponent);
	
	ShootingComponent* shootingComponent = new ShootingComponent(GameManager::getInstance()->getAgent2(), 1);
	addComponent(shootingComponent);
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);
}

void Agent1::onDeath()
{
	Character::onDeath();

}
