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

// Exercice de style

#include "plc.h"
#define VERSION "1.0"

// In Lcd source files
enum Lcd_screen {start_screen, screen_1, screen_2, screen_3};

Class Lcd {
  private:
    bool clear_request {0}; // Set by method when state changes
  public:
    enum States {init, running, fault};
    States state {init};
    Screen screen {start_screen};
    void set_backlight(int);

  void init();
};
//

// PLC Class
// TODO implementation shouldn't be visible, place in internal files

enum Plc_state {init, idle, start, running, stop};

Class Plc {
  private:
    uint32_t port[1];
    Plc_state state {init};
warning
fault
  public:

    void write_port(int);
    uint32_t read_port(int);

    void main();

    void init();
    void loop();
    void start();
    void stop();

    void warning();
    void fault();

    Plc_state read_state();
}

void Plc::main() {
  switch (state) {
    case init:
      init();
      state = Plc_state::idle;
      break;
    case idle:
      break;
    case start:
      start();
      state = Plc_state::running;
      break;
    case running:
      loop();
      break;
    case stop:
      stop();
      state = Plc_state::idle;
      break;
    default:
  }
}

// End of PLC class

// In Application source files

enum Application_state {init, idle, start, running, stop};

Class Application {
  private:
    Application_state state {init};
warning
fault
  public:

    void main();

    // Redefined by application:
    void init();
    void loop();
    void start();
    void stop();

    void warning();
    void fault();

    Application_state read_state();
};

//

// PLC Main function
main() {

  // PLC(s) and peripheral(s)

  Plc plc1;
  Lcd lcd1;

  // PLC controlled tasks

  // Interrupt based
  plc1.create_task {plc_main_task, 10ms, REAL_TIME};
  plc1.create_task {plc_read_di_task, 10ms, REAL_TIME};
  plc1.create_task {plc_write_do_task, 10ms, REAL_TIME};

  // Scheduler based
  plc1.create_task {user_task1_rt, 1ms, REAL_TIME};
  plc1.create_task {user_lcd_task, 100ms, SCHEDULED};

  // Applications
  Application app1;
  plc1.register_application(app1, 10ms);

  plc1.start();

  while (1) {
    plc1.main();
  }
}

// PLC controlled tasks: run independently from user application

void plc_read_di_task() {}
void plc_write_do_task() {}

// ************* User functions *************

// Application 1
// Demo test bench for vibrations

// We control 2 motors to generate a 1kHz 0.120 Nm Sinus vibration
// and 60 degree sinus oscillation
Wave_genetator::Sine sine_vibrations(120.0, 1ms); // Amplitude, period
Wave_genetator::Sine sine_oscillations(60.0, 15hz); // Amplitude, period
Motor_controller motor1 {2000rpm, 120mnm, TORQUE_CONTROL};
Motor_controller motor2 {1500rpm, 2.5nm, POSITION_CONTROL, -60, +60};

// Run on application start
void Application::init() {
  // Wait for start push button
  waitpb
  motor1.
  motor2.
}

// User main application: controlled by user
void Application::main() {
  switch (app1.state) {
    case init:
      break;
    case idle:
      break;
    case start:
      break;
    case running:
      break;
    case stop:
      break;
    default:
  }
}

void Application::loop() {}

// Run on application start
void Application::start() {
}

// Run on application stop
void Application::stop() {
}

// Application loop running real time
void Application::loop() {

}

// ************* *************

// User tasks: run as long as PLC is in run state
// Real time tasks are critical as they run in interrupt context
// Keep them short
void user_task1_rt() {
  switch (app1.state) {
    case init:
      break;
    case idle:
      break;
    case start:
      break;
    case running:
      motor1.set_torque(sine_vibrations);
      motor2.set_position(sine_oscillations);
      break;
    case stop:
      motor1.set_torque(0);
      motor2.set_position(0);
      break;
    default:
  }
}

void user_lcd_task() {
  /*
   * clear(); // Clear screen
   * clear_chars_from_cursor(N); // Clear N char(s) on line from and including cursor
   * clear_chars_before_cursor(N); // Clear N char(s) on line before and not including cursor
   * clear_line_from_cursor(); // Clear line after cursor
   * clear_line_before_cursor(); // Clear line before cursor
   * clear_line(); // Clears entire line
   *
   * set_line(L) // Select line L to write
   * set_cursor(C); // Set cursor at position C
   * set_line_cursor(L, C); // Set cursor at position L, C
   *
   * write(""); // Write text at current line/cursor
   * write("", L); // Write text at line L
   * write("", L, C); // Write text at line L, cursor position C
   * write("", L, C, A_ALIGN); // Write text at position with alignment A (LEFT, RIGHT, CENTER)
   *
   * backlight(); // 0 or 1
   */

  if (clear_request)
    clear();

  switch (lcd1.screen) {
    case start_screen:
      lcd1.write("Ajauru Sofuto", 1, 10, CENTER_ALIGN);
      lcd1.write("Version", 2, 1);
      lcd1.write(VERSION, 2, 9);
      break;
    case screen_1:
      lcd1.write("Ajauru Sofuto", 1, 10, CENTER_ALIGN);
      lcd1.write("Date", 2, 1);
      lcd1.write(date, 2, 20, RIGHT_ALIGN);
      lcd1.write("Time", 3, 1);
      lcd1.write(timer, 3, 20, RIGHT_ALIGN);
      lcd1.write("PLC State", 4, 1);
      // Update State
      lcd1.set_line_cursor(4, 20);
      lcd1.clear_line_before_cursor(10);
      lcd1.write(plc1.read_state(), 4, 20, RIGHT_ALIGN);
      break;
    default:
  }
}
