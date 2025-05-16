#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define LDRPIN A0

#define LED_VERDE 3
#define LED_AMARELO 5
#define LED_VERMELHO 4
#define BUZZER 6

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float tempSum = 0;
  float humSum = 0;
  int ldrSum = 0;

  // 5 leituras para cada sensor
  for (int i = 0; i < 5; i++) {
    tempSum += dht.readTemperature();
    humSum += dht.readHumidity();
    ldrSum += analogRead(LDRPIN);
    delay(500);
  }

  float temp = tempSum / 5.0;
  float hum = humSum / 5.0;
  int ldrValue = ldrSum / 5;

  // porcentagem do LDR
  int ldrPercentage = map(ldrValue, 0, 1023, 100, 0);

  // Luminosidade
  lcd.clear();
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(BUZZER, LOW);

  lcd.setCursor(0, 1);
  lcd.print("Lum: ");
  lcd.print(ldrPercentage);
  lcd.print("%");

  if (ldrPercentage < 30) {
    digitalWrite(LED_VERDE, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente escuro");
  } else if (ldrPercentage < 70) {
    digitalWrite(LED_AMARELO, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente meia luz");
  } else {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Amb. muito claro");
  }

  delay(5000);

  // Temperatura
  lcd.clear();
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(BUZZER, LOW);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print(" C");

  if (temp >= 10 && temp <= 15) {
    digitalWrite(LED_VERDE, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Temperatura OK");
  } else if (temp < 10) {
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Temp. Baixa");
  } else {
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Temp. Alta");
  }

  delay(5000);

  // Umidade
  lcd.clear();
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(BUZZER, LOW);

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(hum, 1);
  lcd.print(" %");

  if (hum >= 50 && hum <= 70) {
    digitalWrite(LED_VERDE, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Umidade OK");
  } else if (hum < 50) {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Umid. Baixa");
  } else {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Umid. Alta");
  }

  delay(5000);
}
