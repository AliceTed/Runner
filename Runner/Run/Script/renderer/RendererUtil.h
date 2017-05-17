#pragma once
/**
* @file RendererUtil.h
* @brief �����_���[���[�e�B���e�B�[
* @author �����T��
* @date 2016/3/3
*/
#include <gslib.h>
#include "BlendFunc.h"
class RendererUtil
{
public:
	RendererUtil()=default;
	~RendererUtil()=default;
	static void setBlendFunc(BlendFunc _func);
	static void drawQuad(const GSrect& _rect,const GSrect& _texCoord,const GScolor& _color);
	static void drawTexture(unsigned int _id, const GScolor& _color);
	static void drawTexture(unsigned int _id, const GSrect& rect, const GSrect& srcRect, const GScolor& _color);
private:
	//�o�C���h���̃e�N�X�`���̃T�C�Y(���A����)���擾
	static GSvector2 getTextureSize();
};