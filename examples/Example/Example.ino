/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
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
