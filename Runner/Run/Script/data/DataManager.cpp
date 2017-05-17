#include "DataManager.h"
#include "define\TextureLoadDesc.h"
#include "define\MeshLoadDesc.h"
#include "define\ShaderLoadDesc.h"
#include "../util/Message.h"

void DataManager::load(const TextureLoadDesc & _desc)
{
	load(_desc, gsLoadTexture, "�e�N�X�`���̓ǂݍ��݃G���[");
	
	//CriticalSection::Lock guard(m_lock);
	//std::string name = _desc.m_path + _desc.m_name + _desc.m_extension;
	//if (gsLoadTexture(CastID::id2uint(_desc.m_id), name.c_str()) == GS_TRUE)return;
	//Message::send("�e�N�X�`���̓ǂݍ��݃G���[",name);
}

void DataManager::load(const MeshLoadDesc & _desc)
{
	auto loader = _desc.m_isShader ? gsLoadMeshEx : gsLoadMesh;
	load(_desc, loader, "���b�V���̓ǂݍ��݃G���[");
}

void DataManager::load(const ShaderLoadDesc & _desc)
{
	std::string nameV =_desc.getNameV();
	std::string nameF = _desc.getNameF();

	if (gsLoadShader(CastID::idToUInt(_desc.m_id), nameV.c_str(),nameF.c_str()) == GS_TRUE)return;
	Message::send("�V�F�[�_�̓ǂݍ��݃G���[", nameV+":"+nameF);
}

void DataManager::release()
{
	//�S�Ẵ��\�[�X���
	gsFinishGraphics();
	/*eachRelease(gsDeleteTexture,TEXTURE_ID::SIZE);
	eachRelease(gsDeleteMesh, MESH_ID::SIZE);*/
}
