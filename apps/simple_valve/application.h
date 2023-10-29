// User application
#include "object_library.h"


// We just use the default implementation

enum States::Valves {close,open,closing,opening,idle};
class Valves : public Generic_valves {}; 
class Tanks : public Generic_tanks {};
