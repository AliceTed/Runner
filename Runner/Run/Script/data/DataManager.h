#pragma once

/**
* @file DataManager.h
* @brief �f�[�^�Ǘ��p�N���X
* @author �����T��
* @date 2016/2/15
*/
#include<gslib.h>
#include <string>
#include "../id/CastID.h"
#include "../thread/CriticalSection.h"
struct TextureLoadDesc;
struct MeshLoadDesc;
struct ShaderLoadDesc;
class DataManager
{
public:
	DataManager()=default;
	~DataManager()=default;
	static void load(const TextureLoadDesc& _desc);
	static void load(const MeshLoadDesc& _desc);
	static void load(const ShaderLoadDesc& _desc);
	static void release();
private:
	template<class Desc,class Loader>
	static void load(const Desc& _desc, Loader _loader, const std::string& _errMes)
	{
		std::string name = _desc.getName();
		if (_loader(CastID::idToUInt(_desc.m_id), name.c_str()) == GS_TRUE)return;
		Message::send(_errMes, name);
	}

	/**
	* @fn
	* @brief �w��֐��Ńf�[�^���J��
	* @param (_func) �w��֐�
	* @param (_size) �J������f�[�^�̃T�C�Y
	*/
	template<class Func,class DataEnum> 
	static void eachRelease(Func _func, DataEnum _size);
private:
	//CriticalSection m_lock;
};

template<class Func, class DataEnum>
void DataManager::eachRelease(Func _func, DataEnum _size)
{
	for (auto i = 0U; i < CastID::id2uint(_size); i++)
	{
		_func(i);
	}
}
