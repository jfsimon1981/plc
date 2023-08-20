# PLC++ Micro

Microcontroller based, C++ programmable PLC project, demo and resources

# Tree

  * libplc: Plc core header and source files
  * gui: Plc GUI / Simulator
  * apps
    * example_helloplc: Tick a LED
    * example_motor_control: Simple motor control
  * runtime: Plc runtime

# HowTo

  * Simply Write two functions:
    * Application::init() // Application init code (run once)
    * Application::loop() // Application main code (runs consinuously)

  * Reference files
    * Application class, write init() and loop(), file: application.cpp
    * main() function, leave as is or customize, file: main.cpp

# Hello PLC++
  * main.cpp
  ```
    int main(int argc, char **argv)
    {
      Plc plc;
      plc.init();
      plc.run();
	    return 0;
    }
  ```
  * application.cpp
  ```
    #include "plc.h"

    Application::Application() {};
    Application::~Application() {};

    // Defines
    // DO
    #define DO_LED_1 0

    // Globals
    Timer tmr;

    int Application::init() {
      tmr.start(500ms);
      tmr.set_autoreload(1);
      return 0;
    }

    /// Main application infinite loop
    int Application::loop() {
      if (tmr.is_elapsed()) {
        plc->do_toggle(DO_LED_1);
        tmr.restart();
      }
      return 0;
    }
  ```
