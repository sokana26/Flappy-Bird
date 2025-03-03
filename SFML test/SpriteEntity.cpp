#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& file_path, sf::Vector2f position, float rotation, int priority)
	: Entity(position, rotation, priority)
	, texture_(std::filesystem::path(file_path))
	, sprite_(texture_)
{
	
}

void SpriteEntity::draw(sf::RenderTarget& texture)
{
	texture.draw(sprite_);
}

void SpriteEntity::update(sf::Time delta_time)
{
	Entity::update(delta_time);
	sprite_.setPosition(entity_position_);
	sprite_.setRotation(sf::Angle{ entity_rotation_ });
}