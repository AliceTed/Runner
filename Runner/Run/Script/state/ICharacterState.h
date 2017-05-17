#pragma once
/**
* @file ICharacterState.h
* @brief キャラクタ用状態インターフェイス
* @author 松尾裕也
* @date 2017/5/17
*/
class Character;
class ICharacterState
{
public:
	virtual ~ICharacterState(){}
	//現在の状態で行動
	virtual void action(float _deltaTime) = 0;
	//キャラの設定
	virtual void setCharacter(Character* _chara) = 0;
	//キャラの取得
	virtual Character* getCharacter()const=0;
	//クローンを作成
	virtual ICharacterState* clone()const = 0;
};