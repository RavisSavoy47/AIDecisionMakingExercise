#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 oldPosition = getOwner()->getTransform()->getLocalPosition();
	//Add the new velocity to the old posiiton to get the new position
	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((oldPosition.x + (m_velocity.x * deltaTime)),
		(oldPosition.y + (m_velocity.y * deltaTime)));


	if (m_velocity.getMagnitude() > m_maxSpeed) {
		m_velocity = m_velocity.getNormalized() * m_maxSpeed;
	}

	//Update facing
	if (getVelocity().getMagnitude() > 0)
		getOwner()->getTransform()->setForward(getVelocity().getNormalized());

	if (getVelocity().getMagnitude() > getMaxSpeed())
		setVelocity(getVelocity().getNormalized() * getMaxSpeed());

	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
