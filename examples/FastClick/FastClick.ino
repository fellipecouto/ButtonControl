/*---------------------------------------------------------
  Program  : ButtonControl
  Descr    : Library to control push button click times
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/ButtonControl
  Date     : 2023-08-20
  ---------------------------------------------------------*/
//Example of short button clicks

#include <ButtonControl.h>  //https://github.com/fellipecouto/ButtonControl

ButtonControl btn(4);  //Push button connected to pin 4 and GND. Default library configuration: pin in INPUT_PULLUP mode and the button connecting LOW to the pin

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Open the serial monitor and...");
  Serial.println("Click on the button!");
  Serial.println("If you keep the button pressed, the clicks will be counted.");
}

void loop() {
  if (btn.fastClick()) {
    Serial.println("Clicked!");
  }
}