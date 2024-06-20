#include "Bird.h"

Bird::Bird(const std::string& file_path, sf::Vector2f position, float rotation) :SpriteEntity(file_path, position, rotation)
{
	sprite_.setScale(0.22, 0.22);
	sprite_.setTextureRect(bird_frame);
	entity_rotation_ = -10.f;
}

void Bird::update(sf::Time delta_time)
{
	SpriteEntity::update(delta_time);
	entity_velocity_.y += gravity_ * delta_time.asSeconds();
	entity_velocity_.y = entity_velocity_.y > max_down_speed_ ? max_down_speed_ : entity_velocity_.y;

	time_passed_ += delta_time.asSeconds();
	if (time_passed_ >= switch_frame_time_)
	{
		time_passed_ -= switch_frame_time_;
		left_coord_ += frame_width_;
		bird_frame.left = left_coord_ %= (frame_width_ * frame_number_);
		sprite_.setTextureRect(bird_frame);
	}
}

void Bird::jump()
{
	entity_velocity_.y = -550.f;
}