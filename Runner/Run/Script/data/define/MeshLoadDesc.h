#pragma once
/**
* @file MeshLoadDesc.h
* @brief ���b�V���̃��[�h�p�\����
* @author �����T��
* @date 2016/2/15
*/
#include<string>
#include "../../id/MESH_ID.h"
struct MeshLoadDesc
{
	MeshLoadDesc(MESH_ID _id, const std::string& _name,bool _isShader=false)
		:m_id(_id),
		m_name(_name),
		m_path("./Asset/Mesh/"),
		m_extension(".msh"),
		m_isShader(_isShader)
	{}
	//�A��
	std::string getName()const
	{
		return m_path + m_name + m_extension;
	}

	MESH_ID m_id;
	std::string m_name;
	std::string m_path;
	std::string m_extension;
	bool m_isShader;
};