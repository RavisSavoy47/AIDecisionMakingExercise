#pragma once
#include "Character.h"

class BulletRS;
class ShieldRS;
class StateMachineRSComponent;
class Agent2 :
    public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health);

    // Inherited from the Character class
    virtual void onCollision(Actor* actor) override;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onDeath();
    virtual void onDamageRecieved() {};

private:
    float m_health = 3;
    StateMachineRSComponent* m_stateMachine;
    // Takes in a custom madde actor designed to be a bullet 
    BulletRS* m_bullet;
    ShieldRS* m_shield;
    //Meant to keep tabs on the time between bullets made 
    float m_timer = 0;
};


