/*
  Example App Anemone App v1

  This sketch is a minimal example of Anemone application created by the Anemone Team

  In order to run it you need to have Anemone Arduino library
  (which is distributed in Anemone.h file)

  Made with love in Prague by Juicymo s.r.o. at 2016

  @see http://www.anemone.cloud
  @see https://github.com/ceskasporitelna/anemone/tree/master/apps/example-app
*/

#include "Anemone.h"

// Program Constants
#define UI_CHECK_UPDATE 10000

// =========================================
// Interface
int timeCheckUpdate;

// =========================================
// Implementation
void setup() {
  Serial.begin(9600);
  Bridge.begin();

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  anemoneTentacleDisplay.begin();

  drawDisplay();

  timeCheckUpdate = millis();
}

void loop() {
  if ((millis() - timeCheckUpdate) > UI_CHECK_UPDATE) {
    anemoneUiCheckUpdate();
    timeCheckUpdate = millis();
  }
  
  delay(100);
}

void drawDisplay(){
  anemoneTentacleDisplay.background(255, 255, 255);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.setTextSize(2);
  anemoneTentacleDisplay.text("Example App", 10, 20);
}
