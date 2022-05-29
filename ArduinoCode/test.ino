#include <Servo.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define RST_PIN 9
#define SS_PIN 10
MFRC522 module_rfid(SS_PIN, RST_PIN);

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;
Servo monServomoteur2;
int pinTrig = 6;
int pinEcho = 7;
long temps;
float distance;




void setup() {
  
  


    
  // Attache le servomoteur à la broche D9
  monServomoteur.attach(5);
  monServomoteur2.attach(3);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;); // Don't proceed, loop forever
  }
  display.display();
  digitalWrite(pinTrig, LOW);  
  SPI.begin();
  module_rfid.PCD_Init();

  Serial.begin(9600);
  
  
}
int passage = 0;
int degre = 90;
void loop() {

  display.clearDisplay();
  display.setTextSize(3); // taille du texte
  display.setTextColor(WHITE);
  display.setCursor(1,1); // position du curseur colonne / ligne
  display.setTextSize(2);
  display.println("Passages :");
  display.setCursor(60,30);
  display.setTextSize(3);
  display.print(passage);
  display.display();


 
  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  temps = pulseIn(pinEcho, HIGH);    
  temps = temps/2;
  distance = (temps*340)/10000.0; 
  if (distance < 6) {  
    Serial.print("distance :");
    Serial.print(distance);
    passage = passage + 1; 
    delay(1000);         
    monServomoteur.write(110);
    delay(1000);
    monServomoteur.write(0);
  }

  if ( ! module_rfid.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! module_rfid.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  String UID = "";

  for (byte i = 0; i < module_rfid.uid.size; i++) {
    UID.concat(String(module_rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(module_rfid.uid.uidByte[i], HEX));
  }

  UID.toUpperCase();


  if (UID.substring(1) == "8B 5F BF 49") 
  {
   display.clearDisplay();
  display.setTextSize(3); // taille du texte
  display.setTextColor(WHITE);
  display.setCursor(0,0); // position du curseur colonne / ligne
  display.setTextSize(2);
  display.println("Acces ");
  display.setCursor(0,20); // position du curseur colonne / ligne
  display.println("Autorise");
  display.display();
  monServomoteur2.write(90);
  delay(1000);
  monServomoteur2.write(0);
  delay(2000);
  }

  else 
{
   display.clearDisplay();
  display.setTextSize(3); // taille du texte
  display.setTextColor(WHITE);
  display.setCursor(1,1); // position du curseur colonne / ligne
  display.setTextSize(2);
  display.println("Acces ");
  display.setCursor(0,20); // position du curseur colonne / ligne
  display.println("Refuse");
  display.display();
  delay(2000);
  }

      


  delay(1000);

  
}`
