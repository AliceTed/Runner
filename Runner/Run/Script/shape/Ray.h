#pragma once
/**
* @file Ray.h
* @brief Ray—pŒ`ó\‘¢‘Ì
* @author ¼”ö—T–ç
* @date 2017/5/17
*/
#include <GSvector3.h>
struct Ray
{
	GSvector3 point;
	GSvector3 direction;

	Ray()
		:point({ 0.0f,0.0f ,0.0f }),
		direction({ 0.0f,0.0f ,0.0f })
	{

	}

	Ray(const GSvector3& _point, const GSvector3& _direction)
		:point(_point), direction(_direction)
	{
	}
};