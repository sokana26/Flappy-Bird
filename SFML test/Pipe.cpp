#include "Pipe.h"
#include "Game.h"

Pipe::Pipe(const std::string& file_path, const sf::Vector2f& position, float rotation, int priority)
	: SpriteEntity(file_path, position, rotation, priority)
{
	entity_velocity_.x = -parameters::ground_speed;

	sprite_.setScale({1.5f, 1.5f});
}
