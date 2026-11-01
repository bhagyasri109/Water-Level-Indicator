#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pot = A0;
int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int buzzer = 8;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int value = analogRead(pot);
  int level = map(value, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Water Level:    ");

  lcd.setCursor(0, 1);
  lcd.print(level);
  lcd.print("%       ");

  if (level < 30) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    noTone(buzzer);
  }
  else if (level < 80) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    noTone(buzzer);
  }
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    tone(buzzer, 1000);
  }

  delay(300);
}