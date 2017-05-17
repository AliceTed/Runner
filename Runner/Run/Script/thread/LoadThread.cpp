#include "LoadThread.h"
#include "../data/DataManager.h"
#include "../data/define\TextureLoadDesc.h"
#include "../data/define\MeshLoadDesc.h"
LoadThread::LoadThread(DataManager* _dataManager)
	:m_dataManager(_dataManager),
	m_isEnd(false)
{
}

LoadThread::~LoadThread()
{
	exit();
}

void LoadThread::run()
{
}

bool LoadThread::isEnd() const
{
	return m_isEnd;
}

void LoadThread::exit()
{
	m_isEnd = true;
	join();
}
