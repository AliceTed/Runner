#pragma once
/**
* @file MyGameThread.h
* @brief �Q�[���X���b�h
* @author �����T��
* @date 2016/3/2
*/
#include "GameThread.h"
#include "../scene/SceneManager.h"
class MyGameThread :public GameThread
{
public:
	MyGameThread(IRenderer* _device);
	~MyGameThread();
	//�����I��
	void exit();
private:
	virtual void initialize() override;

	virtual void update(float deltaTime) override;

	virtual void draw() override;

	virtual void end() override;

	virtual bool isEnd() const override;
private:
	bool m_isEnd;
	SceneManager m_sceneManager;
};