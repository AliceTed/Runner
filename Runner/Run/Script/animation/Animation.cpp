#include "Animation.h"

Animation::Animation(GSuint _animation, bool _isLoop)
{
	m_animation = _animation;
	m_isLoop = _isLoop;
}

const float Animation::endTime(GSuint _modelID) const
{
	return static_cast<float>(gsGetEndAnimationTime(_modelID, m_animation));
}