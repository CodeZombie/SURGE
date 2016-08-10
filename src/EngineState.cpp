#include "EngineState.h"

EngineState::State EngineState::state;

void EngineState::setState(State s_) {
	state = s_;
}

EngineState::State EngineState::getState() {
	return state;
}

bool EngineState::isRunning() {
	if (state == State::END) {
		return 0;
	}
	return 1;
}