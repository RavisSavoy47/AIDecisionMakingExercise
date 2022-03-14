#include "Agent2.h"
#include "SpriteComponent.h"
#include "SeekBehavior.h"
#include "GameManager.h"
#include "Goal.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	////Creates a new seekBehavior and seeks the ballPosition actor
	SeekBehavior* seekBehavior = new SeekBehavior(GameManager::getInstance()->getLeftGoal(), 200);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);

	Character::start();
}

void Agent2::update(float deltaTime)
{

	Character::update(deltaTime);

}

void Agent2::onDeath()
{
	Character::onDeath();

}