#pragma once
#include <memory>

class Game;

class IManager
{
protected:
	IManager(Game& game_ref);

	Game& game_;
};

