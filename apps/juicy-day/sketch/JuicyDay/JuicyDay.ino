/*
  Juicy Day Anemone App v1

  This sketch is example Anemone application created by the Anemone Team

  In order to run it you need to have Anemone Arduino library
  (which is distributed in Anemone.h file)

  Made with love in Prague by Juicymo s.r.o. at 2016

  @see http://www.anemone.cloud
  @see https://github.com/ceskasporitelna/anemone/tree/master/apps/juicy-day
*/

#include "Anemone.h"

// Program Constants
#define UI_LOOP_INTERVAL 5
#define TIME_UPDATE 60000

#define MENU_LABEL_APP "Convert"
#define MENU_LABEL_BEEP "Beeping"
#define MENU_LABEL_BLINK "Blinking"

// =========================================
// Variables

// Tentacle Variables
char * varCzk = "n/a";
char * varUsd = "n/a";
char * varEur = "n/a";

// Tentacle Scripts Output Parsing Variables
char * strings[3];

// Multitasking Variables
unsigned long timeUiLoop;
unsigned long timeUpdate;

// =========================================
// Interface
void setupBuzzer();
void setupScreen();
void setupMenu();
void setupHooks();
void setupMultitasking();

void loopUi();
void loopLogic();

void handleMenuConvert();
void handleMenuBeep();
void handleMenuBlink();

void parseString(char *);

void buzzerOn();
void buzzerOff();
void ledOn();
void ledOff();

void drawAppIconSelected();
void drawAppIcon();
void drawBlinkIconSelected();
void drawBlinkIcon();
void drawBeepIconSelected();
void drawBeepIcon();
void drawDashboard();
void drawMenuIcons();

// =========================================
// Implementation
void setup() {
  anemoneSetup();

  setupBuzzer();
  setupScreen();
  setupMenu();
  setupHooks();
  setupMultitasking();
}

void loop() {
  if ((millis() - timeUiLoop) > UI_LOOP_INTERVAL) {
    loopUi();
  }

  if ((millis() -  timeUpdate) > TIME_UPDATE) {
    loopLogic();
  }

  delay(10);
}

// Functions - Setup
void setupBuzzer() {
  buzzerOff();
}

void setupScreen() {
  anemoneTentacleDisplay.begin();
}

void setupMenu() {
  anemoneSetMenuIcons(&drawMenuIcons);
  
  anemoneUiAddMenuItem(MENU_LABEL_APP, ANEMONE_MENU_DASHBOARD, &handleMenuConvert);
  anemoneUiAddMenuItem(MENU_LABEL_BEEP, ANEMONE_MENU_BEEP, &handleMenuBeep);
  anemoneUiAddMenuItem(MENU_LABEL_BLINK, ANEMONE_MENU_BLINK, &handleMenuBlink);

  anemoneMenuHandles[ANEMONE_MENU_DASHBOARD]();
}

void setupHooks() {
  anemoneUiRegisterHook(ANEMONE_UI_HOOK_BUTTON_SHARE, &handleButtonShare);
  anemoneUiRegisterHook(ANEMONE_UI_HOOK_BUTTON_BACK, &handleBackButton);
  anemoneUiRegisterHook(ANEMONE_UI_HOOK_ENCODER_ROTARY, &handleEncoderRotate);
  anemoneUiRegisterHook(ANEMONE_UI_HOOK_BUTTON_ENCODER, &handleEncoderButton);
}

void setupMultitasking() {
  timeUpdate = millis();
  timeUiLoop = millis();
}

// Functions - Loop
void loopUi() {
  anemoneUiLoop();
  timeUiLoop = millis();
}

void loopLogic() {
  anemoneTentacleDisplay.stroke(39, 181, 242);
  anemoneTentacleDisplay.fill(39, 181, 242);
  anemoneTentacleDisplay.rect(0, 0, 40, 7);
  anemoneTentacleDisplay.rect(70, 0, 20, 7);
  anemoneTentacleDisplay.rect(120, 0, 40, 7);
  anemoneTentacleDisplay.rect(0, 121, 40, 7);
  anemoneTentacleDisplay.rect(70, 121, 20, 7);
  anemoneTentacleDisplay.rect(120, 121, 40, 7);

  anemoneTentacleDisplay.stroke(255, 230, 77);
  anemoneTentacleDisplay.fill(255, 230, 77);
  anemoneTentacleDisplay.rect(40, 0, 30, 7);
  anemoneTentacleDisplay.rect(90, 0, 30, 7);
  anemoneTentacleDisplay.rect(90, 121, 30, 7);
  anemoneTentacleDisplay.rect(40, 121, 30, 7);

  parseString(anemoneUiCheckUpdate());

  timeUpdate = millis();

  switch (anemoneActiveScreen) {
    case 0:
      anemoneTentacleDisplay.stroke(0, 0, 0);
      anemoneTentacleDisplay.fill(0, 0, 0);
      anemoneTentacleDisplay.rect(0, 0, 200, 7);

      anemoneTentacleDisplay.stroke(255, 255, 255);
      anemoneTentacleDisplay.fill(255, 255, 255);
      anemoneTentacleDisplay.rect(0, 121, 200, 7);
      break;

    case 1:
      anemoneTentacleDisplay.stroke(39, 181, 242);
      anemoneTentacleDisplay.fill(39, 181, 242);
      anemoneTentacleDisplay.rect(0, 0, 200, 7);

      anemoneTentacleDisplay.stroke(39, 181, 242);
      anemoneTentacleDisplay.fill(39, 181, 242);
      anemoneTentacleDisplay.rect(0, 121, 200, 7);
      break;

    case 2:
      anemoneUiShowMenu();
      anemoneSetMarked(anemoneSelectedMenuItem);
      break;

    case 3:
      anemoneTentacleDisplay.stroke(255, 255, 255);
      anemoneTentacleDisplay.fill(255, 255, 255);
      anemoneTentacleDisplay.rect(0, 0, 200, 7);

      anemoneTentacleDisplay.stroke(255, 255, 255);
      anemoneTentacleDisplay.fill(255, 255, 255);
      anemoneTentacleDisplay.rect(0, 121, 200, 7);
      break;
  }
}

// Functions - Hooks
void handleMenuConvert() {
  anemoneActiveScreen = 0;
  anemoneSelectedMenuItem = 0;

  drawDashboard();
}

void handleMenuBlink() {
  drawBlinkIconSelected();

  anemoneActiveScreen = 3;
  ledFading();
}

void handleMenuBeep() {
  anemoneActiveScreen = 3;

  drawBeepIconSelected();
  buzzerOn();
}

// Functions - Actuators
void buzzerOn() {
  digitalWrite(5, LOW);
}

void buzzerOff() {
  digitalWrite(ANEMONE_PIN_BUZZER, HIGH);
}

void ledOn() {
  analogWrite(ANEMONE_PIN_LED, 255);
}

void ledOff() {
  digitalWrite(ANEMONE_PIN_LED, 0);
}

void ledFading() {
  while (digitalRead(ANEMONE_PIN_BUTTON_BACK) == LOW) {
    for (int i = 0; i < 2; i++) {
      for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
        if (digitalRead(ANEMONE_PIN_BUTTON_BACK) == HIGH) {
          ledOff();
          return;
        }
        analogWrite(ANEMONE_PIN_LED, fadeValue);
        delay(30);
      }

      for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        if (digitalRead(ANEMONE_PIN_BUTTON_BACK) == HIGH) {
          ledOff();
          return;
        }
        analogWrite(ANEMONE_PIN_LED, fadeValue);
        delay(30);
      }
    }
  }
}

// Functions - Draw Graphics
void drawMenuIcons() {
  anemoneTentacleDisplay.background(255, 255, 255);
  anemoneTentacleDisplay.stroke(0 , 0, 0);

  // Draw dashboard icon
  anemoneTentacleDisplay.fill(255, 255, 255);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.rect(10, 7, 20, 20);
  anemoneTentacleDisplay.rect(22, 7, 5, 10);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.rect(13, 17, 5, 10);

  // Draw beeping icon
  anemoneTentacleDisplay.fill(255, 255, 255);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.rect(10, 48, 20, 20);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.stroke(255, 255, 255);
  anemoneTentacleDisplay.rect(20, 58, 8, 8);
  anemoneTentacleDisplay.rect(12, 58, 6, 6);
  anemoneTentacleDisplay.rect(20, 50, 6, 6);

  // Draw blinking icon
  anemoneTentacleDisplay.fill(255, 255, 255);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.rect(10, 91, 20, 20);
  anemoneTentacleDisplay.rect(19, 100, 6, 6);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.rect(17, 98, 6, 6);
}

void drawBlinkIconSelected() {
  anemoneTentacleDisplay.fill(39, 181, 242);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.rect(10, 91, 20, 20);
  anemoneTentacleDisplay.rect(19, 100, 6, 6);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.rect(17, 98, 6, 6);
}

void drawBeepIconSelected() {
  anemoneTentacleDisplay.fill(39, 181, 242);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.rect(10, 48, 20, 20);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.stroke(39, 181, 242);
  anemoneTentacleDisplay.rect(20, 58, 8, 8);
  anemoneTentacleDisplay.rect(12, 58, 6, 6);
  anemoneTentacleDisplay.rect(20, 50, 6, 6);
}

void drawDashboard() {
  anemoneTentacleDisplay.background(255, 255, 255);
  anemoneTentacleDisplay.stroke(0, 0, 0);
  anemoneTentacleDisplay.fill(0, 0, 0);
  anemoneTentacleDisplay.rect(0, 0, anemoneTentacleDisplay.width(), anemoneTentacleDisplay.height() / 3);
  anemoneTentacleDisplay.setTextSize(2);

  anemoneTentacleDisplay.text("USD: ",  10, 55);
  anemoneTentacleDisplay.text("EUR: ",  10, 100);

  anemoneTentacleDisplay.stroke(255, 255, 255);
  anemoneTentacleDisplay.text("CZK", 20 , 10);
  anemoneTentacleDisplay.text(varCzk,  65, 10);

  anemoneTentacleDisplay.stroke(39, 181, 242);
  anemoneTentacleDisplay.text(varUsd,  60, 55);

  anemoneTentacleDisplay.stroke(255, 255, 255);
  anemoneTentacleDisplay.fill(255, 255, 255);
  anemoneTentacleDisplay.rect(130, 50, 30, 25);

  anemoneTentacleDisplay.stroke(247, 67, 67);
  anemoneTentacleDisplay.text(varEur,  60, 100);

  anemoneTentacleDisplay.stroke(255, 255, 255);
  anemoneTentacleDisplay.fill(255, 255, 255);
  anemoneTentacleDisplay.rect(130, 95, 30, 25);

  anemoneTentacleDisplay.rect(130, 50, 30, 25);
}

// Functions - Parsing
void parseString(char * tmp) {
  int i;
  int counter = 0;

  if (tmp != NULL || strcmp(tmp, "")) {
    strings[counter] = strtok(tmp, "\n");
    counter++;

    while ( counter < 3  ) {
      strings[counter] = strtok(NULL, "\n");
      counter++;
    }

    for (i = 0; i < 3; i++) {
      char * tmp2 = strtok(strings[i], "=");
      if (strcmp(tmp2, "varCostCzk") == 0) {
        varCzk = strtok(NULL, "\n");
        anemoneTentacleDisplay.stroke(0, 0, 0);
        anemoneTentacleDisplay.fill(0, 0, 0);
        anemoneTentacleDisplay.rect(65, 10, 80, 20);
        anemoneTentacleDisplay.stroke(255, 255, 255);
        anemoneTentacleDisplay.text(varCzk, 65, 10);
      } else if (strcmp(tmp2, "varCostEur") == 0) {
        varEur = strtok(NULL, "\n");

        anemoneTentacleDisplay.stroke(255, 255, 255);
        anemoneTentacleDisplay.fill(255, 255, 255);

        anemoneTentacleDisplay.rect(60, 100, 80, 20);
        anemoneTentacleDisplay.stroke(247, 67, 67);
        anemoneTentacleDisplay.text(varEur, 60, 100);

        anemoneTentacleDisplay.stroke(255, 255, 255);
        anemoneTentacleDisplay.rect(130, 95, 30, 25);
      } else if (strcmp(tmp2, "varCostUsd") == 0) {
        varUsd = strtok(NULL, "\n");

        anemoneTentacleDisplay.stroke(255, 255, 255);
        anemoneTentacleDisplay.fill(255, 255, 255);

        anemoneTentacleDisplay.rect(60, 55, 80, 20);
        anemoneTentacleDisplay.stroke(39, 181, 242);
        anemoneTentacleDisplay.text(varUsd, 60, 55);

        anemoneTentacleDisplay.stroke(255, 255, 255);
        anemoneTentacleDisplay.rect(130, 50, 30, 25);
      }
    }
  }
}
