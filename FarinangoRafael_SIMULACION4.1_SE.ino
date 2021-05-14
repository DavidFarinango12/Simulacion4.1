/*
 *CAPITULO IV: PERIFERICOS ESPECIALES
 *CODIGO 14: CONVERSORES ANALOGO DIGITALES Y PWM
 *OBJETIVO: REALIZAR LECTURAS DEL CONVERSOR A-D PARA DETERMIAR LA VELOCIDAD DE UN MOTOR EN DC
 *NOMBRE: RAFAEL FARINANGO
 *FUNCIONES:  analogRead(conversor) A0 - A5
 *            analogWrite(pin,dutty) pin: pines con ~ , dutty: 0 - 255
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);
int conversor;
float voltaje;
int dutty;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  conversor=analogRead(A0);
  voltaje=(conversor*5.0)/1023;
  dutty=conversor/4;
  analogWrite(11,dutty);
  lcd.setCursor(0,0);
  lcd.print("CAD:");
  lcd.setCursor(6,0);
  lcd.print(conversor);
  lcd.setCursor(0,1);
  lcd.print("V:");
  lcd.setCursor(3,1);
  lcd.print(voltaje);
  lcd.setCursor(9,1);
  lcd.print("PWM:");
  lcd.setCursor(13,1);
  lcd.print((dutty*100)/255);
  delay(300);
  lcd.clear();
}
