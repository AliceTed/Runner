#pragma once
/**
* @file CastID.h
* @brief 各IDの変換
* @author 松尾裕也
* @date 2016/2/8
*/
class CastID
{
public:
	CastID()=default;
	~CastID()=default;

	/*スタティックキャスト*/
	template<class ID>
	static unsigned int idToUInt(ID _id);
};

template<class ID>
unsigned int CastID::idToUInt(ID _id)
{
	return static_cast<unsigned int>(_id);
}
