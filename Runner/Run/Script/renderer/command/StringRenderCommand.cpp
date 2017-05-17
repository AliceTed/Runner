#include "StringRenderCommand.h"

StringRenderCommand::StringRenderCommand(const StringRenderDesc & _desc)
	:m_desc(_desc)
{
}

void StringRenderCommand::render()
{
	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);

	//�����F�̐ݒ�
	glColor4fv((GLfloat*)&m_desc.color);

	//�����t�H���g�̐ݒ�
	gsFontParameter(
		m_desc.font.code,
		m_desc.font.size,
		m_desc.font.name.c_str());

	//�\���ʒu�̐ݒ�
	gsTextPos(m_desc.position.x, m_desc.position.y);

	//������̕`��
	gsDrawText(m_desc.string.c_str());

	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
}
