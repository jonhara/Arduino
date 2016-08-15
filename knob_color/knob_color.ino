#include <Servo.h>
int ledDigitalOne[] = {10, 11, 9}; //the three digital pins of the digital LED 
                                   //10 = redPin, 11 = greenPin, 9 = bluePin
int ledRed[] =    {0,255,255,255,0  ,0  ,0  ,255};
int ledGreen[] =  {0,255,0  ,0  ,255,0  ,255,255};
int ledBlue[] =   {0,0  ,255,0  ,0  ,255,255,255};
int potpin = 0;  // analog pin used to connect the potentiometer
int potval;    // variable to read the value from the analog pin
int val;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
Servo myservo;  // create servo object to control a servo

void setup(){
  myservo.attach(7); 
  
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(potval, 0, 1023, 0, 7);
  val2 = map(potval, 0, 1023, 0, 180);

  //if (val==0) {val2=0;}

  analogWrite(11, ledGreen[val]);
  analogWrite(10, ledRed[val]);
  analogWrite(9, ledBlue[val]);
  myservo.write(val2);  
  delay(15);
}
