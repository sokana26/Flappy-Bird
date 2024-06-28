#pragma once
#include "SpriteEntity.h"
class Pipe : public SpriteEntity
{
public:
	Pipe(const std::string& file_path, const sf::Vector2f& position, float rotation, int priority);
};

