#pragma once
#include "Component.h"

enum State
{
	SEEKBALL,
	ATTACK,
	DEFEND,
	GOAL,
};

class SeekBehavior;

class StateMachineRSComponent :
	public Component
{

public:
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrrentState(State state) { m_currentState = state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBehavior* m_seekBehavior;
	float m_seekForce;
	float m_seekRange = 300;
	Actor* m_ballPosition;
	Actor* m_goalPosition;
};

