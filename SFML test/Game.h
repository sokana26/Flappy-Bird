#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"

namespace parameters
{
	constexpr int width = 405;
	constexpr int height = 720;
	constexpr float speed = 100;
	constexpr int ground_level = 620;
}
class Entity;
class Pipe;

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
	std::shared_ptr<sf::RenderWindow> window_;
	std::shared_ptr<Bird> bird;
	std::vector<std::shared_ptr<Entity>> entity_list_;
	std::vector<std::shared_ptr<Entity>> entities_to_create_;
	
};