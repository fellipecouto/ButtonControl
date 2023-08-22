# ButtonControl
Library to control push button click times.
Short clicks, long clicks and double clicks. Click count and button press time.

## Usage
```c++
//Library instance with pin number the button is connected to
//Optional parameters if not declared assume default values
ButtonControl(uint8_t buttonPin, bool internalPullup = true, bool logicSignal = LOW);

//Returns true if the button is pressed. Only short clicks and no click counts. Default parameter true to keep clicks while the button is pressed
bool fastClick(bool continuous = true);

//Returns true if the button is pressed. Short or long click
bool click();

//Returns true if a double click is pressed
bool doubleClick();

//Returns true only if there is a long click
bool longClick();

/* GETS */
//Returns the number of short clicks
int getButtonClicks();

//Returns the elapsed time of the long click in milliseconds
long getLongClickTime();

//Returns the configured minimum time for the long click
int getMinLongClickTime();

//Returns the time range for continuous clicks
int getFastClickContinuousTime();

/* SETS */
//Sets the minimum time for the long click. Default value 1000 milliseconds
void setMinLongClickTime(int minimumTime = 1000);

//Sets the time of continuous clicks. Default value 200 milliseconds
void setFastClickContinuousTime(int continuousTime = 200);
```

>**Note:** [`Usage examples available in the directory`](https://github.com/fellipecouto/ButtonControl/tree/master/examples)

## Author
Fellipe Couto [ http://www.efeitonerd.com.br ]
Date : 2023-08-20
