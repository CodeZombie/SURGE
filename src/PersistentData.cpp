#include "PersistentData.h"

int Engine::PersistentData::persistentInteger[64];
float Engine::PersistentData::persistentFloat[64];
bool Engine::PersistentData::persistentBoolean[64];

void Engine::PersistentData::initialize() {
	for (int i = 0; i < 64; i++) {
		persistentInteger[i] = 0;
		persistentFloat[i] = 0.f;
		persistentBoolean[i] = false;
	}
}

int Engine::PersistentData::getPersistentInteger(enum PersistentIntegerID id_) {
	return persistentInteger[id_];
}

float Engine::PersistentData::getPersistentFloat(enum PersistentFloatID id_) {
	return persistentFloat[id_];
}

bool Engine::PersistentData::getPersistentBoolean(enum PersistentBooleanID id_) {
	return persistentBoolean[id_];
}

void Engine::PersistentData::setPersistentInteger(enum PersistentIntegerID id_, int value_) {
	persistentInteger[id_] = value_;
}

void Engine::PersistentData::setPersistentFloat(enum PersistentFloatID id_, float value_) {
	persistentFloat[id_] = value_;
}

void Engine::PersistentData::setPersistentBoolean(enum PersistentBooleanID id_, bool value_) {
	persistentBoolean[id_] = value_;
}