// left back
int X_STEP = 2;
int X_DIR = 5;

// left forw
int Y_STEP = 3;
int Y_DIR = 6;

// right back
int Z_STEP = 4;
int Z_DIR = 7;

// right forw
int A_STEP = 12;
int A_DIR = 13;

int EN = 8;
int TIME = 1;

void setup()
{
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STEP, OUTPUT);

  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STEP, OUTPUT);

  pinMode(Z_DIR, OUTPUT);
  pinMode(Z_STEP, OUTPUT);

  pinMode(A_DIR, OUTPUT);
  pinMode(A_STEP, OUTPUT);

  pinMode(EN, OUTPUT);

}

void loop() {
  forward(1000);
  backward(1000);
  left(1000);
  right(1000);
  stop_all();
}

void forward(int time) {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, LOW);
  digitalWrite(Y_DIR, LOW);
  digitalWrite(Z_DIR, HIGH);
  digitalWrite(A_DIR, HIGH);
  while (time != 0) {
    digitalWrite(X_STEP, HIGH);
    digitalWrite(Y_STEP, HIGH);
    digitalWrite(Z_STEP, HIGH);
    digitalWrite(A_STEP, HIGH);
    delay(TIME);

    digitalWrite(X_STEP, LOW);
    digitalWrite(Y_STEP, LOW);
    digitalWrite(Z_STEP, LOW);
    digitalWrite(A_STEP, LOW);
    delay(TIME);
    time--;
  }
}

void backward(int time) {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, HIGH);
  digitalWrite(Y_DIR, HIGH);
  digitalWrite(Z_DIR, LOW);
  digitalWrite(A_DIR, LOW);
  while (time != 0) {
    digitalWrite(X_STEP, HIGH);
    digitalWrite(Y_STEP, HIGH);
    digitalWrite(Z_STEP, HIGH);
    digitalWrite(A_STEP, HIGH);
    delay(TIME);

    digitalWrite(X_STEP, LOW);
    digitalWrite(Y_STEP, LOW);
    digitalWrite(Z_STEP, LOW);
    digitalWrite(A_STEP, LOW);
    delay(TIME);
    time--;
  }
}

void left(int time) {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, LOW);
  digitalWrite(Y_DIR, HIGH);
  digitalWrite(Z_DIR, LOW);
  digitalWrite(A_DIR, HIGH);
  while (time != 0) {
    digitalWrite(X_STEP, HIGH);
    digitalWrite(Y_STEP, HIGH);
    digitalWrite(Z_STEP, HIGH);
    digitalWrite(A_STEP, HIGH);
    delay(TIME);

    digitalWrite(X_STEP, LOW);
    digitalWrite(Y_STEP, LOW);
    digitalWrite(Z_STEP, LOW);
    digitalWrite(A_STEP, LOW);
    delay(TIME);
    time--;
  }
}

void right(int time) {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, HIGH);
  digitalWrite(Y_DIR, LOW);
  digitalWrite(Z_DIR, HIGH);
  digitalWrite(A_DIR, LOW);
  while (time != 0) {
    digitalWrite(X_STEP, HIGH);
    digitalWrite(Y_STEP, HIGH);
    digitalWrite(Z_STEP, HIGH);
    digitalWrite(A_STEP, HIGH);
    delay(TIME);

    digitalWrite(X_STEP, LOW);
    digitalWrite(Y_STEP, LOW);
    digitalWrite(Z_STEP, LOW);
    digitalWrite(A_STEP, LOW);
    delay(TIME);
    time--;
  }
}

void stop_all() {
  digitalWrite(EN, HIGH);
}
