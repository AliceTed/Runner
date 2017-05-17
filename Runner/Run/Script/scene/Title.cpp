#include "Title.h"
Title::Title()
{
}
void Title::initialize()
{
}

void Title::update(float deltaTime)
{
}

void Title::draw(IRenderer * renderer)
{
}

void Title::finish()
{
}

const SceneMode Title::next() const
{
	return SceneMode::GAMEPLAY;
}

const bool Title::isEnd() const
{
	return false;
}

const bool Title::isExit() const
{
	return false;
}
