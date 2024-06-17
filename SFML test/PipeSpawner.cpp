#include "PipeSpawner.h"
#include "Game.h"

PipeSpawner::PipeSpawner(Game& game_ref)
	: Entity({}, {})
	, IManager(game_ref)
{
}

void PipeSpawner::update(sf::Time delta_time)
{
	Entity::update(delta_time);

	time_passed_ += delta_time.asSeconds();
	if (time_passed_ >= spawn_time_)
	{
		time_passed_ -= spawn_time_;

		game_.spawn_pipe({parameters::width, 0.f});
	}
}
