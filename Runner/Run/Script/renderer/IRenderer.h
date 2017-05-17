#pragma once
/**
* @file IRenderer.h
* @brief �����_���[�p�C���^�[�t�F�C�X
* @author �����T��
* @date 2016/3/3
*/
#include <gslib.h>
struct MeshRenderDesc;
struct SpriteRenderDesc;
struct LookAtDesc;
struct StringRenderDesc;
struct SphereShaderDesc;
struct SkyBoxRenderDesc;
class IRenderer
{
public:
	virtual ~IRenderer() {}
	virtual void begin() = 0;
	//�`��I��
	virtual void end() = 0;
	//��ʏ���
	virtual void clear(const GScolor& _color) = 0;
	//�J����
	virtual void lookAt(const LookAtDesc& _desc) = 0;
	//�`��(�R�}���h�̒ǉ�)
	virtual void draw(const MeshRenderDesc& _desc) = 0;
	//�X�v���C�g�`��
	virtual void draw(const SpriteRenderDesc& _desc) = 0;
	//������`��
	virtual void draw(const StringRenderDesc& _desc) = 0;
	//�X�J�C�{�b�N�X�`��
	virtual void draw(const SkyBoxRenderDesc& _desc) = 0;
	//���������
	virtual void sync() = 0;
};