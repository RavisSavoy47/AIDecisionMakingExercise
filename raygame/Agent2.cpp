#include "Agent2.h"
#include "SpriteComponent.h"
#include "SteeringComponent.h"
#include "SeekBehavior.h"
#include "GameManager.h"
#include "Goal.h"
#include "Transform2D.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

MathLibrary::Vector2 Agent2::getBallPosition()
{
	//Saves the ball's position in a vector2
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition();
	m_ballPosition->getTransform()->setWorldPostion(ballPosition);

	return ballPosition;
}

void Agent2::start()
{
	Character::start(); 
	//Saves the ball's position in a vector2
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition();
	//Initializes the ballPosition actor to be at the ball's position
	m_ballPosition = new Actor(ballPosition.x, ballPosition.y, "BallPositionActor");
	//add steering behaviours here
	SeekBehavior* seekBehavior = new SeekBehavior(m_ballPosition, 500);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

}

void Agent2::onDeath()
{
	Character::onDeath();

}