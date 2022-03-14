#include "Agent1.h"
#include "SpriteComponent.h"
#include "SeekBehavior.h"
#include "Goal.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "AgentOneStateComponent.h"
#include "ShootingComponent.h"
#include "WanderBehavior.h"
#include "MoveComponent.h"
#include "Agent2.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
	m_slowTimer = 0;
	m_slowDuration = 3;
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
	Agent2* agent = dynamic_cast<Agent2*>(actor);
	if (agent) {
		m_slowingEnemy = true;
		m_slowTimer = 0;
		MoveComponent* moveComponent = agent->getComponent<MoveComponent>();
		moveComponent->setMaxSpeed(20);
	}
}

void Agent1::start()
{
	Character::start();
<<<<<<<<< Temporary merge branch 1
	SeekBehavior* comp = new SeekBehavior(GameManager::get, 200);

	Character::start(); //Calls the base character's start function
	////Creates a new seekBehavior and seeks the ballPosition actor
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
	m_slowTimer += deltaTime;

	if (m_slowTimer > m_slowDuration && m_slowingEnemy) {
		MoveComponent* moveComponent = GameManager::getInstance()->getAgent2()->getComponent<MoveComponent>();
		m_slowTimer = 0;
		m_slowingEnemy = false;
	}

	Character::update(deltaTime);
}

void Agent1::onDeath()
{
	Character::onDeath();

}
