  
  #define IRledPin 12
  #define NumIRsignals 96
        
  // This is the code I determined works for my Duraflame heater
  const int buttonPin = 4;
  int buttonState = 0; 
  int IRsignal[] = {
  // ON, OFF (in 10's of microseconds)
    876, 430,
    56, 164,
    54, 162,
    56, 52,
    56, 54,
    54, 164,
    54, 164,
    54, 54,
    54, 54,
    54, 54,
    54, 54,
    54, 54,
    54, 54,
    54, 54,
    56, 52,
    56, 52,
    56, 52,
    56, 52,
    54, 54,
    54, 54,
    54, 54,
    56, 52,
    56, 52,
    56, 52,
    56, 52,
    56, 162,
    56, 162,
    56, 164,
    54, 162,
    56, 164,
    54, 164,
    54, 164,
    54, 164,
    54, 4310,
    876, 214,
    54, 0};
  
  void setup(void) {
    digitalWrite(IRledPin, LOW);   //LED starts "off"
    Serial.begin(9600);            //Initialize Serial port
    pinMode(buttonPin, INPUT);
  }
  
  void loop() {
    char data[6];
    int index = 0;
    buttonState = digitalRead(buttonPin);
    delay(1000);  //Serial input seems to need some kind of short delay or the data gets screwed up.
  
    while (Serial.available() > 0) {            //Loop if there data on the serial line
      if (index < 5) {                          //Make sure we don't overflow
        data[index] = Serial.read();            //Load a character into the string
        index++;                                //Increment the index to get the next character
      }
    }
  
    data[5]='\0';  //Null terminate the string
    
    if (strcmp(data, "POWER") == 0){                //If the Arduino receives the POWER signal...
      Serial.println("SENDING SIGNAL!");
      for (int i = 0; i < NumIRsignals; i+=2) {         //Loop through all of the IR timings
        pulseIR(IRsignal[i]*10);              //Flash IR LED at 38khz for the right amount of time
        delayMicroseconds(IRsignal[i+1]*10);  //Then turn it off for the right amount of time
      }
    }                                         //Otherwise do nothing!
  }
  
  // This function allows us to PWM the IR LED at about 38khz for the sensor
  
  // THIS IS THE LADYADA program! Has been copied
  void pulseIR(long microsecs) {
    // we'll count down from the number of microseconds we are told to wait
   
    cli();  // this turns off any background interrupts
   
    while (microsecs > 0) {
      // 38 kHz is about 13 microseconds high and 13 microseconds low
     digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
     delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
     digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
     delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   
     // so 26 microseconds altogether
     microsecs -= 26;
    }
   
    sei();  // this turns them back on
  }
