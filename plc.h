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
};
