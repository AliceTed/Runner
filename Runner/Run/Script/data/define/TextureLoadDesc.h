#pragma once

/**
* @file TextureLoadDesc.h
* @brief �e�N�X�`���̃��[�h�p�\����
* @author �����T��
* @date 2016/2/15
*/
#include<string>
#include "../../id/TEXTURE_ID.h"
struct TextureLoadDesc
{
	TextureLoadDesc(TEXTURE_ID _id,const std::string& _name)
		:m_id(_id),
		m_name(_name),
		m_path("./asset/texture/"),
		m_extension(".png")
	{}
	//�A��
	std::string getName()const
	{
		return m_path + m_name + m_extension;
	}
	TEXTURE_ID m_id;
	std::string m_name;
	std::string m_path;
	std::string m_extension;		
};