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

namespace Plc {

// ************* Motor Class *************

class Motor {
  private:
    // Monitoring and protections
    bool b_temperature_monitoring {0};
    int i_winding_temperature_alarm {105};
    int i_winding_temperature_trip {125};
    int i_bearing_temperature_alarm {85};
    int i_bearing_temperature_trip {90};

    // Control
    bool b_running {0};
    bool b_tripped {0};
    bool b_alarm {0};
    bool b_trip {0};
    bool b_brg_alarm {0};
    bool b_brg_trip {0};
    bool b_wdg_alarm {0};
    bool b_wdg_trip {0};

  public:
    // Control
    void start();
    void stop();
    void trip();
    void set_speed(int);
    void reset_trip();

    // Readback
    bool is_healthy();
    bool is_alarm();
    bool is_trip();
    bool is_brg_alarm();
    bool is_brg_trip();
    bool is_wdg_alarm();
    bool is_wdg_trip();

    // Protections
    void set_winding_alarm_value(int);
    void set_winding_trip_value(int);
    void set_bearing_alarm_value(int);
    void set_bearing_trip_value(int);
    void enable_winding_alarm();
    void enable_winding_trip();
    void disable_winding_alarm();
    void disable_winding_trip();
};


}