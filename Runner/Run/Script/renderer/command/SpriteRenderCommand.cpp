#include "SpriteRenderCommand.h"
#include "../RendererUtil.h"
SpriteRenderCommand::SpriteRenderCommand(const SpriteRenderDesc & _desc)
	:m_desc(_desc)
{
}

void SpriteRenderCommand::render()
{
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// ���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	// ���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);

	// �u�����h���@�̐ݒ�
	RendererUtil::setBlendFunc(m_desc.blendFunc);

	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);

	// �����ϊ��s��̑ޔ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	// �r���[�|�[�g�̎擾
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	// ���ˉe�̕ϊ��s���ݒ�
	glLoadIdentity();
	gluOrtho2D(0.0f, (float)viewport[2], (float)viewport[3], 0.0f);

	// ���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// �ϊ��s��̏�����
	glLoadIdentity();

	glMultMatrixf(m_desc.matrix);
	glTranslatef(-m_desc.center.x, -m_desc.center.y, 0);

	if (m_desc.isClip)
	{
		float width = m_desc.rect.right - m_desc.rect.left;
		float height = m_desc.rect.bottom - m_desc.rect.top;
		GSrect rect(0, 0, width, height);
		RendererUtil::drawTexture(m_desc.textureID,rect,m_desc.rect,m_desc.color);
	}
	else
	{
		RendererUtil::drawTexture(m_desc.textureID, m_desc.color);
	}	

	// ���f���r���[�ϊ��s��𕜋A
	glPopMatrix();
	// �����ϊ��s��𕜋A
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	// ���f���r���[�ϊ��s��ɐݒ�
	glMatrixMode(GL_MODELVIEW);
	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
	// �����_�����O�X�e�[�g�̕��A
	glPopAttrib();
}
