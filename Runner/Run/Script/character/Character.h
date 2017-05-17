#pragma once

/**
* @file Character.h
* @brief キャラクター用基礎クラス
* @author 松尾裕也
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
	//自身を死亡させる
	void killSelf();
protected:
	//!
	Transform m_transform;
	//!アニメーション用
	Animator m_animator;
private:
	//!死亡か？
	bool m_isDead;
	//!地面についているか？
	bool m_isGround;
};