#pragma once
/**
* @file Message.h
* @brief bZ[Wbox
* @author ¼öTç
* @date 2016/1/19
*/

#include <string>
class Message
{
public:
	Message() = default;
	~Message() = default;

	static void send(const std::string& _title,const std::string & _message);
};