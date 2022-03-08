#include <RGBmatrixPanel.h>

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define COLOR_WHITE 1,1,1
#define COLOR_BLACK 0,0,0

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

constexpr int delayTime = 7000; // ms
constexpr int blankTime = 100; // ms

void matrixClear() {
  matrix.fillScreen(matrix.Color333(COLOR_BLACK));
  matrix.setCursor(0,0);
}

void blankDelay(int ms)
{
  int actualBlankTime = blankTime;
  
  if (ms <= blankTime)
    actualBlankTime = 0;

  delay(ms - actualBlankTime);
  matrixClear();
  delay(actualBlankTime);
}

void printTeamName(const char name[], bool shouldBlank = true) {
  // clear the team name field
  matrix.fillRect(0, 0, matrix.width(), 8, matrix.Color333(COLOR_BLACK));
  // print on line 1
  matrix.setCursor(0, 0);

  if (shouldBlank) {
    delay(blankTime);
  }
  
  matrix.println(name);
  matrix.drawLine(0, 7, matrix.width() - 1, 7, matrix.Color333(COLOR_WHITE));
}

void printMeetingName(const char name[], bool shouldBlank = true) {
  // clear the team name field
  matrix.fillRect(0, 9, matrix.width(), 7, matrix.Color333(COLOR_BLACK));
  // print on line 2
  matrix.setCursor(0, 9);

  if (shouldBlank) {
    delay(blankTime);
  }
  
  matrix.println(name);
}

void printMeetingDetails(const char line1[], const char line2[], bool shouldBlank = true) {
  // clear the details fields
  matrix.fillRect(0, 17, matrix.width(), 16, matrix.Color333(COLOR_BLACK));
  matrix.setCursor(0, 17);

  if (shouldBlank) {
    delay(blankTime);
  }
  
  matrix.println(line1);
  matrix.println(line2);
}

void printRobotics() {
  printTeamName("ROBO TEAM", false);
  
  printMeetingName("MEETING", false);
  printMeetingDetails("THURS M306", "4:04 PM");
  delay(delayTime);

  printMeetingName("WORKDAYS");
  printMeetingDetails("WED M101", "5 PM");
  delay(delayTime);
  printMeetingDetails("SAT M101", "NOON");

  blankDelay(delayTime);
}

void printUAS() {
  printTeamName("UAS TEAM", false);
  
  printMeetingName("MEETING", false);
  printMeetingDetails("MON M101","5 PM");
  delay(delayTime);
  printMeetingDetails("EVERY", "OTHER WEEK");
  delay(delayTime);

  printMeetingName("WORKDAY");
  printMeetingDetails("FRI M101", "5 PM");
  
  blankDelay(delayTime);
}

void print3DPC() {
  printTeamName("3DPC", false);
  
  printMeetingName("MEETING", false);
  printMeetingDetails("FRI M206", "4 PM");
  delay(delayTime);

  printMeetingName("WORKDAY");
  printMeetingDetails("SAT M101", "NOON");

  blankDelay(delayTime);
}

void setup() {
  matrix.begin();

  matrix.setTextSize(1);
  matrix.setCursor(0,0);
  matrix.setTextColor(matrix.Color333(COLOR_WHITE));
  matrix.print("HELLO");
  blankDelay(500);
}

void loop() {
  printRobotics();
  printUAS();
  print3DPC();
}
