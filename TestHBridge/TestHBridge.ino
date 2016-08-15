#define RtFwd 9
#define RtBkw 8
#define LfFwd 11
#define LfBkw 10
#define trigPin 3
#define echoPin 2
#define buzzer 7
#define RdLt 6
#define GrnLt 5

void setup() {
  // put your setup code here, to run once:
  //Right DC Motor
  pinMode(RtFwd, OUTPUT);
  pinMode(RtBkw, OUTPUT);
  //Left DC Motor
  pinMode(LfFwd, OUTPUT);
  pinMode(LfBkw, OUTPUT);
  //Distance Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long scanDistance;
  scanDistance = scan();

  if (scanDistance < 50) {
    digitalWrite(GrnLt, LOW);
    digitalWrite(RdLt, HIGH);
    moveStop();
    delay(500);
    tone(buzzer, 262, 1000);
    delay(1300);
    noTone(buzzer);
    moveLeft();
    delay(200);
    moveStop();
    delay(500);
  }
  else {
    digitalWrite(GrnLt, HIGH);
    digitalWrite(RdLt, LOW);
    moveForward();
  }
}

void moveForward() {
  digitalWrite(LfFwd, HIGH);
  digitalWrite(LfBkw, LOW);
  digitalWrite(RtFwd, HIGH);
  digitalWrite(RtBkw, LOW);
}

void moveBackward() {
  digitalWrite(LfFwd, LOW);
  digitalWrite(LfBkw, HIGH);
  digitalWrite(RtFwd, LOW);
  digitalWrite(RtBkw, HIGH);
}

void moveStop() {
  digitalWrite(LfFwd, LOW);
  digitalWrite(LfBkw, LOW);
  digitalWrite(RtFwd, LOW);
  digitalWrite(RtBkw, LOW);
}

void moveLeft() {
  digitalWrite(LfFwd, HIGH);
  digitalWrite(LfBkw, LOW);
  digitalWrite(RtFwd, LOW);
  digitalWrite(RtBkw, HIGH);
}

void moveRight() {
  digitalWrite(LfFwd, LOW);
  digitalWrite(LfBkw, HIGH);
  digitalWrite(RtFwd, HIGH);
  digitalWrite(RtBkw, LOW);
}

long scan() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}
