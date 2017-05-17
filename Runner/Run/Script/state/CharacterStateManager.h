#pragma once
/**
* @file CharacterStateManager.h
* @brief �L�����N�^�p��ԊǗ��p�N���X
* @author �����T��
* @date 2017/5/17
*/
#include <memory>
#include <unordered_map>
#include "../state/CHARACTER_STATE.h"
class ICharacterState;
class CharacterStateManager
{
public:
	//!�L�����N�^�C���^�[�t�F�C�X�|�C���^�^
	using ICharacterStatePtr = std::shared_ptr<ICharacterState>;
public:
	CharacterStateManager()=default;
	~CharacterStateManager()=default;
	CharacterStateManager(const CharacterStateManager & _other);

	void registerState(CHARACTER_STATE _stateKey, ICharacterStatePtr _state);
	void changeState(CHARACTER_STATE _next);
private:	
	//!��ԊǗ��R���e�i�^
	using StateContainer = std::unordered_map<CHARACTER_STATE, ICharacterStatePtr>;
	//!��ԃR���e�i
	StateContainer m_stateContainer;
	//!���݂̏��
	ICharacterState* m_currentState;
	//!���݂̏�ԃL�[
	CHARACTER_STATE m_currentStateKey;
};
