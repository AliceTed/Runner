#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
/*
animation���̊Ǘ�
�ԍ��ƃ^�C�}�[��
loop���ǂ����Ȃǂ̏�������
*/
struct Animation
{
	//�A�j���[�V�����A�X�P���g���A���b�V��������id�ŊǗ�
	//GSuint m_model_id;

	//�A�j���[�V�����ԍ�
	GSuint m_animation;
	bool m_isLoop;
	Animation(GSuint _animation, bool _isLoop = false);
	const float endTime(GSuint _modelID)const;
};
#endif