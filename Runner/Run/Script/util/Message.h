#pragma once
/**
* @file Message.h
* @brief メッセージbox
* @author 松尾裕也
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