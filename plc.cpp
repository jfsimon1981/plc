#include "plc.h"

/// Ctor
Plc::Plc() {}
/// Dtor
Plc::~Plc() {}

/// Init
/// System Level (PLC itself) init phase
/// Setup Digital and Analog I/Os
/// Setup clock and timers
/// Setup interrupts
int Plc::init() {
	// ...
	application.init();
	return 0;
}

/// Run the main application
/// Enable interrupts and run
int Plc::run() {
	while (1) {
		application.loop();
	}
	return 0;
}

