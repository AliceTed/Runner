#include "SkyBoxRenderCommand.h"
#include <gslib.h>
#include "../../id/CastID.h"
#include "../../id/SHADER_ID.h"
SkyBoxRenderCommand::SkyBoxRenderCommand(const SkyBoxRenderDesc & _desc)
	:m_desc(_desc)
{
}

void SkyBoxRenderCommand::render()
{
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT);
	// ����ϊ��s���ޔ�����
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(m_desc.time*0.1f,0,1,0);
	gsDrawSkyBox(m_desc.meshID);
	//uv����������
	//gsBeginShader(CastID::id2uint(SHADER_ID::SKYBOX));
	////gsDrawSkyBoxEx���Ńo�C���h���Ă���
	//gsSetShaderParamTexture("u_baseMap",0);
	////���Ԍo�߂�uv�X�N���[����
	//gsSetShaderParam1f("u_time",m_desc.time);
	//gsDrawSkyBoxEx(m_desc.meshID);
	//gsEndShader();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glPopAttrib();
}
