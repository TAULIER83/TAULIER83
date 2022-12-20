#include <Arduino.h>
#include <PZEM004Tv30.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define capteur A0
LiquidCrystal_I2C lcd(0x27, 20, 21);
PZEM004Tv30 pzem(11, 12); // Software Serial pin 8 (RX) & 9 (TX)
PZEM004Tv30 pzem02(10, 8); // Software Serial pin 8 (RX) & 9 (TX)

float valeurcapteur;


int led1 = (22);
int led2 = (24);
int power01;
int power02;


void setup() {
  
  
  Serial.begin(9600);
  Serial.println("Demarage");
  delay(1000);
  Serial.print("J'ai dit que je demmarre");
  lcd.init();
  lcd.backlight();
  delay(1100);
  digitalWrite(led1,HIGH);
  delay(1000);
  digitalWrite(led1,LOW);
  delay(1000);
  digitalWrite(led1,HIGH);
  delay(1000);
  digitalWrite(led1,LOW);
  delay(1000);
  digitalWrite(led2,HIGH);
  delay(1000);
  digitalWrite(led2,LOW);
  delay(1000);
  digitalWrite(led2,HIGH);
  delay(1000);
  digitalWrite(led2,LOW);
  delay(100);

}

 void loop() {
  
  
    valeurcapteur = analogRead(capteur);
    int a = valeurcapteur;
    int b = 6;
    int powert = a * b;
    

    Serial.println("");
    
    Serial.print("puissance théorique : ");
    Serial.print(powert);
    Serial.print(" W");
    Serial.println(" ");
    
    // li la puissance sur les pzem
    float power01 = pzem.power(); // enedis
    float power02 = pzem02.power(); 
    int rest = (powert-power02);
    Serial.print("Puissance enedis : ");
    Serial.print(power01);
    Serial.println(" W");
    
    // maison (power02)
    Serial.print("Puissance maison : ");
    Serial.print(power02);
    Serial.println(" W");
    
   // calcul du rest à consomer
   Serial.print("Rest à conso : ");
   Serial.print(rest);
   Serial.println(" w");
   
   Serial.print("Puissance théorique : ");
   Serial.print(powert);
   Serial.println("w");
   
   
   lcd.clear();
   lcd.setCursor(1, 0);
   lcd.print("PowerT: ");
   lcd.print(powert);
   lcd.setCursor(1, 1);
   lcd.print("Rest : ");
   lcd.print(rest);
   delay(1000);
   
  
  // SI rest a consomer est superieur à 300

     if (power01<10 && rest>300) {
   digitalWrite(led1,HIGH);
   } else {
    digitalWrite(led1&&led2,LOW);

} 
// SI rest a consomer est superieur à 600
     if (power01<10 && rest>600) {
    digitalWrite(led1&&led2,HIGH);
   } else {
    digitalWrite(led2,LOW);
    Serial.print("fin");
    
  }
   
    }
    
   
