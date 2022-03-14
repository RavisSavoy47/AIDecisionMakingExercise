#include "AgentOneStateComponent.h"
#include "Actor.h"
#include "SeekBehavior.h"
#include "Transform2D.h"
#include "GameManager.h"
#include "Agent2.h"
#include "Agent1.h"
#include "Goal.h"

AgentOneStateComponent::AgentOneStateComponent()
	: Component()
{
	m_seekComponent = nullptr;
	m_seekForce = 0;
	m_targetActor = nullptr;
}

void AgentOneStateComponent::start()
{
	m_targetActor = new Actor(0, 0, "Target");
	m_seekComponent = getOwner()->getComponent<SeekBehavior>();
	m_seekForce = m_seekComponent->getForce();
	m_currentState = SEEKING_BALL;
	Component::start();
}

void AgentOneStateComponent::update(float deltaTime)
{
	MathLibrary::Vector2 ballPosition;
	MathLibrary::Vector2 goalPosition;
	MathLibrary::Vector2 enemyPosition;

	switch (m_currentState) {
	case SEEKING_BALL:
		ballPosition = GameManager::getInstance()->getBall()->getTransform()->getWorldPosition();
		m_targetActor->getTransform()->setWorldPostion(ballPosition);
		m_seekComponent->setTarget(m_targetActor);

		if (GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEKING_GOAL;
		else if (GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = SEEKING_ENEMY;
		break;
	case SEEKING_GOAL:
		goalPosition = GameManager::getInstance()->getRightGoal()->getTransform()->getWorldPosition();
		m_targetActor->getTransform()->setWorldPostion(goalPosition);
		m_seekComponent->setTarget(m_targetActor);

		if (GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEKING_BALL;
		break;
	case SEEKING_ENEMY:
		enemyPosition = GameManager::getInstance()->getAgent2()->getTransform()->getWorldPosition();
		m_targetActor->getTransform()->setWorldPostion(enemyPosition);
		m_seekComponent->setTarget(m_targetActor);

		if (!GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = SEEKING_BALL;
		break;
	}
}

