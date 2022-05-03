
class KeyPad{
  public:
    int getPin(){
      
    }
    int getChoice(String choices[]){
      
    }
};

class FacialRecognition{
  private:
    bool is_setup;
    bool pendResponse(long timeout){
      
    }
  public:
    FacialRecognition(){
      
    }
    void setup(){
      
    }
    bool getIsSetup(){
      
    }
    bool addFace(){
      
    }
    bool checkFace(){
      
    }
};



class PinHandler{
  private:
    int stored_pin;
    int tries_left;
  public:
    PinHandler(){
      
    }
    PinHandler(int pin){
      
    }
    bool verifyPin(int pin){
      
    }
    void setPin(int pin){

    }
};

class Peripheral{
  protected:
    bool state;
    int io_pin;
  public:
    bool enabled;
    bool getState(){
      
    }
};

class LED: public Peripheral{
  public:
    LED(int output_pin){
      
    }
    void setState(bool state){
      
    }
};

class PIR: public Peripheral{
  private:
    long time_of_last_measure;
  public:
    PIR(int input_pin){
      
    }
    bool measure(){
      
    }
};

class MagneticSwitch: public Peripheral{
  public:
    MagneticSwitch(int input_pin){
      
    }
    bool measure(){
      
    }
};

class Buzzer: public Peripheral{
  private:
    static const long TIMEOUT;
    int tone_freq;
    int pulse_freq;
    long duration;
    long start_time;
  public:
    Buzzer(int loud_pin, int quiet_pin){
      
    }
    void setTone(int tone_freq){
      
    }
    void setPulseFreq(int pulse_freq){
      
    }
    void pulsate(long duration, bool is_quiet){
      
    }
    void stop(){
      
    }
    void update(){
      
    }
};

class Solenoid: public Peripheral{
  private:
    long duration;
    long start_time;
  public:
    Solenoid(int output_pin){
      
    }
    void open(int duration){
      
    }
    void update(){
      
    }
    void close(){
      
    }
};

struct EventTime{
  int event_type;
  long timestamp;
};

class Logger{
  private:
    EventTime events[50];
    void pushQueue(){
    
    }
  public:
    Logger(){
  
    }
    void logEvent(int event_type){
  
    }
    void printLog(){
  
    }
};

class Controller{
  private:
    int system_state;
    KeyPad keypad;
    FacialRecognition facial_recognition;
    PinHandler pin_handler;
    Logger logger;
    LED armed_LED, triggered_LED;
    Buzzer buzzer;
    Solenoid solenoid;
    MagneticSwitch magnetic_switch;
    PIR pir;
    
    void armAlarm(){
      
    }
    void triggerAlarm(){
      
    }
    void resetAlarm(){
      
    }
    void sendAlert(int event_type){
      
    }
  public:
    Controller(int armed_LED_pin, int triggered_LED_pin, int loud_buzz_pin, 
      int quiet_buzz_pin, int solenoid_pin, int magswitch_pin, int PIR_pin):
        armed_LED(armed_LED_pin),
        triggered_LED(triggered_LED_pin),
        buzzer(loud_buzz_pin, quiet_buzz_pin),
        solenoid(solenoid_pin),
        magnetic_switch(magswitch_pin),
        pir(PIR_pin)
    {
      system_state = 0;
    }
    
    void proccessSysState(){

    }
    void updateTimers(){
      
    }
};

void setup() {

}

void loop(){
  
}
