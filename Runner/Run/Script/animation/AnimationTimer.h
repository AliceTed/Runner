#pragma once
#ifndef _ANIMATIONTIMER_H_
#define _ANIMATIONTIMER_H_
#include <gslib.h>
/*
AnimationTimer

0‚©‚ç”CˆÓ‚Ì”’l‚É‘‚¦‚Ä‚¢‚­
speed‚Å‘¬‚³w’è
*/
struct AnimationTimer
{
	float current;
	float end;
	float speed;
	AnimationTimer(float _end, float _speed = 1.0f);
	void reset();
	const bool isEnd()const;
	void update(float deltaTime);
};
#endif