#include "Entity.h"

Entity::Entity(sf::Vector2f position, float rotation, int priority)
	: entity_position_(position)
	, entity_rotation_(rotation)
	, priority(priority)
{
}

void Entity::update(sf::Time delta_time)
{
	entity_position_ += entity_velocity_ * delta_time.asSeconds();
}