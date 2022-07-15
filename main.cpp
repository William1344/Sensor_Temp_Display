#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#include <Wire.h>

//define pinos do sensor DHT11
#define DHT_PIN A1
#define DHT_TYPE DHT11

//instancia o sensor DHT11
DHT dht(DHT_PIN, DHT_TYPE);
//instancia o LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("DHT11");
  lcd.setCursor(0, 1);
  lcd.print("Sensor init");
  delay(5000);
}

void loop() {
  float temp  = dht.readTemperature();
  float hum   = dht.readHumidity();
  if(isnan(temp) || isnan(hum)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro de leitura");
    lcd.setCursor(0, 1);
    lcd.print("Tente novamente");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(hum);
    lcd.print("%");
  }
  delay(15000);
}