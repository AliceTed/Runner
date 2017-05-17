#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
/*
animation情報の管理
番号とタイマーと
loopかどうかなどの情報を持つ
*/
struct Animation
{
	//アニメーション、スケルトン、メッシュを共通idで管理
	//GSuint m_model_id;

	//アニメーション番号
	GSuint m_animation;
	bool m_isLoop;
	Animation(GSuint _animation, bool _isLoop = false);
	const float endTime(GSuint _modelID)const;
};
#endif