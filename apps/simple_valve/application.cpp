// Valves

Valves v1;

void v1::open() {
  DO::contactor_k2.open();
  DO::contactor_k1_close();
}
void v1::close() {
  DO::contactor_k1_open();
  DO::contactor_k2_close();
}
void v1::stop() {
  DO::contactor_k1_open();
  DO::contactor_k2_open();
}
int v1::is_open() {return DI::valve_1_is_open();}
int v1::is_close() {return DI::valve_1_is_closed();}

// Tanks

void Tank::fill() {}
void Tank::stop() {}
int Tank::is_full() {return DI::tank_1_is_full();}
int Tank::is_empty() {return DI::tank_1_is_empty();}

// Main

int main() {

  v1

}
