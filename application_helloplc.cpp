#include "plc.h"

Application::Application() {};
Application::~Application() {};

// Defines
// DO
#define DO_LED_1 0

// Globals
Timer tmr;

int Application::init() {
  tmr.start(500/*ms*/); // FIXME ""ms
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
