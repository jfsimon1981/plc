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

#define APPLICATION_TITLE "HelloPLC"
#define APPLICATION_VERSION "1.0"
#define APPLICATION_AUTHOR "LCE"

#include "../../libplc/plc.h"

#include <stdio.h>

/// Ctor
Application::Application(Plc * plc_ptr) {
  plc = plc_ptr;
  printf("Application started: %s\n", APPLICATION_TITLE);
  printf("Version:             %s\n", APPLICATION_VERSION);
  printf("Author:              %s\n", APPLICATION_AUTHOR);
};

/// Dtor
Application::~Application() {
  printf("Application Exit\n");
//  printf("Runtime: %s\nr", plc.show_runtime());
};

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
