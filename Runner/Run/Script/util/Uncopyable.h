#pragma once
/**
* @file Uncopyable.h
* @brief �R�s�[�֎~�p�e�N���X
* @author �����T��
* @date 2016/1/19
*/
class Uncopyable
{
public:
	Uncopyable() {}
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;
};
