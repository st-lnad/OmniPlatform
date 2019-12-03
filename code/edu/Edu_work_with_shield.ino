int X_STEP = 2;
int X_DIR = 5;
int EN = 8;
int TIME = 3;

void setup() 
{ 
pinMode(X_DIR, OUTPUT); 
pinMode(X_STEP, OUTPUT); 
pinMode(EN, OUTPUT); 
 
} 

void loop() {
  digitalWrite(EN, LOW);
  digitalWrite(X_DIR, HIGH);
  
  digitalWrite(X_STEP, HIGH);
  delay(TIME);
  
  digitalWrite(X_STEP, LOW);
  delay(TIME);
} 
