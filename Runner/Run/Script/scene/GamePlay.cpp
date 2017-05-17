#include "GamePlay.h"
#include "../device/Input.h"
GamePlay::GamePlay()
{
}

void GamePlay::initialize()
{
}

void GamePlay::update(float deltaTime)
{
}

void GamePlay::draw(IRenderer * _renderer)
{
}

void GamePlay::finish()
{
}

const SceneMode GamePlay::next() const
{
	return SceneMode::GAMEPLAY;
}

const bool GamePlay::isEnd() const
{
	return  false;
}

const bool GamePlay::isExit() const
{
	return false;
}


