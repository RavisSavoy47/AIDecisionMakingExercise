#include "StateMachineRSComponent.h"
#include "Actor.h"
#include "SeekBehavior.h"
#include "GameManager.h"
#include "Transform2D.h"

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

	//gets the agent1 position
	MathLibrary::Vector2 targetPos = m_seekBehavior->getTarget()->getTransform()->getWorldPosition();

	//gets the ball position as a vector
	MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition();
	m_ballPosition->getTransform()->setWorldPostion(ballPosition);

	//gets the left goal position as avector
	MathLibrary::Vector2 goalPosition = GameManager::getInstance()->getBallPosition();
	m_goalPosition->getTransform()->setWorldPostion(goalPosition);

	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();
	float distanceFromBall = (ballPosition - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	bool ballInRange = distanceFromBall <= m_seekRange;

	switch (m_currentState)
	{
	case SEEKBALL:
		m_seekBehavior->setForce(m_seekForce);

		if (ballInRange)
			setCurrrentState(GOAL);

		break;
	case ATTACK:
		m_seekBehavior->setForce(m_seekForce);

		if (targetInRange)
			setCurrrentState(DEFEND);

		break;
	case DEFEND:
		m_seekBehavior->setForce(m_seekForce);

		if (!targetInRange)
			setCurrrentState(SEEKBALL);
		break;
	case GOAL:
		m_seekBehavior->setForce(m_seekForce);
		m_seekBehavior->setTarget(m_goalPosition);

		if (!targetInRange)
			setCurrrentState(SEEKBALL);
		break;
	}
}
