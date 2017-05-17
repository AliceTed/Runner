#pragma once
/**
* @file Renderer.h
* @brief �}���`�X���b�h�����_���[
* @author �����T��
* @date 2016/3/2
*/
//ActiveObject�p�^�[��

#include "IRenderer.h"
#include "DisplayList.h"
#include "../thread/CriticalSection.h"

class Renderer:public IRenderer
{
public:
	Renderer();
	//�`��J�n
	virtual void begin()override;
	//�`��I��
	virtual void end()override;
	//��ʏ���
	virtual void clear(const GScolor& _color)override;
	//�J����
	virtual void lookAt(const LookAtDesc& _desc)override;
	//�`��(�R�}���h�̒ǉ�)
	virtual void draw(const MeshRenderDesc& _desc)override;
	//�X�v���C�g�`��
	virtual void draw(const SpriteRenderDesc& _desc)override;
	//������`��
	virtual void draw(const StringRenderDesc& _desc)override;
	//�X�J�C�{�b�N�X�`��
	virtual void draw(const SkyBoxRenderDesc & _desc) override;

	//���������
	virtual void sync()override;
	//�f�B�X�v���C���X�g�̕`��
	void render();
private:
	//���݂̃f�B�X�v���C���X�g���擾
	int currentDisplayList()const;
	//�����_�����O���s���f�B�v���C���X�g���擾
	int renderDisplayList()const;
	//�X���b�v
	void swapDisplayList();
	//�ҋ@ (true�őҋ@)
	void wait(const bool& _isWait)const;

	template<class Command,class Desc>
	void drawTemplate(const Desc& _desc)
	{
		CommandPtr command = std::make_unique<Command>(_desc);
		m_displayList[currentDisplayList()].add(command);
	}
private:
	//�f�B�X�v���C(�_�u���o�b�t�@�悤�ɂQ��)
	std::vector<DisplayList> m_displayList;
	//DisplayList m_displayList[2];
	//���݂̃f�B�X�v���C���X�g
	int m_currentDisplay;
	//���ݕ`�撆���H
	bool m_isRendering;
	//�R�}���h�ݒ蒆���H
	bool m_isAddCommand;
	//���������H
	bool m_isSync;
	//�N���e�B�J���Z�N�V����
	CriticalSection m_lock;
};