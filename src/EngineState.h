#pragma once

namespace EngineState {
	enum State {
		PLAY,
		END
	};

	extern State state;
	
	extern void setState(State s_);
	extern State getState();
	extern bool isRunning();
}