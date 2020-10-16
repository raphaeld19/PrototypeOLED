#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SPIDevice.h>

#define SCREEN_WIDTH 128 // Largeur de l'écran en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran en pixels.

// Déclaration de l'écran connecté via I2C.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }


}

void loop() {
  //Affichage des informations nécessaires.
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1,1);
  display.setTextColor(WHITE);

  display.setCursor(0, 5);
  // Display static text
  display.println("Aquarium Raph");

  display.setCursor(0, 20);
  // Display static text
  display.println("Temperature : 50C");

  display.setCursor(0, 35);
  // Display static text
  display.println("IP : 192.168.1.40");

  display.display(); 
}

