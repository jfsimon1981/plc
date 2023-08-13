#include "plc.h"

#include <iostream>
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
	cout << "." << flush;
	return 0;
}

