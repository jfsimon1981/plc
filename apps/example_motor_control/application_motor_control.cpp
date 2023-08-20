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


#include "../../libplc/plc.h"

#include <stdio.h>
using namespace std;

/*!
 * \section Application
 * * Customer application's init
 * * Setup registers, variables
 * * Setup I/Os
 */

/// Ctor
Application::Application() {};

/// Dtor
Application::~Application() {};

/*!
 * Main application init (runs once)
 * * Setup registers, variables
 * * Setup I/Os
 */
int Application::init() {
	return 0;
}

// Defines
// DI
#define BP1_START 0 
// DO
#define K1_MOTOR1 0
#define K2_MOTOR2 1
#define K3_MOTOR3 1
// AI
#define AI_MOTOR1_RPM 0
// AO
#define AO_BARGRAPH 0

/// Main application infinite loop
int Application::loop() {
  // Local variables
  /*static*/ Timer timer_motors; // FIXME Alloc
  /*static*/ bool motor_run_order = plc->digitalRead(BP1_START); // FIXME Alloc
  // Handle motors 1/2/3 start/stop
  if (motor_run_order) {
    // Start a timer to sequence motor start
    timer_motors.start(15); // TODO 15s ""s unit
    if (timer_motors.is_running()) {plc->digitalWrite(K1_MOTOR1, 1);}
    if (timer_motors.value_s() < 10) {plc->digitalWrite(K2_MOTOR2, 1);}
    if (timer_motors.value_s() < 5) {plc->digitalWrite(K3_MOTOR3, 1);}
  } else {
    // Stop motors
    plc->digitalWrite(K1_MOTOR1, 0);
    plc->digitalWrite(K2_MOTOR2, 0);
    plc->digitalWrite(K3_MOTOR3, 0);
    // Reset and stop sequence timer
    timer_motors.stop();
    timer_motors.reset();
  }
  //
  /*static*/ int motor_act_speed = plc->analogRead(AI_MOTOR1_RPM); // FIXME Alloc
  // Display speed on bargraph
  int speed_bargraph = motor_act_speed / 150; // Scale motor speed
  plc->analogWrite(AO_BARGRAPH, speed_bargraph); // Analog write 0-10 V
  printf(".");
	return 0;
}

