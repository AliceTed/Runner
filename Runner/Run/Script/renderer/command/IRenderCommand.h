#pragma once

/**
* @file IRenderCommand.h
* @brief �`��R�}���h�p�C���^�[�t�F�C�X
* @author �����T��
* @date 2016/3/2
*/
class IRenderCommand
{
public:
	virtual ~IRenderCommand() {}
	/*
	�`�施��
	*/
	virtual void render()=0;
};