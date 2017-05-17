#pragma once
/**
* @file MeshRenderCommand.h
* @brief ���b�V���`��R�}���h
* @author �����T��
* @date 2016/3/2
*/
#include "IRenderCommand.h"
#include "../desc/MeshRenderDesc.h"
class MeshRenderCommand:public IRenderCommand
{
public:
	MeshRenderCommand(const MeshRenderDesc& _desc);
	virtual void render() override;
private:
	MeshRenderDesc m_desc;
};