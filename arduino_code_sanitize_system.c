/*
 * Automated Sanitize System
 */
 
int relayPin = 12;                // choose the pin for the Relay Pin

int inputPin = 2;               // choose the input pin (for PIR sensor)
int inputPin2 = 3;               // choose the input pin (for PIR sensor 02)

int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int val2 = 0;                    // variable for reading the pin status

 
void setup() {
  pinMode(relayPin, OUTPUT);      // declare Relay as output
  pinMode(inputPin, INPUT);     // declare PIR sensor as input
  pinMode(inputPin2, INPUT);  
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  val2 = digitalRead(inputPin2);  // read input value
  if (val == HIGH || val2 == HIGH) {            // check if the input is HIGH
    digitalWrite(relayPin, HIGH);  // turn Relay ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Sanitization Processing");
      // 15 sec delay
      delay(15000);
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(relayPin, 0); // turn Relay OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Sanitization Completed");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
}
