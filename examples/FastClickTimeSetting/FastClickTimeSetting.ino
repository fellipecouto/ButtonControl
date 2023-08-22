/*---------------------------------------------------------
  Program  : ButtonControl
  Descr    : Library to control push button click times
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/ButtonControl
  Date     : 2023-08-20
  ---------------------------------------------------------*/
//Example of short button clicks with time setting

#include <ButtonControl.h>  //https://github.com/fellipecouto/ButtonControl

ButtonControl btn(4);  //Push button connected to pin 4 and GND. Default library configuration: pin in INPUT_PULLUP mode and the button connecting LOW to the pin

int clickCounter = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Open the serial monitor and...");
  Serial.println("Click on the button!");
  Serial.println("Keep the button pressed.");
}

void loop() {
  //Information: using the 'false' parameter, the click will be considered only after releasing the button. Ex.: btn.fastClick(false)

  if (btn.fastClick()) {
    clickCounter++;
    Serial.print("Clicked! ");
    Serial.println(clickCounter);
  }

  if (clickCounter == 7) {
    btn.setFastClickContinuousTime(600);
    Serial.print("New continuous click time: (ms): ");
    Serial.println(btn.getFastClickContinuousTime());
  }

  if (clickCounter == 14) {
    btn.setFastClickContinuousTime(70);
    Serial.print("New continuous click time: (ms): ");
    Serial.println(btn.getFastClickContinuousTime());
  }

  if (clickCounter == 21) {
    btn.setFastClickContinuousTime(1000);
    Serial.print("New continuous click time: (ms): ");
    Serial.println(btn.getFastClickContinuousTime());
  }
}