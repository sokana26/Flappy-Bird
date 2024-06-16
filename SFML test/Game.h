#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"

namespace parameters
{
	constexpr int width = 405;
	constexpr int height = 720;
	constexpr float speed = 100;
}
class Entity;

class Game
{
public:
	Game() = default;

	void run();
	void init();
	void update();
	void draw();
	void exit();
	void process_events(const sf::Event& evnt);
	void on_mouse_button_pressed();

private:
	std::shared_ptr<sf::RenderWindow> window_;
	std::shared_ptr<Bird> bird;
	std::vector<std::shared_ptr<Entity>> entity_list_;
	
};