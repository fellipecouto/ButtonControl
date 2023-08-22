/*---------------------------------------------------------
  Program  : ButtonControl
  Descr    : Library to control push button click times
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/ButtonControl
  Date     : 2023-08-20
  ---------------------------------------------------------*/
//Double click verification example

#include <ButtonControl.h>  //https://github.com/fellipecouto/ButtonControl

ButtonControl btn(4);  //Button connected to pin 4 and GND. Default library configuration: pin in INPUT_PULLUP mode and the button connecting LOW to the pin. Can be changed with parameters

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Open the serial monitor and...");
  Serial.println("Double-click the button!");
}

void loop() {
  if (btn.doubleClick()) {
    Serial.println("Yes! Double-click!");
  }
}