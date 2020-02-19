#include <nRF24L01.h> // Подключаем файл настроек из библиотеки RF24
#include <RF24.h>     // Подключаем библиотеку для работы с nRF24L01+
RF24 radio(9, 10);    // Создаём объект radio для работы с библиотекой RF24, указывая номера выводов nRF24L01+ (CE, CSN)

#define pin_x A0
#define pin_y A1
#define pin_switch 7

int data[2];

void setup(){
  Serial.begin(9600);
  pinMode(pin_switch, INPUT_PULLUP);
  radio.begin();
  radio.setChannel(100); // Канал приёма данных (от 0 до 127), 2.400 ГГц + аргумент 
  // На одном канале может быть только 1 приёмник и до 6 передатчиков
  radio.setDataRate(RF24_1MBPS); // Cкорость передачи данных (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS)
  radio.setPALevel(RF24_PA_LOW); // Мощность передатчика (RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm)
  radio.openReadingPipe(1, 0x1234567890LL); // Открываем 1 трубу с идентификатором 0x1234567890 для приема данных (на ожном канале может быть открыто до 6 разных труб, которые должны отличаться только последним байтом идентификатора)
}

void loop(){
    data[0] = analogRead(pin_x); // считываем показания Trema слайдера с вывода A1 и записываем их в 0 элемент массива data
    data[1] = analogRead(pin_y); // считываем показания Trema потенциометра с вывода A2 и записываем их в 1 элемент массива data
    radio.write(&data, sizeof(data)); // отправляем данные из массива data указывая сколько байт массива мы хотим отправить
}
