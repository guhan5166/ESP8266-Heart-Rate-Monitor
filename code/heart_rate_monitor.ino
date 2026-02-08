#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- OLED ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ---------- PULSE SENSOR ----------
#define PULSE_PIN A0

// ---------- FILTER ----------
#define FILTER_SIZE 10
int filterBuffer[FILTER_SIZE];
int filterIndex = 0;

// ---------- BPM CALC ----------
unsigned long windowStart = 0;
int beatCount = 0;
int bpm = 0;

const int threshold = 550;
const unsigned long minBeatInterval = 300; // ms
unsigned long lastBeatTime = 0;

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);

  for (int i = 0; i < FILTER_SIZE; i++) {
    filterBuffer[i] = 0;
  }

  windowStart = millis();
}

int getFilteredValue(int newValue) {
  filterBuffer[filterIndex] = newValue;
  filterIndex = (filterIndex + 1) % FILTER_SIZE;

  long sum = 0;
  for (int i = 0; i < FILTER_SIZE; i++) {
    sum += filterBuffer[i];
  }
  return sum / FILTER_SIZE;
}

void loop() {
  int rawValue = analogRead(PULSE_PIN);
  int pulseValue = getFilteredValue(rawValue);
  unsigned long now = millis();

  // Beat detection
  if (pulseValue > threshold &&
      now - lastBeatTime > minBeatInterval) {
    beatCount++;
    lastBeatTime = now;
  }

  // Calculate BPM every 5 seconds
  if (now - windowStart >= 5000) {
    bpm = (beatCount * 60) / 5;
    beatCount = 0;
    windowStart = now;
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(5, 0);
  display.println("Heart Rate");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println("  Monitor");

  display.setTextSize(2);
  display.setCursor(27, 47);
  display.print(bpm);
  display.println(" BPM");


  display.display();
  delay(20);
}
