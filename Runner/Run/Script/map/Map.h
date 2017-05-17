#pragma once
#ifndef _MAP_H_
#define _MAP_H_
/**
* @file Map.h
* @brief octree—pƒNƒ‰ƒX
* @author ¼”ö—T–ç
* @date 2016/8/17
*/
#include <gslib.h>
#include "../id/OCTREE_ID.h"
struct Ray;
struct Sphere;
class IRenderer;
class Map
{
public:
	Map(OCTREE_ID _id);
	~Map();

	const bool isCollisionRay(const Ray & _ray,GSvector3 * _intersect)const;
	const bool isCollisionSphere(const Sphere& _sphere,GSvector3* _out_center)const;
	/*command–¢À‘•*/
	void draw(IRenderer * _renderer);
private:
	OCTREE_ID m_ID;
};

#endif