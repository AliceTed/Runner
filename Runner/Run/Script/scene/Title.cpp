#include "Title.h"
#include "../renderer/IRenderer.h"
#include "../id/CastID.h"
#include "../id/MESH_ID.h"
#include "../renderer/desc/MeshRenderDesc.h"
#include "../renderer/desc/LookAtDesc.h"
Title::Title()
{
}
void Title::initialize()
{
}

void Title::update(float deltaTime)
{
}

void Title::draw(IRenderer * _renderer)
{
	LookAtDesc lookAt;
	lookAt.eye = GSvector3(0, 30, -100);
	lookAt.at = GSvector3(0, 0, 0);	
	lookAt.up = GSvector3(0, 1, 0);
	_renderer->lookAt(lookAt);

	MeshRenderDesc desc;
	desc.meshID = CastID::idToUInt(MESH_ID::PLAYER);
	_renderer->draw(desc);
}

void Title::finish()
{
}

const SceneMode Title::next() const
{
	return SceneMode::GAMEPLAY;
}

const bool Title::isEnd() const
{
	return false;
}

const bool Title::isExit() const
{
	return false;
}
