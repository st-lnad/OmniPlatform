int X_STEP = 2;
int X_DIR = 5;

int Y_STEP = 3;
int Y_DIR = 6;

int Z_STEP = 4;
int Z_DIR = 7;

int A_STEP = 12;
int A_DIR = 13;

int EN = 8;
int TIME = 3;

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
  stop_all();
} 

void move_frwd(int time) {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, LOW);
  digitalWrite(Y_DIR, LOW);
  digitalWrite(Z_DIR, LOW);
  digitalWrite(A_DIR, LOW);
  while (time!=0){
    digitalWrite(X_STEP, HIGH);
    digitalWrite(Y_STEP, HIGH);
    digitalWrite(Z_STEP, HIGH);
    digitalWrite(A_STEP, HIGH);
    delay(10.2);
    
    digitalWrite(X_STEP, LOW);
    digitalWrite(Y_STEP, LOW);
    digitalWrite(Z_STEP, LOW);
    digitalWrite(A_STEP, LOW);
    delay(10.2);
    time--;
  }
}

void stop_all(){
  digitalWrite(EN, HIGH);
}
