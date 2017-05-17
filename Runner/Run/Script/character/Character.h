#pragma once

/**
* @file Character.h
* @brief �L�����N�^�[�p��b�N���X
* @author �����T��
* @date 2017/5/17
*/
#include "../transform/Transform.h"
class Character
{
public:
	Character();
	~Character();

	virtual void update(float _deltaTime) = 0;

	bool isDead()const;
protected:
	//���g�����S������
	void killSelf();
protected:
	//!
	Transform m_transform;
private:
	//!���S���H
	bool m_isDead;

};