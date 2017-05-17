#include "CharacterStateManager.h"
#include "ICharacterState.h"
#include <assert.h>
CharacterStateManager::CharacterStateManager(const CharacterStateManager & _other)
{
	/*for (const auto i:_other.m_stateContainer)
	{
		auto state=i.second->clone();
		state->setCharacter();
		registerState(i.first, ICharacterStatePtr(state));
	}*/
}
void CharacterStateManager::registerState(CHARACTER_STATE _stateKey, ICharacterStatePtr _state)
{
	m_stateContainer.insert(std::make_pair(_stateKey,_state));
}

void CharacterStateManager::changeState(CHARACTER_STATE _next)
{
	assert(m_stateContainer.count(_next)!=0);
	m_currentStateKey = _next;
	m_currentState = m_stateContainer.at(m_currentStateKey).get();
}
