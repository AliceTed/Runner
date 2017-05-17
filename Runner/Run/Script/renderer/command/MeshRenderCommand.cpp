#include "MeshRenderCommand.h"

MeshRenderCommand::MeshRenderCommand(const MeshRenderDesc & _desc)
	:m_desc(_desc)
{
}

void MeshRenderCommand::render()
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//�J���[�̐ݒ�
	glColor4fv((GLfloat*)&m_desc.color);

	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadName(GL_PROJECTION_MATRIX);

	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadName(GL_MODELVIEW_MATRIX);

	//���b�V���`��
	glMultMatrixf((GLfloat*)&m_desc.matrix);
	gsDrawMesh(m_desc.meshID);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
}
