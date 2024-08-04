#define BUTTON_PIN 21 // GIOP21 pin connected to button
#define LED_PIN1 2  // GIOP2 pin connected to LED (Built in & external) {Recognises if Button is pressed}
#define LED_PIN2 16 // GIOP16 pin connected to LED {Recognises if Automated process is on or off}
#define LED_PIN3 4  // GIOP4 pin connected to LED {Recognises if Automated process is on or off}

#define stepPin 22
#define dirPin 23

void setup() {
  // Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  bool turnedOnLights = false;
  bool automationWasActivated = false;
  
  // Serial.println(buttonState);

  //if button pressed
  if(buttonState == 0){
    digitalWrite(LED_PIN1, HIGH);
    //if automated process is NOT activated
    if(turnedOnLights == false){
      digitalWrite(LED_PIN2, HIGH);
      digitalWrite(LED_PIN3, LOW);
      // Motor script 
      
      digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 800; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(700); 
      }
      automationWasActivated = true;
      turnedOnLights = true;
    }
  }
  //if button not pressed {RESET}
  else if(buttonState == 1){
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN3, HIGH);
    
    if(automationWasActivated = true){
      digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 800; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(700); 
      }
      digitalWrite(LED_PIN2, LOW);
    }
    automationWasActivated = false;
    turnedOnLights = false;
    
  }

  
}
