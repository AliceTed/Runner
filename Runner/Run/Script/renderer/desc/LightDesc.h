#pragma once
/**
* @file LightDesc.h
* @brief ���C�g�L�q�q
* @author �����T��
* @date 2016/3/5
*/
#include <gslib.h>
struct LightDesc
{
	LightDesc()
		:ambient(0.6f,0.6f,0.6f,1.0f),
		diffuse(1.0f, 1.0f, 1.0f, 1.0f),
		specular(1.0f, 1.0f, 1.0f, 1.0f),
		position(0.0f, 0.0f, 0.0f)
	{
	}
	GScolor ambient;
	GScolor diffuse;
	GScolor specular;
	GSvector3 position;
};