#pragma once
/**
* @file ICharacterState.h
* @brief �L�����N�^�p��ԃC���^�[�t�F�C�X
* @author �����T��
* @date 2017/5/17
*/
class Character;
class ICharacterState
{
public:
	virtual ~ICharacterState(){}
	//���݂̏�Ԃōs��
	virtual void action(float _deltaTime) = 0;
	//�L�����̐ݒ�
	virtual void setCharacter(Character* _chara) = 0;
	//�L�����̎擾
	virtual Character* getCharacter()const=0;
	//�N���[�����쐬
	virtual ICharacterState* clone()const = 0;
};