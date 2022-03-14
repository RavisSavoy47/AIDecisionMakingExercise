#pragma once
#include "Character.h"

class Agent1 :
    public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health);

    virtual void onCollision(Actor* actor) override; //Called on collision with another actor
    virtual void start() override; //Called when this actor is added to a scene
    virtual void update(float deltaTime) override; //Called every frame
    virtual void onDeath(); //Called when this actor dies
    virtual void onDamageRecieved() {};
};

