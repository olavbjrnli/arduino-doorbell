int buttonPin = 1;    
int speaker = 3;
int ledPin = 2;

int buttonState = 0;       
String buttonClick = "Someone just rang your doorbell";

/* Class made with help from the arduino library examples 
    02. Digital > Button and 02. Digital > toneMelody  */
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  /* This checks if button is pressed. If pressed, buttonstate = HIGH.
    Particle.publish will send a message using the IFTTT app to your phone. 
    Will also play a doorbell sound and light a green led. 
  
  */
  if (buttonState == HIGH) {
     Particle.publish("At_Door", "Rang");
     delay(100);
     digitalWrite(ledPin, HIGH);
     tone(speaker, 660);
     delay(700);
     tone(speaker, 550);
     delay(700);
     tone(speaker, 440);
     delay(700);
     buttonState == LOW;
  } else {
     noTone(speaker);
     digitalWrite(ledPin, LOW);
  
  }
  
}