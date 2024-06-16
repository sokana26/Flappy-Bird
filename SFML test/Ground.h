#pragma once
#include "SpriteEntity.h"

class Ground : public SpriteEntity
{
public:
	Ground(const std::string& str, const sf::Vector2f& p, float r);

private:
	void update(sf::Time delta_time) override;
	float distance_passed{ 0 };
	float reset_point{ 500 };
};