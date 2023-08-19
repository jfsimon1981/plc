#include "plc.h"

// Class Plc

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

int Plc::digitalRead(int port) {return 0;};
void Plc::digitalWrite(int port, int val) {};
int Plc::analogRead(int port) {return 0;};
void Plc::analogWrite(int port, int val) {};

/// Class Timer
/// Read
bool Timer::is_running() {return 0;}
int Timer::value_s() {return 0;}

// Write
void Timer::start() {}
void Timer::start(int timer_val_in) {}
void Timer::stop() {}
void Timer::reset() {}

/// Ctor Dtor
Timer::Timer() {}
Timer::~Timer() {}
