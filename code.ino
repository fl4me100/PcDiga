#include <LiquidCrystal.h>
#include <Adafruit_LiquidCrystal.h>

int senha = 0;
int atendidos = 0;
int tempo=0;
Adafruit_LiquidCrystal lcd_1(0x20);
Adafruit_LiquidCrystal lcd_2(0x21);

void setup()
{
  lcd_1.begin(16, 2);
  lcd_2.begin(16, 2);
  delay(1000);
  
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  lcd_1.print("PcDiga");
  lcd_1.setCursor(0,1);
  lcd_1.print("Retire Senha!");
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(3, LOW);
}

void loop()
{
  
  if(digitalRead(5)==LOW){
    tone(11, 240);
    delay(500);
    noTone(11);
    delay(100);
    noTone(11);
    lcd_1.clear();
    lcd_1.print("Senha: ");
    lcd_1.print(senha);
    lcd_1.setCursor(0,1);
    lcd_1.print("Espera (min): ");
    tempo = 5 * (senha-atendidos);
    lcd_1.print(tempo);
    senha++;
    digitalWrite(3, HIGH);
    digitalWrite(9, LOW);
    delay(3000);
    lcd_1.clear();
    lcd_1.print("PcDiga");
  lcd_1.setCursor(0,1);
  lcd_1.print("Retire Senha!");
  }
  if(senha>atendidos){
  if(digitalRead(6)==LOW){
    atendidos++;
    tone(11, 150);
    delay(100);
    noTone(11);
    lcd_2.clear();
    lcd_2.print("Proximo Cliente");
    lcd_2.setCursor(0,1);
    lcd_2.print("Senha: ");
    lcd_2.print(atendidos);
    digitalWrite(3, LOW);
    delay(1000);
    digitalWrite(9, HIGH);
    delay(3000);
    digitalWrite(9, LOW);
    delay(1000);
    digitalWrite(3, HIGH);
  }
  }
}
