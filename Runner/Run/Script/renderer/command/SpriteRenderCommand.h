#pragma once
/**
* @file SpriteRenderCommand.h
* @brief �X�v���C�g�`��R�}���h
* @author �����T��
* @date 2016/3/3
*/
#include "IRenderCommand.h"
#include "../desc/SpriteRenderDesc.h"
class SpriteRenderCommand:public IRenderCommand
{
public:
	SpriteRenderCommand(const SpriteRenderDesc& _desc);
	
	virtual void render() override;
private:
	SpriteRenderDesc m_desc;
};