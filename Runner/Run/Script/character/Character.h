#pragma once

/**
* @file Character.h
* @brief キャラクター用基礎クラス
* @author 松尾裕也
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
	//自身を死亡させる
	void killSelf();
protected:
	//!
	Transform m_transform;
private:
	//!死亡か？
	bool m_isDead;

};