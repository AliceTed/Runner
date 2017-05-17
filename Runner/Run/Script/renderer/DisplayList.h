#pragma once
/**
* @file DisplayList.h
* @brief �R�}���h�i�[���X�g
* @author �����T��
* @date 2016/3/2
*/
#include <memory>
#include <vector>
#include "../thread/CriticalSection.h"
//class IRenderCommand;
#include "command\IRenderCommand.h"
using CommandPtr = std::unique_ptr<IRenderCommand>;
class DisplayList
{
public:
	DisplayList();
	~DisplayList()=default;
	void clear();
	//�R�}���h�̒ǉ�(move)
	void add(CommandPtr& _command);
	//�S�R�}���h�̎��s
	void render();
private:
	using CommandList = std::vector<CommandPtr>;
	CriticalSection m_lock;
	CommandList m_list;
};