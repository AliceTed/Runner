#pragma once
/**
* @file SpriteRenderDesc.h
* @brief �X�v���C�g�`��L�q�q
* @author �����T��
* @date 2016/3/3
*/
#include <gslib.h>
#include "../BlendFunc.h"
struct SpriteRenderDesc
{
	SpriteRenderDesc()
		:textureID(0),
		center(0,0),
		color(1.0f, 1.0f, 1.0f, 1.0f),
		isClip(false),
		rect(0.0f,0.0f,0.0f,0.0f),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}
	unsigned int textureID;
	GSvector2 center;
	GSmatrix4 matrix;
	GScolor color;
	bool isClip;
	GSrect rect;
	BlendFunc blendFunc;
};