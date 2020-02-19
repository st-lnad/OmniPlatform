#define SPEED 10000

// Код предполагает, что: 
// LFW "отклонено" влево;
// RFW "отклонено" вправо;
// LBW "отклонено" вправо;
// RBW "отклонено" влево.

void forward() {
  LFW.setSpeed(SPEED);
  RFW.setSpeed(-SPEED);
  LBW.setSpeed(SPEED);
  RBW.setSpeed(-SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}

void backward() {
  LFW.setSpeed(-SPEED);
  RFW.setSpeed(SPEED);
  LBW.setSpeed(-SPEED);
  RBW.setSpeed(SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}

void strafeRight() {
  LFW.setSpeed(-SPEED);
  RFW.setSpeed(-SPEED);
  LBW.setSpeed(SPEED);
  RBW.setSpeed(SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
void strafeLeft() {
  LFW.setSpeed(SPEED);
  RFW.setSpeed(-SPEED);
  LBW.setSpeed(-SPEED);
  RBW.setSpeed(-SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
void strafeTopLeft() {
  LFW.setSpeed(SPEED);
  RFW.setSpeed(0);
  LBW.setSpeed(0);
  RBW.setSpeed(-SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
void strafeTopRight() {
  LFW.setSpeed(0);
  RFW.setSpeed(-SPEED);
  LBW.setSpeed(SPEED);
  RBW.setSpeed(0);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
void strafeBotRight() {
  LFW.setSpeed(-SPEED);
  RFW.setSpeed(0);
  LBW.setSpeed(0);
  RBW.setSpeed(SPEED);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
void strafeBotLeft() {
  LFW.setSpeed(0);
  RFW.setSpeed(SPEED);
  LBW.setSpeed(-SPEED);
  RBW.setSpeed(0);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}

void extra_stop() {
  digitalWrite(EN, HIGH);
}

void engineStop() {
  LFW.setSpeed(0);
  RFW.setSpeed(0);
  LBW.setSpeed(0);
  RBW.setSpeed(0);
  LFW.runSpeed();
  RFW.runSpeed();
  LBW.runSpeed();
  RBW.runSpeed();
}
