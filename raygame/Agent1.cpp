#include "Agent1.h"
#include "SpriteComponent.h"
#include "SeekBehavior.h"
#include "Goal.h"
#include "GameManager.h"
#include "Transform2D.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
}

MathLibrary::Vector2 Agent1::getBallPosition()
{
	//Saves the ball's position in a vector2
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition();
	m_ballPosition->getTransform()->setWorldPostion(ballPosition);

	return ballPosition;
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
	if (dynamic_cast<Character*>(actor))
		for (int i = 0; i < 3; i++)
			takeDamage();
}

void Agent1::start()
{
	Character::start(); //Calls the base character's start function

	//Saves the ball's position in a vector2
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition(); 
	//Initializes the ballPosition actor to be at the ball's position
	m_ballPosition = new Actor(ballPosition.x, ballPosition.y, "BallPositionActor");

	//Creates a new seekBehavior and seeks the ballPosition actor
	SeekBehavior* seekBehavior = new SeekBehavior(m_ballPosition, 200);
	addComponent(seekBehavior);
	onAddComponent(seekBehavior);
}

void Agent1::update(float deltaTime)
{

	Character::update(deltaTime);
}

void Agent1::onDeath()
{
	Character::onDeath();

}
