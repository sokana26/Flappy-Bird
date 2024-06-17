#include "Game.h"
#include  "Bird.h"
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
	window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(parameters::width, parameters::height), "Flappy Bird", sf::Style::Close);
	auto const background = std::make_shared<SpriteEntity>("Sprites/background.png", sf::Vector2f{ 0, 0 }, 0);
	auto const ground = std::make_shared<Ground>("Sprites/ground.png", sf::Vector2f{ 0, parameters::ground_level }, 0);
	bird = std::make_shared<Bird>("Sprites/bird123.png", sf::Vector2f{ 50, 300 }, 0);
	auto pipe_spawner = std::make_shared<PipeSpawner>(*this);
	entity_list_.push_back(pipe_spawner);
	entity_list_.push_back(background);
	entity_list_.push_back(ground);
	entity_list_.push_back(bird);
}

void Game::post_update()
{
	if (!entities_to_create_.empty())
	{
		entity_list_.insert(entity_list_.end(), entities_to_create_.begin(), entities_to_create_.end());
		entities_to_create_.clear();
	}
}

void Game::update()
{
	sf::Clock clock;
	while (window_->isOpen())
	{
		sf::Event evnt;
		while (window_->pollEvent(evnt))
		{
			process_events(evnt);
		}
		sf::Time elapsed = clock.restart();
		for (auto& entity : entity_list_) 
		{
			entity->update(elapsed);
		}
		post_update();
		draw();
	}
}

void Game::draw()
{
	window_->clear();
	for (auto entity : entity_list_) {
		entity->draw(*window_);
	}
	window_->display();
}

void Game::process_events(const sf::Event& evnt)
{
	switch (evnt.type)
	{
	case sf::Event::Closed:
		window_->close();
		break;
	case sf::Event::MouseButtonPressed:
		on_mouse_button_pressed();
		break;
	default:
		break;
	}
	for (const auto &entity : entity_list_) {
		entity->processEvents(evnt);
	}
}

void Game::on_mouse_button_pressed()
{
	bird->jump();
}

std::shared_ptr<Pipe> Game::spawn_pipe(const sf::Vector2f& initial_position)
{
	auto new_pipe = std::make_shared<Pipe>("Sprites/pipes.png", initial_position, 0);
	entities_to_create_.push_back(new_pipe);
	return new_pipe;
}

void Game::exit()
{

}
