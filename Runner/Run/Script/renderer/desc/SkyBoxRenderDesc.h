#pragma once

/**
* @file SkyBoxRenderDesc.h
* @brief �X�J�C�{�b�N�X�`��L�q�q
* @author �����T��
* @date 2016/3/5
*/
struct SkyBoxRenderDesc
{
	SkyBoxRenderDesc()
		:meshID(0),
		time(0)
	{
	}
	unsigned int meshID;
	float time;
};