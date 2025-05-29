// Instalação de Bibliotecas
#include <DHT.h>

// Variáveis
#define trigger 4
#define echo 3
#define dhtpin 7
#define dhtType DHT22
#define led1 9
#define led2 10
#define buzzer 8
int dist = 0;

DHT dht(dhtpin, dhtType);

void setup() {
  // Declarações gerais de OUTPUT, INPUT, etc.
  Serial.begin(9600);
  dht.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

}

void loop() {
  // Loop principal

  // Pegando umidade
  int umi = dht.readHumidity();

  // Configurando tempo Ultrasônico
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Pegando distância
  dist = pulseIn(echo, HIGH);
  dist = dist/58;

  // Colocando uma condição de alerta de enchente
  // Com leds vermelhos e um buzzer
  if (umi > 70  && dist < 100){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
  }

  // delay para depois fazer a medição novamente
  delay(1000);
}

// O projeto poderia ser melhorado com:
// Sensor de chuva
// Boia de nível de água
// Porém não tem esses componentes no Wokwi
