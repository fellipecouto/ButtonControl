/*---------------------------------------------------------
  Program  : ButtonControl
  Descr    : Library to control push button click times
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/ButtonControl
  Date     : 2023-08-20
  ---------------------------------------------------------*/
#include "ButtonControl.h"
#include <Arduino.h>

ButtonControl::ButtonControl(uint8_t buttonPin, bool internalPullup, bool logicSignal) {
  _pin = buttonPin;
  _signal = logicSignal;
  if (internalPullup) {
    pinMode(_pin, INPUT_PULLUP);
    _signal = LOW;
  } else {
    pinMode(_pin, INPUT);
  }
}

bool ButtonControl::fastClick(bool continuous) {
  _continuous = continuous;
  verifyButton(true, false);
  if (_buttonClicks > 0) return true;
  return false;
}

bool ButtonControl::click() {
  verifyButton(false, false);
  if (_buttonClicks > 0) return true;
  return false;
}

bool ButtonControl::doubleClick() {
  verifyButton(false, true);
  if (_buttonClicks == 2) return true;
  return false;
}

bool ButtonControl::longClick() {
  verifyButton(false, false);
  return _longClick;
}

int ButtonControl::getButtonClicks() {
  return _buttonClicks;
}

long ButtonControl::getLongClickTime() {
  if (_longClick) return _buttonTimes;
  return 0;
}

int ButtonControl::getMinLongClickTime() {
  return _longMinClickTime;
}

int ButtonControl::getFastClickContinuousTime() {
  return _continuousTime;
}

void ButtonControl::setMinLongClickTime(int minimumTime) {
  _longMinClickTime = minimumTime;
}

void ButtonControl::setFastClickContinuousTime(int continuousTime) {
  _continuousTime = continuousTime;
  if (_continuousTime < _debounceTime) _continuousTime = _debounceTime;
}

void ButtonControl::verifyButton(bool fast, bool doubleClick) {
  _buttonTimes = 0;
  _buttonClicks = 0;
  _longClick = false;
  while (digitalRead(_pin) == _signal) {
    _buttonTimes++;
    if (_buttonTimes >= _continuousTime && _continuous) break;
    delay(1);
  }
  if (_buttonTimes > _debounceTime) {
    _buttonClicks++;
    if (fast) return;
    if (_buttonTimes >= _longMinClickTime) {
      _longClick = true;
    } else {
      bool loopClick = true;
      while (loopClick) {
        int timeNotPressedValue = 250;
        int timeNotPressedCount = 0;
        while (digitalRead(_pin) == !_signal) {
          timeNotPressedCount++;
          if (timeNotPressedCount >= timeNotPressedValue) {
            loopClick = false;
            break;
          }
          delay(1);
        }
        if (timeNotPressedCount < timeNotPressedValue) {
          _buttonTimes = 0;
          while (digitalRead(_pin) == _signal) {
            _buttonTimes++;
            delay(1);
          }
          if (_buttonTimes > 20) _buttonClicks++;
          if (_buttonClicks == 2 && doubleClick) loopClick = false;
        }
      }
    }
  }
}