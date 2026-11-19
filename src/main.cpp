#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

DHT dht(4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // đổi địa chỉ nếu cần

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Loi doc DHT11!  ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Nhiet do: ");
    lcd.print(t, 1);
    lcd.print((char)223);  // ký hiệu độ
    lcd.print("C ");

    lcd.setCursor(0, 1);
    lcd.print("Do am: ");
    lcd.print(h, 0);
    lcd.print("%   ");
  }
  delay(2000);
}