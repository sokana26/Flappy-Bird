#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& file_path, sf::Vector2f position, float rotation):Entity(position, rotation)
{
	texture_.loadFromFile(file_path);
	sprite_.setTexture(texture_);
}

void SpriteEntity::draw(sf::RenderTarget& texture)
{
	texture.draw(sprite_);
}

void SpriteEntity::update(sf::Time delta_time)
{
	Entity::update(delta_time);
	sprite_.setPosition(entity_position_);
	sprite_.setRotation(entity_rotation_);
}