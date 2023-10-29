/* 
 * This file contains IO Requests to Physical IO mapping
 * We abstract away the wiring.
 */

// Digital Outputs

class DO {
  private:
    static void write();
  public:
    // Valve V1
    static void contactor_k1_close();
    static void contactor_k1_open();
    // Valve V1
    static void contactor_k2_close();
    static void contactor_k2_open();
    // Pump P1
    static void contactor_k3_close();
    static void contactor_k3_open();
    // Pump P2
    static void contactor_k4_close();
    static void contactor_k4_open();
};

// Digital Inputs

class DI {
  private:
    static int read();
  public:

    // Valve V1
    static int valve_1_is_open();
    static int valve_1_is_closed();

    // Tank
    static int tank_1_is_full();
    static int tank_1_is_empty();
};
