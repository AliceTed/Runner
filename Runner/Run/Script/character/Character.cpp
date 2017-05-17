#include "Character.h"

Character::Character(const Transform _transform,GSuint _modelID)
	:m_transform(_transform),
	m_animator(_modelID),

	m_isDead(false),
	m_isGround(false)
{
}

void Character::draw(IRenderer * _renderer)
{
	m_animator.draw(_renderer,m_transform);
}

bool Character::isDead() const
{
	return m_isDead;
}

bool Character::isGround() const
{
	return m_isGround;
}

void Character::killSelf()
{
	m_isDead = true;
}
