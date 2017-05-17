#include "Map.h"
#include "../shape/Ray.h"
#include "../shape/Sphere.h"
#include "../id/CastID.h"
#include "../renderer/IRenderer.h"

Map::Map(OCTREE_ID _id)
	:m_ID(_id)
{
}

Map::~Map()
{
}

const bool Map::isCollisionRay(const Ray & _ray, GSvector3 * _intersect)const
{
	return gsOctreeCollisionRay(gsGetOctree(CastID::idToUInt(m_ID)),&_ray.point,&_ray.direction,_intersect, NULL)==GS_TRUE;
}

const bool Map::isCollisionSphere(const Sphere& _sphere, GSvector3* _out_center) const
{
	return gsOctreeCollisionSphere(gsGetOctree(CastID::idToUInt(m_ID)), &_sphere.center, _sphere.radius,_out_center) == GS_TRUE;
}
void Map::draw(IRenderer * _renderer)
{
	//_renderer->draw();
}
