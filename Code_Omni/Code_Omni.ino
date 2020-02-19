// Code omni
// Version 0.1
// 19.02.2020

#include <AccelStepper.h>      // Подключаем библиотеку для работы с шаговыми двигателями
#include <nRF24L01.h>          // Подключаем файл настроек из библиотеки RF24
#include <RF24.h>              // Подключаем библиотеку для работы с nRF24L01+

RF24 radio(48, 49);            // nRF24L01 (CE, CSN)
int data[2] = {1500, 1500};    // Радио данные. 1500 - невозможное значение
AccelStepper LFW(1, 2, 5);     // Левое переднее колесо
AccelStepper RFW(1, 3, 6);     // Правое переднее колесо
AccelStepper LBW(1, 4, 7);     // Левое заднее колесо
AccelStepper RBW(1, 12, 13);   // Правое заднее колесо

// TODO
// ПРОВЕРИТЬ ПИНЫ!!!!!!!!

int EN = 8;

void setup() {
  Serial.begin(9600);
  LFW.setMaxSpeed(32000);
  RFW.setMaxSpeed(32000);
  LBW.setMaxSpeed(32000);
  RBW.setMaxSpeed(32000);
  LFW.setSpeed(0);
  RFW.setSpeed(0);
  LBW.setSpeed(0);
  RBW.setSpeed(0);
  pinMode(EN, OUTPUT);

  radio.begin();
  radio.setChannel(100); // Канал приёма данных (от 0 до 127), 2.400 ГГц + аргумент 
  // На одном канале может быть только 1 приёмник и до 6 передатчиков
  radio.setDataRate(RF24_1MBPS); // Cкорость передачи данных (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_LOW); // Мощность передатчика (RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm)
  radio.openReadingPipe(1, 0x1234567890LL); // Открываем 1 трубу с идентификатором 0x1234567890 для приема данных (на ожном канале может быть открыто до 6 разных труб, которые должны отличаться только последним байтом идентификатора)
  radio.startListening();
  digitalWrite(EN, LOW); // Разрешаем движение
}

void loop() {
  int x = data[0];
  int y = data[1];
  if (radio.available()) {
    radio.read(&data, sizeof(data));  
    x = data[0];
    y = data[1];
  } 
  else {
    // Пульт должен передавать значения в диапазоне [-441; 583)
    // Начальное положение джойстика (70; 70)
    engineStop();
    x = 1500;
    y = 1500;
  }
  
  if ((x != 1500) && (y != 1500)) {
    if (x<0) {
      if (y<0) strafeBotLeft();
      else if (y>140) strafeTopLeft();
      else strafeLeft();
    }
    else if (x>140) {
      if (y<0) strafeBotRight();
      else if (y>140) strafeTopRight();
      else strafeRight();
    }
    else {
      if (y<0) backward();
      else if (y>140) forward();
      else engineStop();
    }
  }
}
