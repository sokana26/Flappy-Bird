#include "Bird.h"

Bird::Bird(const std::string& file_path, sf::Vector2f position, float rotation):SpriteEntity(file_path, position, rotation)
{
	sprite_.setScale(0.2, 0.2);
	sprite_.setTextureRect(bird_frame);
}

void Bird::update(sf::Time delta_time)
{
	SpriteEntity::update(delta_time);
	entity_velocity_.y += gravity_ * delta_time.asSeconds();
	entity_velocity_.y = entity_velocity_.y > max_down_speed_ ? max_down_speed_ : entity_velocity_.y;

	if (bird_frame.left == 628)
		bird_frame.left = 0;
	else
		bird_frame.left += 314;

	sprite_.setTextureRect(bird_frame);
}

void Bird::jump()
{
	entity_velocity_.y = -550.f;
}