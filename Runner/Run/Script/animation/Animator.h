#pragma once

#include "Animation.h"
#include <memory>
#include <vector>
#include "../transform/Transform.h" 
#include "AnimationLerp.h"
class IRenderer;
class Animator
{
public:
	/*mesh,anim,skl共通のＩＤで管理*/
	Animator(GSuint _modelID);
	//endTimeが0ならアニメーションが終了するまでtimerをupdate
	void start(const Animation& _next, float _speed = 1.0f, float _endTime = 0.0f,bool _isLerp=true);
	void update(float deltaTime);
	const bool isEnd()const;
	const GSmatrix4& getSkelton(GSuint _index)const;

	const AnimationTimer& getTimer()const;
	void draw(IRenderer * _renderer,const Transform& _t);
private:
	void calculateAnimation();
private:
	AnimationTimer m_timer;
	GSuint m_modelID;
	Animation m_current;
	bool m_isLerp;
	AnimationLerp m_lerp;
	static const int LENGHT = 256;
	std::shared_ptr<GSmatrix4> m_matrix;
};