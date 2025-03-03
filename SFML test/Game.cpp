#include "Game.h"
#include "Bird.h"
#include "Ground.h"
#include "Pipe.h"
#include "PipeSpawner.h"

void Game::run()
{
	init();
	update();
	exit();
}

void Game::init()
{
	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode({ parameters::width, parameters::height }), "Flappy Bird", sf::Style::Close);

	auto background = std::make_shared<SpriteEntity>("Sprites/background.png", sf::Vector2f{ 0, 0 }, 0, 1);
	_entity_list.push_back(background);

	_bird = std::make_shared<Bird>("Sprites/bird123.png", sf::Vector2f{ 50, 300 }, 0, 2);
	_entity_list.push_back(_bird);

	auto ground = std::make_shared<Ground>("Sprites/ground.png", sf::Vector2f{ 0, parameters::ground_level }, 0, 4);
	_entity_list.push_back(ground);

	auto pipe_spawner = std::make_shared<PipeSpawner>(*this);
	_entity_list.push_back(pipe_spawner);
}

void Game::update()
{
	sf::Clock clock;
	while (_window->isOpen())
	{
		while (const std::optional event = _window->pollEvent())
		{
			process_events(event);
		}
		sf::Time elapsed = clock.restart();
		for (auto& entity : _entity_list)
		{
			entity->update(elapsed);
		}
		draw();
		post_update();
	}
}

void Game::post_update()
{
	if (!_entities_to_create.empty())
	{
		_entity_list.insert(_entity_list.begin() + 2, _entities_to_create.begin(), _entities_to_create.end());
		_entities_to_create.clear();
	}
}

void Game::draw()
{
	_window->clear();

	for (auto entity : _entity_list)
	{
		entity->draw(*_window);
	}

	_window->display();
}

void Game::process_events(const std::optional<sf::Event>& event)
{

	if (event->is<sf::Event::Closed>())
		_window->close();

	else if (event->is<sf::Event::MouseButtonPressed>())
		on_mouse_button_pressed();

	for (const auto& entity : _entity_list)
	{
		entity->processEvents(event);
	}
}

void Game::on_mouse_button_pressed()
{
	_bird->jump();
}

std::shared_ptr<Pipe> Game::spawn_pipe(const sf::Vector2f& initial_position)
{
	auto new_pipe = std::make_shared<Pipe>("Sprites/pipes.png", initial_position, 0, 2);
	_entities_to_create.push_back(new_pipe);

	return new_pipe;
}

void Game::exit()
{

}
