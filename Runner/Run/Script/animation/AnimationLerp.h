#pragma once
#include <gslib.h>
#include "AnimationTimer.h"
class AnimationLerp
{
public:
	AnimationLerp(GSuint _modelID);
	~AnimationLerp();
	void begin(GSuint _beginNo,float _begin_time,GSuint _endNo,float _end_time);
	void update(float deltaTime);
	void calulate(GSmatrix4* _out);
	const bool isEnd()const;
private:
	GSuint m_modelID;

	GSuint m_beginNo;
	float m_begin_time;
	GSuint m_endNo;
	float m_end_time;

	AnimationTimer m_timer;
};