#pragma once
/**
* @file ShaderLoadDesc.h
* @brief �V�F�[�_�̃��[�h�p�\����
* @author �����T��
* @date 2016/3/5
*/
#include <string>
#include "../../id/SHADER_ID.h"
struct ShaderLoadDesc
{
	ShaderLoadDesc(SHADER_ID _id, const std::string& _namev, const std::string& _namef)
		:m_id(_id),
		m_nameV(_namev),
		m_nameF(_namef),
		m_path("./asset/shader/"),
		m_extensionV(".glslv"),
		m_extensionF(".glslf")
	{}
	//�t���O�����g�ƃo�[�e�b�N�X�����ꖼ�̃t�@�C���̏ꍇ
	ShaderLoadDesc(SHADER_ID _id, const std::string& _name)
		:ShaderLoadDesc(_id, _name, _name)
	{}
	//�A��
	std::string getNameV()const
	{
		return m_path + m_nameV + m_extensionV;
	}
	//�A��
	std::string getNameF()const
	{
		return m_path + m_nameF + m_extensionF;
	}

	SHADER_ID m_id;
	std::string m_path;
	std::string m_nameV;
	std::string m_nameF;
	
	std::string m_extensionV;
	std::string m_extensionF;
};