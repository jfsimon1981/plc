class Motor {
  private:
    // Monitoring and protections
    bool temperature_monitoring {0};
    int winding_temperature_alarm {105};
    int winding_temperature_trip {125};
    int bearing_temperature_alarm {85};
    int bearing_temperature_trip {90};

    // Control
    bool running {0};
    bool tripped {0};
    bool is_alarm {0};
    bool is_trip {0};
    bool is_brg_alarm {0};
    bool is_brg_trip {0};
    bool is_wdg_alarm {0};
    bool is_wdg_trip {0};

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
}


class Application {
	private:
	public:
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
		Plc();		/// Ctor
		~Plc();		/// Dtor
    void static in(int) {
    };
    void static out(int) {
    };
};
