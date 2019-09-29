/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
 #include "EasingLib.h"

Easing::Easing()
{
	_startPoint = 0;
	_setPoint = 0;
	_active = false;
	SetMode(ease_mode::EASE_IN_OUT_QUINT);
	easingFunction = &Easing::easeInOutCubic;
	_easyDuration = 1000000;
}

Easing::Easing(ease_mode mode, unsigned long millisInterval)
{
	_startPoint = 0;
	_setPoint = 0;
	_active = false;
	SetMode(mode);
	_easyDuration = millisInterval * 1000;
}

void Easing::Init(float value)
{
	_setPoint = value;
	_startPoint = value;
	_currentValue = value;
}

float Easing::operator=(float value)
{
	return SetSetpoint(value);
}

Easing::operator float()
{
	return GetValue();
}

float Easing::GetSetpoint(float value)
{
	return _setPoint;
}

float Easing::SetSetpoint(float value)
{
	if (value == _setPoint) return GetValue();

	_setPoint = value;
	_startPoint = _currentValue;
	_startTime = micros();
	_active = true;
	return _currentValue;
}

float Easing::GetValue()
{
	if (!_active) return _currentValue;

	unsigned long elapsedTime = micros() - _startTime;
	if (elapsedTime >= _easyDuration)
	{
		_active = false;
		_startPoint = _setPoint;
		_currentValue = _setPoint;
		return _currentValue;
	}

	float t = static_cast<float>(elapsedTime) / _easyDuration;
	_currentValue = (_setPoint - _startPoint) * (*this.*easingFunction)(t) + _startPoint;
	return _currentValue;
}

void Easing::SetMillisInterval(unsigned long interval)
{
	_easyDuration = 1000 * interval;
}

void Easing::SetMicrosInterval(unsigned long interval)
{
	_easyDuration = interval;
}

void Easing::SetMode(ease_mode mode)
{
	switch (mode)
	{
	case LINEAR: 			easingFunction = (&Easing::linear); break;
	case EASE_IN_QUAD: 		easingFunction = (&Easing::easeInQuad); break;
	case EASE_OUT_QUAD: 	easingFunction = (&Easing::easeOutQuad); break;
	case EASE_IN_OUT_QUAD: 	easingFunction = (&Easing::easeInOutQuad); break;
	case EASE_IN_CUBIC: 	easingFunction = (&Easing::easeInCubic); break;
	case EASE_OUT_CUBIC: 	easingFunction = (&Easing::easeOutCubic); break;
	case EASE_IN_OUT_CUBIC: easingFunction = (&Easing::easeInOutCubic); break;
	case EASE_IN_QUART: 	easingFunction = (&Easing::easeInQuart); break;
	case EASE_OUT_QUART: 	easingFunction = (&Easing::easeOutQuart); break;
	case EASE_IN_OUT_QUART: easingFunction = (&Easing::easeInOutQuart); break;
	case EASE_IN_QUINT: 	easingFunction = (&Easing::easeInQuint); break;
	case EASE_OUT_QUINT: 	easingFunction = (&Easing::easeOutQuint); break;
	case EASE_IN_OUT_QUINT: easingFunction = (&Easing::easeInOutQuint); break;
	}
}


float Easing::linear(float t) { return t; }

float Easing::easeInQuad(float t) { return t * t; }

float Easing::easeOutQuad(float t) { return t * (2 - t); }

float Easing::easeInOutQuad(float t) { return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t; }

float Easing::easeInCubic(float t) { return t * t * t; }

float Easing::easeOutCubic(float t) { return (--t) * t * t + 1; }

float Easing::easeInOutCubic(float t) { return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1; }

float Easing::easeInQuart(float t) { return t * t * t * t; }

float Easing::easeOutQuart(float t) { return 1 - (--t) * t * t * t; }

float Easing::easeInOutQuart(float t) { return t < .5 ? 8 * t * t * t * t : 1 - 8 * (--t) * t * t * t; }

float Easing::easeInQuint(float t) { return t * t * t * t * t; }

float Easing::easeOutQuint(float t) { return 1 + (--t) * t * t * t * t; }

float Easing::easeInOutQuint(float t) { return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t; }