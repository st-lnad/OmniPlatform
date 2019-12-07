#include <AccelStepper.h>

AccelStepper Xaxis(1, 2, 5); // pin 3 = step, pin 6 = direction
AccelStepper Yaxis(1, 3, 6); // pin 4 = step, pin 7 = direction
AccelStepper Zaxis(1, 4, 7); // pin 5 = step, pin 8 = direction
AccelStepper Aaxis(1, 12, 13); // pin 5 = step, pin 8 = direction

int EN = 8;
int TIME = 3;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  Xaxis.setMaxSpeed(2000);
  Yaxis.setMaxSpeed(2000);
  Zaxis.setMaxSpeed(2000);
  Aaxis.setMaxSpeed(2000);
  Xaxis.setSpeed(500);
  Yaxis.setSpeed(500);
  Zaxis.setSpeed(-500);
  Aaxis.setSpeed(-500);
  pinMode(EN, OUTPUT); 
}

void loop() {  
  int x = analogRead(A0);
  int y = analogRead(A1);
  if ( x > 700 && x <= 1023 && y > 323 && y <= 700) Serial.println("forward");
  else if (x >= 0 && x < 323 && y > 323 && y <= 700) Serial.println("backward");
  else if (y > 700 && y <= 1023 && x > 323 && x <= 700) Serial.println("strafeRight");
  else if (y >= 0 && y < 323 && x > 323 && x <= 700) Serial.println("strafeLeft");
  else if (x > 700 && x <= 1023 && y >= 0 && y < 323) Serial.println("strafeTopLeft");
  else if (x > 700 && x <= 1023 && y > 700 && y <= 1023) Serial.println("strafeTopRight");
  else if (x >= 0 && x < 323 && y > 700 && y <= 1023) Serial.println("strafeBotRight");
  else if (x >= 0 && x < 323 && y >= 0 && y < 323) Serial.println("strafeBotLeft");
  else Serial.println("allStop");
}

void move_frwd() {
  Xaxis.setSpeed(500);
  Yaxis.setSpeed(500);
  Zaxis.setSpeed(-500);
  Aaxis.setSpeed(-500);
  int cur = millis();
  while (millis() < cur + 100) {
    Serial.println("Move forward");
    Xaxis.runSpeed();
    Yaxis.runSpeed();
    Zaxis.runSpeed();
    Aaxis.runSpeed();
  }
}

void move_back() {
  Xaxis.setSpeed(-500);
  Yaxis.setSpeed(-500);
  Zaxis.setSpeed(500);
  Aaxis.setSpeed(500);
  int cur = millis();
  while (millis() < cur + 100) {
    Serial.println("Move back");
    Xaxis.runSpeed();
    Yaxis.runSpeed();
    Zaxis.runSpeed();
    Aaxis.runSpeed();
  }
}

void extra_stop(){
  digitalWrite(EN, HIGH);
}

void stop_drivers() {
  Xaxis.setSpeed(0);
  Yaxis.setSpeed(0);
  Zaxis.setSpeed(0);
  Aaxis.setSpeed(0);
}
