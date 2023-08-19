#include <stdio.h>
// #include <>
#include "plc.h"
using namespace std;

/*!
 * \section HowTo make a PLC program
 * \subsection application.cpp Application
Write Init and Loop functions:
 * * init() in Application class, runs once
 * * loop() in Application class, runs continusouly
 * \subsection main.cpp main()
Instanciate Plc in main() and run ini() and run()
 * * Instanciate Plc class
 * * Call init()
 * * Call run()
 */


/// Main program is the PLC/MCU entry point
int main(int argc, char **argv)
{
  Plc plc;
  plc.init();
  plc.run();
	return 0;
}
