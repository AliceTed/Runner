#pragma once
#ifndef _ANIMATIONTIMER_H_
#define _ANIMATIONTIMER_H_
#include <gslib.h>
/*
AnimationTimer

0から任意の数値に増えていく
speedで速さ指定
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