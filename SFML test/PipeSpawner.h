#pragma once
#include "Entity.h"
#include "IManager.h"

class PipeSpawner : public Entity, public IManager
{
public:
	PipeSpawner(Game& game_ref);

	void update(sf::Time delta_time) override;

	float time_passed_ = 0.f;
	float spawn_time_ = 3.f;
};

