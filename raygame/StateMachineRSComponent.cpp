#include "StateMachineRSComponent.h"
#include "Actor.h"
#include "SeekBehavior.h"
#include "Transform2D.h"
#include "GameManager.h"
#include "Goal.h"
#include "Agent1.h"

void StateMachineRSComponent::start()
{
	Component::start();

	m_seekBehavior = getOwner()->getComponent<SeekBehavior>();
	m_seekForce = m_seekBehavior->getForce();
	m_currentState = SEEKBALL;
}

void StateMachineRSComponent::update(float deltaTime)
{
	Component::update(deltaTime);
	//Saves the ball's position in a vector2
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBall()->getTransform()->getWorldPosition();
	//gets the left goal position as a vector
	MathLibrary::Vector2 goalPosition = GameManager::getInstance()->getLeftGoal()->getTransform()->getWorldPosition();
	//gets the agent1 position
	MathLibrary::Vector2 targetPos = GameManager::getInstance()->getAgent1()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	float distanceFromBall = (ballPosition - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	bool ballInRange = distanceFromBall <= m_seekRange;

	switch (m_currentState)
	{
	case SEEKBALL:
		m_seekBehavior->setForce(m_seekForce);
		m_seekBehavior->setTarget(GameManager::getInstance()->getBall());
		if (!ballInRange)
			setCurrrentState(GOAL);
		if (targetInRange)
			setCurrrentState(ATTACK);
		break;
	case ATTACK:
		m_seekBehavior->setForce(m_seekForce);
		m_seekBehavior->setTarget(GameManager::getInstance()->getAgent1());

		if (!targetInRange)
			setCurrrentState(SEEKBALL);

		break;
	case GOAL:
		m_seekBehavior->setForce(m_seekForce);
		m_seekBehavior->setTarget(GameManager::getInstance()->getLeftGoal());

		if (ballInRange)
			setCurrrentState(SEEKBALL);
		if (targetInRange)
			setCurrrentState(ATTACK);
		break;
	}
}
