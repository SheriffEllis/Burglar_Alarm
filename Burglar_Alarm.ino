// instantiating controller object
Controller controller(int armed_LED_pin, int triggered_LED_pin, int loud_buzz_pin, int quiet_buzz_pin, int solenoid_pin, int magswitch_pin, int PIR_pin);

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
    PinHandler()
    {
      // set default PIN to 1234
      stored_pin = 1234;
    }
    PinHandler(int pin)
    {
      stored_pin = pin;
    }
    bool verifyPin(int pin)
    {
      return stored_pin == pin;
    }
    void setPin(int pin)
    {
      stored_pin = pin;
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
      io_pin = output_pin;
      state = false;
      enabled = true;
      pinMode(io_pin, OUTPUT);
    }
    void setState(bool state){
      digitalWrite(io_pin, state);
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
    void pushQueue()
    {
    int i, len = 50;
    for (i = 0; i < len; i++)
      {
       events[i+1].event_type =         
       events[i].event_type;
       events[i+1].timestamp =           
       events[i].timestamp;
      }
    }
  public:
    Logger(){
      logEvent(event_type);
      printLog();
      pushQueue();  
    }
    void logEvent(int event_type){
      int i = 0;
      events[i].event_type = event_type;
      events[i].timestamp = millis() * 1000;
      i++;
    }
    void printLog(){
    int i, len = 50;
    for(i = 0 ; i< len ; i++)
      {
        cout << events[i].timestamp << " : " << events[i].event_type  << endl;
      }
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
      armed_LED.setState(1); 
      solenoid.close();
    }
    void triggerAlarm(){
      
    }
    void resetAlarm(){
      
    }
    void sendAlert(int event_type){
      logEvent(event_type);
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
      int newPIN;
      int choice;
      // turn LEDs Off
      armed_LED.setState(0);
      triggered_LED.setState(0);

      do{
        Serial.println("System unarmed - enter PIN");
        newPIN = Serial.read();
        if(!pin_handler.verifyPin(newPIN)){
          Serial.println("Incorrect PIN");
        }
      }while(!pin_handler.verifyPin(newPIN))
      do{
        Serial.print("Choose an option:");
        Serial.println("\t 0 - go back");  
        Serial.println("\t 1 - arm alarm");
        Serial.println("\t 2 - check sensors");
        Serial.println("\t 3 - system settings");
        choice = Serial.read()
      } while((choice<0)||(choice>4))

      // go back - doesnt loop to start yet, the others - work in progress
        
      // arm alarm
      if(choice == 1){
        Serial.println("Starting timer.");
        for(int i = 0; i < 60: i++){
          Serial.print("Seconds left: ");
          Serial.println(60-i);
          buzzer.pulsate();  // buzzer pulse (should be before for loop?)
          delay(1000);
        }
        armAlarm();
        // waiting for the sensor to be triggered
        do{
          // read sensors
          
        }while()  // while magnetic swith and PIR LOW
        // 20 seconds to disarm the alarm
        do{
          Serial.println"Enter PIN to cancel the alarm");
          newPIN = Serial.read()    // it will just wait for input - have to figure out timer
          
        }while((timer > 0)&&(pin_handler.getTriesLeft() > 0)&&(!pin_handler.verifyPin(newPIN)))
      }
      // check sensors
      if(choice == 2){
        
      }
      // system settings
      if(choice == 3){
        
      }
        
    } 
    void updateTimers(){
      
    }
};

void setup() {
  pinMode(led, OUTPUT);          // initalize LED as an output
  pinMode(sensor, INPUT);        // initialize sensor as an input
  Serial.begin(9600);            // initialize serial
  pinMode(buzzer, OUTPUT);        // Set buzzer - pin 5 as an output
  pinMode(slideSwitch, OUTPUT);  // initalize switch as an output
}

void loop(){
  val = digitalRead(sensor);               // read sensor value
  switchState = digitalRead(slideSwitch);  // read switch state 
  Serial.print("Magnetic Switch: ");
  Serial.println(switchState);
  
  if ((val == HIGH)||(switchState == HIGH))        // check if the sensor is HIGH
  {
    digitalWrite(led, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds
    tone(buzzer, 1000);        // Send 1KHz sound signal...
    delay(1000);               // ...for 1 sec
    noTone(buzzer);            // Stop sound...
    delay(1000);               // ...for 1sec
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
