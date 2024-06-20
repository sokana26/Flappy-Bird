#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"

class Pipe;

namespace parameters
{
	constexpr int width = 405;
	constexpr int height = 720;

	constexpr int ground_level = 620;
	constexpr float ground_speed = 180;
}

class Game
{
public:
	Game() = default;

	void run();
	void init();
	void post_update();
	void update();
	void draw();
	void exit();
	void process_events(const sf::Event& evnt);
	void on_mouse_button_pressed();
	std::shared_ptr<Pipe> spawn_pipe(const sf::Vector2f& initial_position);

private:
	std::shared_ptr<sf::RenderWindow> _window;
	std::shared_ptr<Bird> _bird;
	std::vector<std::shared_ptr<Entity>> _entity_list;
	std::vector<std::shared_ptr<Entity>> _entities_to_create;
};