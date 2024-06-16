#include "Ground.h"
#include "Game.h"

Ground::Ground(const std::string& str, const sf::Vector2f& p, float r): SpriteEntity(str, p, r)
{
	entity_velocity_.x = -parameters::speed;
}

void Ground::update(sf::Time delta_time)
{
	SpriteEntity::update(delta_time);
	distance_passed -= delta_time.asSeconds() * entity_velocity_.x;
	if (distance_passed >= reset_point)
	{
		distance_passed -= reset_point;
		entity_position_.x = 0;
	}
}