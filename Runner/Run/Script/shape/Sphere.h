#pragma once
/**
* @file Sphere.h
* @brief Sphere—pŒ`ó\‘¢‘Ì
* @author ¼”ö—T–ç
* @date 2017/5/17
*/
#include <GSvector3.h>

struct Sphere
{
	GSvector3 center;
	float radius;

	Sphere()
		:center({ 0.0f,0.0f ,0.0f }),
		radius(0.0f)
	{

	}

	Sphere(const GSvector3& _center,float _radius)
		:center(),radius(_radius)
	{
	}
};