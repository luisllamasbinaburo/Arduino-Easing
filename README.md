# Arduino Easing Library
Arduino library that implement easing functions for smoothing variable changes. (For example, for changing a motor speed smoothly)

Just create a new `Easing` instance, and use `=` operator to set the new SetPoint. Then, use `GetValue()` function to get the smooth value.

Easing interval can be set in the `Easing` constructor, or change with `SetMillisInterval()` or `SetMicrosInterval()` methods. Aditionally, can use `Init()` to inmediately change both Setpoint and variable.

## Easing modes
### Available modes
	LINEAR
	EASE_IN_QUAD
	EASE_OUT_QUAD
	EASE_IN_OUT_QUAD
	EASE_IN_CUBIC
	EASE_OUT_CUBIC
	EASE_IN_OUT_CUBIC
	EASE_IN_QUART
	EASE_OUT_QUART
	EASE_IN_OUT_QUART
	EASE_IN_QUINT
	EASE_OUT_QUINT
	EASE_IN_OUT_QUINT
  
### Easing order
Five function orders available (LINEAR, QUAD, CUBIC, QUART, QUINT). The higher  order, the smoother the response transition (but high slope in the mid transition). Default CUBIC. 
![Image](https://github.com/luisllamasbinaburo/Arduino-Easing/blob/master/images/arduino-easing-modes.png)

### Easing IN, OUT or IN-OUT
Three transitions available (IN, OT and IN-OUT)
![Image](https://github.com/luisllamasbinaburo/Arduino-Easing/blob/master/images/arduino-easing-in-out.png)


## Example
```c++
#include "EasingLib.h"

int values[8] = { 0, 1000, 4000, 2000, 1000, 3000, 5000, 1000 };

// Default constructor (EASE_IN_OUT_CUBIC, 1000ms)
Easing easing();

// Full constructor
// Easing easing(ease_mode::LINEAR, 500);

void setup() 
{
	while (!Serial){};

	Serial.begin(115200);

	for(auto i = 0; i < 240; i++)
	{
		auto index = i / 30;
		float newValue = values[index];
		
		Serial.print(newValue);
		Serial.print(',');
		Serial.println(easing.SetSetpoint(newValue));

		delay(50);
	}
}

void loop()
{ 
}
```
