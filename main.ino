#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  
  Serial.begin(9600);
  Serial.println("Sistem Lampu Lalu Lintas Dimulai");
}

void countdown(int duration, const char* message) {
  for (int i = duration; i > 0; i--) {
    Serial.print(message);
    Serial.print(" dalam ");
    Serial.print(i);
    Serial.println(" detik...");
    delay(1000); 
  }
}

void loop() {
  lcd.setCursor(4, 0); 
  lcd.print("BERHENTI!");
  Serial.println("Lampu Merah: BERHENTI!");
  digitalWrite(2, HIGH);
  countdown(11, "Lampu Merah");
  digitalWrite(2, LOW);
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print("BERSIAP JALAN");
  Serial.println("Lampu Kuning: BERSIAP JALAN");
  digitalWrite(3, HIGH);
  countdown(1, "Lampu Kuning");
  digitalWrite(3, LOW);
  lcd.clear();

  lcd.setCursor(6, 0); 
  lcd.print("JALAN!");
  Serial.println("Lampu Hijau: JALAN!");
  digitalWrite(4, HIGH);
  countdown(7, "Lampu Hijau");
  digitalWrite(4, LOW);

  Serial.println("Lampu Hijau Berkedip: Bersiap untuk berhenti");
  for (int i = 0; i < 4; i++) {
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
  }
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("BERSIAP STOP!");
  Serial.println("Lampu Kuning: BERSIAP STOP");
  digitalWrite(3, HIGH);
  countdown(1, "Lampu Kuning");
  digitalWrite(3, LOW);
  lcd.clear();
}
