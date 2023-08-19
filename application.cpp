#include "plc.h"

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

/// Main application infinite loop
int Application::loop() {
  // Local variables
  static Timer timer_motors123;
  static bool motor_run_order = plc->digitalRead(bp1_start);
  // Handle motors 1/2/3 start/stop
  if (motor1_run_order) {
    // Start a timer to sequence motor start
    timer_motor1.start(15s);
    if (timer_motors123.is_running()) {plc->digitalWrite(k1_motor1, 1);}
    if (timer_motors123.value_s() < 10) {plc->digitalWrite(k2_motor2, 1);}
    if (timer_motors123.value_s() < 5) {plc->digitalWrite(k3_motor3, 1);}
  } else {
    // Stop motors
    plc->digitalWrite(k1_motor1, 0);
    plc->digitalWrite(k2_motor2, 0);
    plc->digitalWrite(k3_motor3, 0);
    // Reset and stop sequence timer
    timer_motors123.stop();
    timer_motors123.reset();
  }
  //
  plc->digitalWrite(k1_motor1, val);
  plc->digitalWrite(k2_motor2, val);
  plc->digitalWrite(k3_motor3, val);
  motor_act_speed = analogRead(dynamo_motor1);
  // Display speed on bargraph
  int speed_bargraph = motor_act_speed / 150; // Scale motor speed
  analogWrite(h1_bargraph, speed_bargraph); // Analog write 0-10 V
  printf(".");
	return 0;
}

