#pragma once
#include "PersistentDataID.h"
namespace Engine {
	namespace PersistentData {
		extern int persistentInteger[64];
		extern float persistentFloat[64];
		extern bool persistentBoolean[64];

		extern void initialize();

		extern int getPersistentInteger(enum PersistentIntegerID id_);
		extern float getPersistentFloat(enum PersistentFloatID id_);
		extern bool getPersistentBoolean(enum PersistentBooleanID id_);

		extern void setPersistentInteger(enum PersistentIntegerID id_, int value_);
		extern void setPersistentFloat(enum PersistentFloatID id_, float value_);
		extern void setPersistentBoolean(enum PersistentBooleanID id_, bool value_);
	}
}
