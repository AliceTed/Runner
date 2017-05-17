#pragma once

/**
* @file Character.h
* @brief �L�����N�^�[�p��b�N���X
* @author �����T��
* @date 2017/5/17
*/

#include "../transform/Transform.h"
#include "../animation/Animator.h"
#include "../state/CHARACTER_STATE.h"
#include "../state/CharacterStateManager.h"
class Map;
class Character
{
public:	
	~Character()=default;

	virtual void update(float _deltaTime) = 0;
	void draw(IRenderer * _renderer);

	//!��Ԃ̐ؑ�
	void changeState(CHARACTER_STATE _next);
	
	bool isDead()const;
	bool isGround()const;
protected:
	Character(const Transform _transform, GSuint _modelID);

protected:
	//��Ԃ�o�^
	void registerState(CHARACTER_STATE _stateKey, CharacterStateManager::ICharacterStatePtr _state);
	//���g�����S������
	void killSelf();
protected:
	//!
	Transform m_transform;
	//!�A�j���[�V�����p
	Animator m_animator;
private:
	//!��ԊǗ�
	CharacterStateManager m_stateManager;

	//!���S���H
	bool m_isDead;
	//!�n�ʂɂ��Ă��邩�H
	bool m_isGround;
};