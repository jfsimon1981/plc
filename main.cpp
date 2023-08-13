#include <iostream>
// #include <>
#include "plc.h"
using namespace std;

int main(int argc, char **argv)
{
  Plc plc;
  plc.init();
  plc.run();
	return 0;
}
