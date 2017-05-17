#include "AnimationTimer.h"

AnimationTimer::AnimationTimer(float _end, float _speed)
{
	end = _end;
	current = 0.0f;
	speed = _speed;
}

void AnimationTimer::reset()
{
	current = 0.0f;
}

const bool AnimationTimer::isEnd() const
{
	return current >= end;
}

void AnimationTimer::update(float deltaTime)
{
	current = CLAMP(current + speed*deltaTime, 0.0f, end);
}
