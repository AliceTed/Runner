#include "Renderer.h"

#include "command\MeshRenderCommand.h"
#include "command\LookAtCommand.h"
#include "command\ClearCommand.h"
#include "command\SpriteRenderCommand.h"
#include "command\StringRenderCommand.h"
#include "command\SkyBoxRenderCommand.h"
Renderer::Renderer()
	:m_currentDisplay(0),
	m_isRendering(false),
	m_isAddCommand(false),
	m_isSync(false),
	m_displayList(2)
{
}
void Renderer::begin()
{
	CriticalSection::Lock guard(m_lock);
	m_isAddCommand = true;
	m_displayList[currentDisplayList()].clear();
}

void Renderer::end()
{
	m_isAddCommand = false;
}

void Renderer::clear(const GScolor & _color)
{
	CommandPtr command = std::make_unique<ClearCommand>(_color);
	m_displayList[currentDisplayList()].add(command);
}

void Renderer::lookAt(const LookAtDesc & _desc)
{
	CommandPtr command = std::make_unique<LookAtCommand>(_desc);
	m_displayList[currentDisplayList()].add(command);
}

void Renderer::draw(const MeshRenderDesc & _desc)
{
	drawTemplate<MeshRenderCommand>(_desc);

	//CommandPtr command = std::make_unique<MeshRenderCommand>(_desc);
	//m_displayList[currentDisplayList()].add(command);
}

void Renderer::draw(const SpriteRenderDesc & _desc)
{
	drawTemplate<SpriteRenderCommand>(_desc);
}

void Renderer::draw(const StringRenderDesc & _desc)
{
	drawTemplate<StringRenderCommand>(_desc);
}

void Renderer::draw(const SkyBoxRenderDesc & _desc)
{
	drawTemplate<SkyBoxRenderCommand>(_desc);
}


void Renderer::sync()
{
	m_isSync = true;
	//�����_�����O���͑ҋ@
	wait(m_isRendering);
	m_isSync = false;
}

void Renderer::render()
{
	m_isRendering = true;
	//�����_�����O�p�̃f�B�X�v���C���X�g���擾
	const auto current = renderDisplayList();
	m_displayList[current].render();
	m_displayList[current].clear();
	swapDisplayList();
	//glutSwapBuffers();
	m_isRendering = false;
	//�������͑ҋ@
	wait(m_isSync);
}

int Renderer::currentDisplayList() const
{
	return m_currentDisplay;
}

int Renderer::renderDisplayList() const
{
	return m_currentDisplay==0?1:0;
}

void Renderer::swapDisplayList()
{
	CriticalSection::Lock guard(m_lock);
	//�R�}���h�ǉ����͑ҋ@
	wait(m_isAddCommand);
	m_currentDisplay = renderDisplayList();
}

void Renderer::wait(const bool& _isWait) const
{
	while (_isWait)Sleep(0);
}

