#pragma once
/**
* @file ClearCommand.h
* @brief �����R�}���h
* @author �����T��
* @date 2016/3/2
*/
#include <GScolor.h>
#include "IRenderCommand.h"
class ClearCommand:public IRenderCommand
{
public:
	ClearCommand(const GScolor& _color);
	virtual void render() override;
private:
	GScolor m_color;
};