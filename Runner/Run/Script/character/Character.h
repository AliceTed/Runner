#pragma once

/**
* @file Character.h
* @brief �L�����N�^�[�p��b�N���X
* @author �����T��
* @date 2017/5/17
*/
#include "../transform/Transform.h"
#include "../animation/Animator.h"
class Map;
class Character
{
public:
	Character(const Transform _transform, GSuint _modelID);
	~Character()=default;

	virtual void update(float _deltaTime) = 0;
	void draw(IRenderer * _renderer);

	bool isDead()const;
	bool isGround()const;
protected:
	//���g�����S������
	void killSelf();
protected:
	//!
	Transform m_transform;
	//!�A�j���[�V�����p
	Animator m_animator;
private:
	//!���S���H
	bool m_isDead;
	//!�n�ʂɂ��Ă��邩�H
	bool m_isGround;
};