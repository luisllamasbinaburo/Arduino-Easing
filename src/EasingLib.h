/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
 #ifndef _EASINGLIB_h
#define _EASINGLIB_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

enum ease_mode {
	LINEAR,
	EASE_IN_QUAD,
	EASE_OUT_QUAD,
	EASE_IN_OUT_QUAD,
	EASE_IN_CUBIC,
	EASE_OUT_CUBIC,
	EASE_IN_OUT_CUBIC,
	EASE_IN_QUART,
	EASE_OUT_QUART,
	EASE_IN_OUT_QUART,
	EASE_IN_QUINT,
	EASE_OUT_QUINT,
	EASE_IN_OUT_QUINT
};

class Easing
{

public:
	typedef float (Easing::* EasingFunction)(float);

	Easing();
	Easing(ease_mode mode, unsigned long millisInterval);

	void Init(float value);

	float operator = (float value);
	operator float();
	float GetSetpoint(float value);
	float SetSetpoint(float value);
	float GetValue();

	void SetMillisInterval(unsigned long interval);
	void SetMicrosInterval(unsigned long interval);
	void SetMode(ease_mode mode);

private:
	ease_mode Mode;
	float _startPoint;
	float _setPoint;
	float _currentValue;
	unsigned long _startTime;
	unsigned long _easyDuration = 1000000;
	bool _active;

	EasingFunction easingFunction;
	float linear(float t);
	float easeInQuad(float t);
	float easeOutQuad(float t);
	float easeInOutQuad(float t);
	float easeInCubic(float t);
	float easeOutCubic(float t);
	float easeInOutCubic(float t);
	float easeInQuart(float t);
	float easeOutQuart(float t);
	float easeInOutQuart(float t);
	float easeInQuint(float t);
	float easeOutQuint(float t);
	float easeInOutQuint(float t);
};

#endif

