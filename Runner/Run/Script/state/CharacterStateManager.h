#pragma once
/**
* @file CharacterStateManager.h
* @brief キャラクタ用状態管理用クラス
* @author 松尾裕也
* @date 2017/5/17
*/
#include <memory>
#include <unordered_map>
#include "../state/CHARACTER_STATE.h"
class ICharacterState;
class CharacterStateManager
{
public:
	//!キャラクタインターフェイスポインタ型
	using ICharacterStatePtr = std::shared_ptr<ICharacterState>;
public:
	CharacterStateManager()=default;
	~CharacterStateManager()=default;
	CharacterStateManager(const CharacterStateManager & _other);

	void registerState(CHARACTER_STATE _stateKey, ICharacterStatePtr _state);
	void changeState(CHARACTER_STATE _next);
private:	
	//!状態管理コンテナ型
	using StateContainer = std::unordered_map<CHARACTER_STATE, ICharacterStatePtr>;
	//!状態コンテナ
	StateContainer m_stateContainer;
	//!現在の状態
	ICharacterState* m_currentState;
	//!現在の状態キー
	CHARACTER_STATE m_currentStateKey;
};
