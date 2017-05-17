#pragma once
/**
* @file StringRenderDesc.h
* @brief ������`��L�q�q
* @author �����T��
* @date 2016/3/3
*/
#include <string>
#include <gslib.h>
//�t�H���g�̎w��
struct  Font
{
	//�C���R�[�h
	static const unsigned int CODE_NOMAL = 0; //�w��Ȃ�
	static const unsigned int CODE_BOLD = (1 << 0);  //����
	static const unsigned int CODE_ITALIC = (1 << 1);//�C�^���b�N
	static const unsigned int CODE_UNDERLINE = (1 << 2);//�A���_�[���C��
	static const unsigned int CODE_STRIKEOUT = (1 << 3);//��������

	Font() :
		code(CODE_NOMAL),
		size(16),
		name("�l�r �S�V�b�N")
	{}
	//�C���R�[�h
	int code;
	int size;
	//�t�H���g��
	std::string name;
};

struct StringRenderDesc
{
	StringRenderDesc() :
		font(),
		string(""),
		position(0, 0),
		color(1, 1, 1, 1)
	{}
	//�t�H���g
	Font font; 
	//������
	std::string string;
	GSvector2 position;
	GScolor color;
};