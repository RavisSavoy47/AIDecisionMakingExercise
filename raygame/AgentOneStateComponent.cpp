#include "AgentOneStateComponent.h"
#include "Actor.h"
#include "SeekBehavior.h"
#include "Transform2D.h"
#include "GameManager.h"
#include "Agent2.h"
#include "Agent1.h"

AgentOneStateComponent::AgentOneStateComponent()
	: Component()
{
	m_seekComponent = nullptr;
	m_seekForce = 0;
	m_targetActor = nullptr;
}

void AgentOneStateComponent::start()
{
	m_seekComponent = getOwner()->getComponent<SeekBehavior>();
	m_seekForce = m_seekComponent->getForce();
	m_currentState = SEEKING_BALL;
	Component::start();
}

void AgentOneStateComponent::update(float deltaTime)
{
	switch (m_currentState) {
	case SEEKING_BALL:
		MathLibrary::Vector2 ballPosition = GameManager::getInstance()->getBallPosition();
		m_targetActor->getTransform()->setWorldPostion(ballPosition);
		m_seekComponent->setTarget(m_targetActor);

		if (GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEKING_GOAL;
		break;
	case SEEKING_GOAL:
		MathLibrary::Vector2 goalPosition = GameManager::getInstance()->getBallPosition();
		m_targetActor->getTransform()->setWorldPostion(goalPosition);
		m_seekComponent->setTarget(m_targetActor);

		if (!GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEKING_BALL;
	}
}

