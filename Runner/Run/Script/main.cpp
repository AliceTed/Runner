#include <GSgame.h>
#include <memory>
#include "renderer\Renderer.h"
#include "scene\SceneManager.h"

#include "data\DataManager.h"
#include "data\define\TextureLoadDesc.h"
#include "data\define\MeshLoadDesc.h"
#include "data\define\ShaderLoadDesc.h"
#include "id\RENDER_TARGET_ID.h"

#include "gamethread\MyGameThread.h"
class MyGame : public gslib::Game
{
public:
	MyGame()
		:Game(1280, 720, false),
		m_renderer(),
		m_gameTread(nullptr)
	{
	}
private:
	virtual void start() override
	{
		//Resource��lord���X���b�h�łł��Ȃ����߂Ƃ肠���������ɋL��
		DataManager::load(MeshLoadDesc(MESH_ID::PLAYER,"CyberSoldier/CyberSoldier"));


		m_gameTread = std::make_unique<MyGameThread>(&m_renderer);
		m_gameTread->start();
	}

	// �X�V
	virtual void update(float deltaTime) override
	{
		m_renderer.render();
	}
	// �`��
	virtual void draw() override
	{
	}
	// �I��
	virtual void end() override
	{
		DataManager::release();
	}
private:
	Renderer m_renderer;
	std::unique_ptr<MyGameThread>m_gameTread;
};

int main()
{
	return MyGame().run();
}
