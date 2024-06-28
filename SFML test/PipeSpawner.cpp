#include "PipeSpawner.h"
#include "Game.h"
#include <random>

PipeSpawner::PipeSpawner(Game& game_ref)
	: Entity({}, {}, {})
	, IManager(game_ref)
{
}

float PipeSpawner::get_random_y_position()
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> y{ 150, 400 };

	return y(mt);
}

void PipeSpawner::update(sf::Time delta_time)
{
	Entity::update(delta_time);

	time_passed_ += delta_time.asSeconds();
	if (time_passed_ >= spawn_time_)
	{
		time_passed_ -= spawn_time_;

		game_.spawn_pipe({parameters::width, -get_random_y_position()});
	}
}
