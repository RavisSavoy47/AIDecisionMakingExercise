#pragma once
#include "Component.h"
#include <Vector2.h>
class SeekBehavior;

enum State {
	SEEKING_BALL,
	SEEKING_GOAL,
	SEEKING_ENEMY
};

class AgentOneStateComponent :
	public Component
{
public:
	AgentOneStateComponent();
	~AgentOneStateComponent() {}

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void start() override;
	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBehavior* m_seekComponent;
	float m_seekForce;
	Actor* m_targetActor;
};

