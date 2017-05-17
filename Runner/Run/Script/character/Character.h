#pragma once

/**
* @file Character.h
* @brief キャラクター用基礎クラス
* @author 松尾裕也
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

	//!状態の切替
	void changeState(CHARACTER_STATE _next);
	
	bool isDead()const;
	bool isGround()const;
protected:
	Character(const Transform _transform, GSuint _modelID);

protected:
	//状態を登録
	void registerState(CHARACTER_STATE _stateKey, CharacterStateManager::ICharacterStatePtr _state);
	//自身を死亡させる
	void killSelf();
protected:
	//!
	Transform m_transform;
	//!アニメーション用
	Animator m_animator;
private:
	//!状態管理
	CharacterStateManager m_stateManager;

	//!死亡か？
	bool m_isDead;
	//!地面についているか？
	bool m_isGround;
};