
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define PIN 7	 // set input pin Neopixel is attached to
#define NUM_LEDS 23 // number of neopixels in Ring
#define TempSensor A0 // set pin temp sensor is attached to
#define MoistureSensor A1 // set pin moisture sensor is attached to

// Initialisation for led strips
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pump = 9; // initialise Pump pin
const int fan = 6; // initialise Fan pin

int MS = 0; // Create variable called MS


void setup() {
  strip.begin(); // Start Strip blank
  strip.show();
  Serial.begin(9600); // Starts Serial Monitor
  pinMode(TempSensor, INPUT); // setting function of pins
  pinMode(MoistureSensor, INPUT);
  pinMode(pump, OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature:");
}

void loop() {
  // Reading and calculating value on temp sensor
  float temp = ((analogRead(TempSensor) * (5.0/1024)) - 0.5)/0.01;
  MS = analogRead(MoistureSensor); // Storing value of moisture sensor in variable MS 
  Serial.println(MoistureSensor);
  
  
    lcd.setCursor(0, 1);
    lcd.print("   ");
    lcd.setCursor(0, 1);
    lcd.print(temp);
  
  	//Serial.println(temp);
  	delay(1000);

  if (MS < 10) {
    digitalWrite(pump, HIGH); // Turn on pump
  }else{
    digitalWrite(pump, LOW); // Turn off pump
  }
  
  if (temp < 20){
    // Turn on LED strips
    strip.setPixelColor(0,0,0,255);
    strip.setPixelColor(1,0,0,255);
    strip.setPixelColor(2,0,0,255);
    strip.setPixelColor(3,0,0,255);
    strip.setPixelColor(4,0,0,255);
    strip.setPixelColor(5,0,0,255);
    strip.setPixelColor(6,0,0,255);
    strip.setPixelColor(7,0,0,255);
    strip.setPixelColor(8,0,0,255);
    strip.setPixelColor(9,0,0,255);
    strip.setPixelColor(10,0,0,255);
    strip.setPixelColor(11,0,0,255);
    strip.setPixelColor(12,0,0,255);
    strip.setPixelColor(13,0,0,255);
    strip.setPixelColor(14,0,0,255);
    strip.setPixelColor(15,0,0,255);
  	strip.show();
  }else{
    // Turn LED strips off
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.setPixelColor(4, 0, 0, 0);
    strip.setPixelColor(5, 0, 0, 0);
    strip.setPixelColor(6, 0, 0, 0);
    strip.setPixelColor(7, 0, 0, 0);
    strip.setPixelColor(8, 0, 0, 0);
    strip.setPixelColor(9, 0, 0, 0);
    strip.setPixelColor(10, 0, 0, 0);
    strip.setPixelColor(11, 0, 0, 0);
    strip.setPixelColor(12, 0, 0, 0);
    strip.setPixelColor(13, 0, 0, 0);
    strip.setPixelColor(14, 0, 0, 0);
    strip.setPixelColor(15, 0, 0, 0);
    strip.show();
  }

  if (temp > 30){
    digitalWrite(fan, HIGH); // Turn on fan
  }else{
    digitalWrite(fan, LOW); // Turn off fan
  }
}
