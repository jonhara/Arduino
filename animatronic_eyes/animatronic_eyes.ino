/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int rnd;
int mxSrv = 120;
int mnSrv = 20;
int hfSrv = 70;
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void sweep() 
{                                // in steps of 1 degree 
  for(pos = mnSrv; pos <= mxSrv; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
  delay(1000);
  for(pos = mxSrv; pos>=mnSrv; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
  delay(1000); 
} 

void suddenstraight() 
{       
  myservo.write(hfSrv);
  delay(3000);          
  for(pos = hfSrv; pos>=mnSrv; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
}


void suddenright() 
{       
  myservo.write(mxSrv);
  delay(3000);          
  for(pos = mxSrv; pos>=mnSrv; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(10);                       // waits 15ms for the servo to reach the position 
  }  
}

void crazyEyes()
{
  myservo.write(90);
  delay(150);
  myservo.write(45);
  delay(150);
  myservo.write(90);
  delay(150);
  myservo.write(45);
  delay(150);
}

void dartingEyes()
{
  myservo.write(mxSrv);
  delay(400);
  myservo.write(mnSrv);
  delay(400);
  myservo.write(mxSrv);
  delay(400);
  myservo.write(mnSrv);
  delay(400);
}

void loop()
{
  //myservo.write(0);
  randomProg();
}

void randomProg() {
  rnd = random(6);

  if (rnd == 0) {
    sweep();
  }
  else if (rnd == 1) {
    suddenstraight();
  }
  else if (rnd == 2) {
    suddenright();
  }
  else if (rnd == 3) {
    crazyEyes();
  }
  else if (rnd == 4) {
    dartingEyes();
  }
  else {
    delay(1000); 
  }
  delay(1000); 
}
    
