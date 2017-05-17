#include "Animator.h"
#include <gslib.h>
#include "../renderer/IRenderer.h"
#include "Animator.h"
//#include "../renderer/define/SkinnedMeshRenderDesc.h"
Animator::Animator(GSuint _modelID)
	:m_modelID(_modelID),
	m_timer(0),
	m_current(0),
	m_matrix(new GSmatrix4[LENGHT], std::default_delete<GSmatrix4[]>()),
	m_isLerp(false),
	m_lerp(_modelID)
{
}

void Animator::start(const Animation & _next, float _speed, float _endTime, bool _isLerp)
{
	m_isLerp = _isLerp;
	if (m_isLerp)
	{
		m_lerp.begin(m_current.m_animation, m_timer.current, _next.m_animation, 0);
	}
	float end = _endTime;
	if (_endTime == 0.0f)
	{
		end = _next.endTime(m_modelID);
	}
	m_current = _next;
	m_timer.end = end;
	m_timer.speed = _speed;
	m_timer.reset();
}

void Animator::update(float deltaTime)
{
	calculateAnimation();
	if (m_isLerp)
	{
		m_lerp.update(deltaTime);
		m_isLerp = !m_lerp.isEnd();
		return;
	}
	m_timer.update(deltaTime);
	if (m_timer.isEnd() && m_current.m_isLoop)
	{
		m_timer.reset();
	}
}

const bool Animator::isEnd() const
{
	return m_timer.isEnd() && !m_current.m_isLoop;
}

const GSmatrix4&  Animator::getSkelton(GSuint _index) const
{
	return m_matrix.get()[_index];
}
const AnimationTimer & Animator::getTimer() const
{
	return m_timer;
}

void Animator::draw(IRenderer * _renderer, const Transform & _t)
{
	std::unique_ptr<GSmatrix4>mat(new GSmatrix4[LENGHT]);
	//スケルトンの位置情報を計算
	gsSkeletonCalculateTransform(
		gsGetSkeleton(m_modelID),
		mat.get(),
		m_matrix.get());

	/*SkinnedMeshRenderDesc desc;
	desc.meshID = static_cast<GSuint>(m_modelID);
	desc.shaderID = static_cast<GSuint>(0);
	desc.matrix = _t.matrix();
	desc.animation = mat.get();
	_renderer.render(desc);*/
}

void Animator::calculateAnimation()
{
	std::unique_ptr<GSmatrix4> animMat(new GSmatrix4[LENGHT]);
	if (m_isLerp)
	{
		m_lerp.calulate(animMat.get());
	}
	else
	{
		//アニメーションの計算	
		gsCalculateAnimation(
			m_modelID,
			m_current.m_animation,
			m_timer.current,
			animMat.get());
	}
	//スケルトン情報の計算
	gsSkeletonCalculateOrientation(gsGetSkeleton(m_modelID), m_matrix.get(), NULL, animMat.get());
}

