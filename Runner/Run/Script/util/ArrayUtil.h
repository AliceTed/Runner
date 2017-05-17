#pragma once
/**
* @file ArrayUtil.h
* @brief �z��p���[�e�B���e�B�[
* @author �����T��
* @date 2016/2/15
*/
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
class ArrayUtil
{
public:
	ArrayUtil()=default;
	~ArrayUtil()=default;
	/**
	* @fn
	* @brief �w��v�f���O�̗v�f�����ɘA������
	* @param (_out) sort����z��
	* @param (_element) �w��v�f
	*/
	template<class T>
	static void sort(std::vector<T>& _out, const T& _element);

private:

};

template<class T>
void ArrayUtil::sort(std::vector<T>& _out, const T & _element)
{
	auto itr = std::find_if(_out.begin(), _out.end(), [_element](const T& _ele) {return _element == _ele;});
	assert(itr != _out.end());
	std::vector<T> tmp;
	std::move(_out.begin(), itr, std::back_inserter(tmp));
	_out.erase(_out.begin(), itr);
	std::move(tmp.begin(), tmp.end(), std::back_inserter(_out));
}
