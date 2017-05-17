#include "AnimationLerp.h"

AnimationLerp::AnimationLerp(GSuint _modelID)
	:m_modelID(_modelID),
	m_timer(20.0f)
{
}

AnimationLerp::~AnimationLerp()
{
}

void AnimationLerp::begin(GSuint _beginNo, float _begin_time, GSuint _endNo, float _end_time)
{
	m_beginNo = _beginNo;
	m_begin_time = _begin_time;
	m_endNo = _endNo;
	m_end_time = _end_time;

	m_timer.reset();
}

void AnimationLerp::update(float deltaTime)
{
	m_timer.update(deltaTime);
}

void AnimationLerp::calulate(GSmatrix4 * _out)
{
	gsCalculateAnimationLerp
	(
		m_modelID, m_beginNo, m_begin_time,
		m_modelID, m_endNo, m_end_time, m_timer.current / m_timer.end,
		_out
	);
}

const bool AnimationLerp::isEnd() const
{
	return m_timer.isEnd();
}
