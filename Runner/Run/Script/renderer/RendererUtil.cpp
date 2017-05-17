#include "RendererUtil.h"

void RendererUtil::drawQuad(const GSrect & _rect, const GSrect & _texCoord, const GScolor & _color)
{
	glBegin(GL_QUADS);
	glColor4fv((GLfloat*)&_color);
	glTexCoord2f(_texCoord.left, _texCoord.top);
	glVertex2f(_rect.left, _rect.top);
	glTexCoord2f(_texCoord.left, _texCoord.bottom);
	glVertex2f(_rect.left, _rect.bottom);
	glTexCoord2f(_texCoord.right, _texCoord.bottom);
	glVertex2f(_rect.right, _rect.bottom);
	glTexCoord2f(_texCoord.right, _texCoord.top);
	glVertex2f(_rect.right, _rect.top);
	glEnd();
}

void RendererUtil::drawTexture(unsigned int _id, const GScolor & _color)
{	
	// �e�N�X�`�����o�C���h����
	gsBindTexture(_id);	
	GSvector2 size=getTextureSize();

	GSrect rect(0, 0, size.x, size.y);
	GSrect texCoord(0.0f, 0.0f, 1.0f, 1.0f);

	drawQuad(rect,texCoord,_color);

	// �e�N�X�`���𖳌��ɂ���
	glBindTexture(GL_TEXTURE_2D, 0);
}

void RendererUtil::drawTexture(unsigned int _id, const GSrect & rect, const GSrect & srcRect, const GScolor & _color)
{
	// �e�N�X�`�����o�C���h����
	gsBindTexture(_id);

	GSvector2 size = getTextureSize();

	// �e�N�X�`�����W�̌v�Z���s��
	GSrect texCoord(
		srcRect.left / size.x,
		srcRect.top / size.y,
		srcRect.right / size.x,
		srcRect.bottom / size.y);

	drawQuad(rect,texCoord,_color);

	// �e�N�X�`���𖳌��ɂ���
	glBindTexture(GL_TEXTURE_2D, 0);
}

GSvector2 RendererUtil::getTextureSize()
{
	GLsizei texWidth;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &texWidth);
	GLsizei	texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	return GSvector2(texWidth, texHeight);
}

void RendererUtil::setBlendFunc(BlendFunc _func)
{//�u�����h��L����
	glEnable(GL_BLEND);

	switch (_func)
	{
	case BlendFunc::NONE://�u�����h�Ȃ�
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
		break;
	case BlendFunc::DEFAULT://�f�t�H���g
		glDepthMask(GL_TRUE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BlendFunc::ALPHA://�A���t�@�l�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
		break;
	case BlendFunc::ADD://���Z�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	case BlendFunc::SUB://���Z�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	default:
		break;
	}
}
