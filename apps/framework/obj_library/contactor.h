namespace Plc {

class Contactors {
  private:
    enum State {undefined, open, close};
    State state {undefined};
  public:
    virtual void open();
    virtual void close();
    virtual int is_open();
    virtual int is_close();
};
  
}
