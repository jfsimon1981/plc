class Timer {
  private:
    
  public:

    bool is_running();
    int value_s();

    void start();
    void start(int);
    void stop();
    void reset();

    Timer();
    ~Timer();
};

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

class Plc;

class Application {
	private:
	public:
    Plc* plc {0};
		int init();	/// Main customer Application initialisation
		int loop();	/// Main customer application loop
		Application();	/// Ctor
		~Application();	/// Dtor
};

class Plc {
	private:
		Application application;
	public:
		int init();	/// Init PLC level
		int run();	/// Run PLC Level
    //
    int static digitalRead(int port);
    void static digitalWrite(int port, int val);
    int static analogRead(int port);
    void static analogWrite(int port, int val);
    //
		Plc();		/// Ctor
		~Plc();		/// Dtor
};
