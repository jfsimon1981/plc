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

// ************* PLC and Application Classes *************

class Plc;

class Application {
	private:
	public:
    Plc* plc {0};
    bool running {1}; /// Auto run on PLC start
		int init();	/// Main Application initialisation
		int loop();	/// Main application loop
    void start(); /// Request Start Application runtime
    void stop(); /// Request Stop Application runtime
		Application(Plc* plc_ptr);	/// Ctor
		~Application();	/// Dtor
};

class Plc {
	private:
		Application application {this};
	public:
		int init();	/// Init PLC level
		int run();	/// Run PLC Level
    // FIXME API consistency and correctness
    int static digitalRead(int port);
    void static digitalWrite(int port, int val);
    int static analogRead(int port);
    void static analogWrite(int port, int val);
    
    void do_toggle(int);

    // Misc utilities
    char* show_runtime();

    //
		Plc();		/// Ctor
		~Plc();		/// Dtor
};

// *************  *************
