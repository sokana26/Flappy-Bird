#include "Pipe.h"
#include "Game.h"

Pipe::Pipe(const std::string& file_path, const sf::Vector2f& position, float rotation)
	: SpriteEntity(file_path, position, rotation)
{
	entity_velocity_.x = -parameters::speed;

	sprite_.setScale(0.2f, 0.2f);
}
