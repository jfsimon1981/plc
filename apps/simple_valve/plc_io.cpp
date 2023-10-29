/* 
 * This file contains IO Requests to Physical IO mapping
 * We abstract away the wiring.
 */

// Digital Outputs

// Valve V1

void DO::contactor_k1_close()    {
  /* if (!DO::contactor_k2_is_open() // Safety */
    DO::write(ADR_01, DO_01,1)
}
void DO::contactor_k1_open()     {DO::write(ADR_01, DO_01,0);}
void DO::contactor_k2_close()    {
  /* if (!DO::contactor_k1_is_open() // Safety */
    DO::write(ADR_01, DO_02,1);
}
void DO::contactor_k2_open()     {DO::write(ADR_01, DO_02,0);}

// Pump P1
static void DO::contactor_k3_close() {DO::write(ADR_01, DO_03,1);}
static void DO::contactor_k3_open()  {DO::write(ADR_01, DO_03,1);}

// Pump P2
static void DO::contactor_k4_close() {DO::write(ADR_01, DO_04,1);}
static void DO::contactor_k4_open()  {DO::write(ADR_01, DO_04,1);}

// Digital Inputs

int DI::valve_1_is_open()           {return DI::read(ADR_02, DI_01,0);}
int DI::valve_1_is_closed()         {return DI::read(ADR_02, DI_02,0);}

int DI::tank_1_is_full()            {return DI::read(ADR_02, DI_03,0);}
int DI::tank_1_is_empty()           {return DI::read(ADR_02, DI_04,0);}

// Implementers notes

/*
 * For safety assurance, implement contactors as a class with following methods:
 * 
 * close
 *  - open()
 *  - is_closed()
 *  - is_open()
 *  - init() (default open)
 * 
 */
