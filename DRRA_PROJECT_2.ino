// Created by Barbu Vulc.
// LCD I2C library:
#include <LiquidCrystal_I2C.h>

// LCD I2C address 0x27, 16 column and 2 rows!
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD, the LEDs, and Serial Monitor:
  lcd.init();
  lcd.backlight();
  pinMode(2, OUTPUT); // Red LED
  pinMode(3, OUTPUT); // Yellow LED
  pinMode(4, OUTPUT); // Green LED

  Serial.begin(9600); // Initialize Serial Monitor
  Serial.println("Sistem Lampu Lalu Lintas Dimulai");
}

// Function to display countdown on Serial Monitor and LCD
void countdown(int duration, const char* message, int ledPin) {
  for (int i = duration; i > 0; i--) {
    // Tampilkan di Serial Monitor
    Serial.print(message);
    Serial.print(" dalam ");
    Serial.print(i);
    Serial.println(" detik...");

    // Tampilkan angka di baris kedua LCD
    lcd.setCursor(7, 1); // Tampilkan angka di tengah baris kedua
    lcd.print("   ");    // Hapus angka sebelumnya
    lcd.setCursor(7, 1); // Reset posisi kursor
    lcd.print(i);
    
    delay(1000); // Tunggu 1 detik
  }
}

void loop() {
  // Lampu Merah (Red LED)
  lcd.setCursor(4, 0); // Posisi kolom 4, baris 0
  lcd.print("BERHENTI");
  Serial.println("Lampu Merah: BERHENTI!");
  digitalWrite(2, HIGH);
  countdown(11, "Lampu Merah", 2); // Countdown selama 11 detik
  digitalWrite(2, LOW);
  lcd.clear();

  // Lampu Kuning (Yellow LED) - Bersiap Jalan
  lcd.setCursor(1, 0); // Posisi kolom 1, baris 0
  lcd.print("BERSIAP JALAN");
  Serial.println("Lampu Kuning: BERSIAP JALAN");
  digitalWrite(3, HIGH);
  countdown(2, "Lampu Kuning", 3); // Countdown selama 2 detik
  digitalWrite(3, LOW);
  lcd.clear();

  // Lampu Hijau (Green LED)
  lcd.setCursor(5, 0); // Posisi kolom 5, baris 0
  lcd.print("JALAN");
  Serial.println("Lampu Hijau: JALAN!");
  digitalWrite(4, HIGH);
  countdown(7, "Lampu Hijau", 4); // Countdown selama 7 detik
  digitalWrite(4, LOW);
  lcd.clear();

  // Lampu Kuning (Yellow LED) - Bersiap Berhenti
  lcd.setCursor(0, 0); // Posisi kolom 0, baris 0
  lcd.print("BERSIAP BERHENTI");
  Serial.println("Lampu Kuning: BERSIAP BERHENTI");
  digitalWrite(3, HIGH);
  countdown(2, "Lampu Kuning", 3); // Countdown selama 2 detik
  digitalWrite(3, LOW);
  lcd.clear();
}
