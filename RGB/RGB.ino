/*     ---------------------------------------------------------
 *     |  Experimentation Kit for Arduino Example Code         |
 *     |  CIRC-RGB .: Colourful Light :. (RGB LED)             |
 *     ---------------------------------------------------------
 * 
 * We've blinked an LED and controlled eight in sequence now it's time to 
 * control colour. Using an RGB LED (actual 3 LEDs in a single housing)  
 * we can generate any colour our heart desires.
 *
 * (we'll also use a few programming shortcuts to make the code 
 * more portable/readable)
 */


//RGB LED pins
int ledDigitalOne[] = {10, 11, 9}; //the three digital pins of the digital LED 
                                   //10 = redPin, 11 = greenPin, 9 = bluePin

int ON = 255;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
int OFF = 0;   //Define off as HIGH
int HALF = 128;
int QUARTER = 64;
int EIGHTH = 32;

//Predefined Colors
int RED[] = {ON, OFF, OFF};        
int REDORANGE[] = {ON, EIGHTH, OFF};   
int ORANGE[] = {ON, QUARTER, OFF};      
int ORANGEYELLOW[] = {ON, HALF, OFF};
int YELLOW[] = {ON, ON, OFF};     
int YELLOWGREEN[] = {HALF, ON, OFF};   
int GREEN[] = {OFF, ON, OFF};       
int BLUEGREEN[] = {OFF, ON, QUARTER};   
int BLUE[] = {OFF, OFF, ON};     
int PURPLE[] = {EIGHTH, OFF, HALF}; 
int CYAN[] = {OFF, ON, ON}; 
int MAGENTA[] = {ON, OFF, ON}; 
int WHITE[] = {ON, ON, ON}; 
int BLACK[] = {OFF, OFF, OFF}; 
int PINK[] = {ON, EIGHTH, QUARTER};   
int AQUA[] = {OFF, ON, HALF};  
int HOTPINK[] = {ON, OFF, HALF};   
int LAVENDER[] = {QUARTER, OFF, ON};        
int MYST[] = {QUARTER, EIGHTH, EIGHTH};  

//An Array that stores the predefined colors (allows us to later randomly display a color)
int* COLORS[] = {RED, ORANGE, YELLOW, GREEN, BLUE, CYAN, MAGENTA, WHITE,HOTPINK,PINK,AQUA,LAVENDER,PURPLE,MYST};

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs
  }

  pinMode(8, OUTPUT);
}

void loop(){
  digitalWrite(8,LOW);
/* Example - 1 Set a color
   Set the three LEDs to any predefined color
*/
   //setColor(ledDigitalOne, BLACK);    //Set the color of LED one
  rainbowColors(10,1,0,256);
/* Example - 2 Go through Random Colors
  Set the LEDs to a random color
*/
   //randomColor();
  //delay(500);
}

void randomColor(){
  int rand = random(0, sizeof(COLORS) / 2);  //get a random number within the range of colors
  setColor(ledDigitalOne, COLORS[rand]);  //Set the color of led one to a random color
  delay(1000);
}

void cycleUpColor(int pin, int dly, int stp, int strt, int nd) {
  for(int r = strt; r < nd; r = r+stp) {
    analogWrite(pin, r);
    delay(dly);
  }
}

void cycleDownColor(int pin, int dly, int stp, int strt, int nd) {
  for(int r = strt; r > nd; r = r-stp) {
    analogWrite(pin, r);
    delay(dly);
  }
}

void rainbowColors(int dly, int stp, int strt, int nd) {
  cycleUpColor(10,dly,stp,strt,nd);
  cycleUpColor(11,dly,stp,strt,nd);
  cycleUpColor(9,dly,stp,strt,nd);
  cycleDownColor(10,dly,stp,nd,strt);
  cycleDownColor(11,dly,stp,nd,strt);
  cycleDownColor(9,dly,stp,nd,strt);
  
  cycleUpColor(11,dly,stp,strt,nd);
  cycleUpColor(9,dly,stp,strt,nd);
  cycleUpColor(10,dly,stp,strt,nd);
  cycleDownColor(11,dly,stp,nd,strt);
  cycleDownColor(9,dly,stp,nd,strt);
  cycleDownColor(10,dly,stp,nd,strt);
  
  cycleUpColor(9,dly,stp,strt,nd);
  cycleUpColor(10,dly,stp,strt,nd);
  cycleUpColor(11,dly,stp,strt,nd);
  cycleDownColor(9,dly,stp,nd,strt);
  cycleDownColor(10,dly,stp,nd,strt);
  cycleDownColor(11,dly,stp,nd,strt);
  
  cycleUpColor(10,dly,stp,strt,nd);
  cycleUpColor(9,dly,stp,strt,nd);
  cycleUpColor(11,dly,stp,strt,nd);
  cycleDownColor(10,dly,stp,nd,strt);
  cycleDownColor(9,dly,stp,nd,strt);
  cycleDownColor(11,dly,stp,nd,strt);
  
  cycleUpColor(11,dly,stp,strt,nd);
  cycleUpColor(10,dly,stp,strt,nd);
  cycleUpColor(9,dly,stp,strt,nd);
  cycleDownColor(11,dly,stp,nd,strt);
  cycleDownColor(10,dly,stp,nd,strt);
  cycleDownColor(9,dly,stp,nd,strt);
  
  cycleUpColor(9,dly,stp,strt,nd);
  cycleUpColor(11,dly,stp,strt,nd);
  cycleUpColor(10,dly,stp,strt,nd);
  cycleDownColor(9,dly,stp,nd,strt);
  cycleDownColor(11,dly,stp,nd,strt);
  cycleDownColor(10,dly,stp,nd,strt);
}

/* Sets an led to any color
   led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin)
   color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)
*/
void setColor(int* led, int* color){
 for(int i = 0; i < 3; i++){
   analogWrite(led[i], color[i]);
 }
}

/* A version of setColor that allows for using const boolean colors
*/
void setColor(int* led, const boolean* color){
  boolean tempColor[] = {color[0], color[1], color[2]};
  setColor(led, tempColor);
}
