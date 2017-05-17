#pragma once
/**
* @file CharacterState.h
* @brief キャラクタ用状態
* @author 松尾裕也
* @date 2017/5/17
*/

#include "../state/CHARACTER_STATE.h"
#include "ICharacterState.h"
class Character;
template<typename T>
class CharacterState:public ICharacterState
{
protected:
	CharacterState(T* _character)
		:m_character(_character)
	{
	}

	virtual void setCharacter(Character * _chara) override
	{
		m_character = static_cast<T*>(_chara);
	}
	virtual Character * getCharacter() const override
	{
		return static_cast<Character*>(m_character);
	}

	void changeState(CHARACTER_STATE _next)
	{
		m_character->changeState(_next);
	}

private:
	//行動
	virtual void action(float _deltaTime) = 0;
	//クローンを作成
	virtual ICharacterState * clone() const = 0;

private:
	T* m_character;
};
