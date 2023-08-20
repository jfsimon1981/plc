/*
 * Copyright (c) 2023
 *	Chrysalide Engineering SAS. All rights reserved.
 *
 * This code is original work.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

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

void Plc::do_toggle(int value_in) {};

/// Class Timer
/// Read
bool Timer::is_running() {return 0;}
int Timer::value_s() {return 0;}
bool Timer::is_elapsed() {return 0;}

// Write
// FIXME API correctness
void Timer::start() {}
void Timer::start(int timer_val_in) {}
void Timer::stop() {}
void Timer::reset() {}
void Timer::restart() {}

void Timer::set_autoreload(int value_in) {};

/// Ctor Dtor
Timer::Timer() {}
Timer::~Timer() {}
