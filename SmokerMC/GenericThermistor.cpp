/*
 * GenericThermistor.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#include "GenericThermistor.h"
#include <math.h>
#include "Arduino.h"

//Calculate temperature using the Beta coefficient method
double GenericThermistor::getTempWithBeta(int ADC_Value) {
	double temp;

	// convert the value to resistance
	ADC_Value = 1023 / ADC_Value - 1;
	ADC_Value = this->seriesRes / ADC_Value;

	temp = ADC_Value / this->thermistorNominalResistance;     // (R/Ro)
	temp = log(temp); // ln(R/Ro)
	temp /= this->beta; // 1/B * ln(R/Ro)
	temp += 1.0 / (this->thermistorNominalTemperature + 273.15); // + (1/To)

	if( ! this->isPullUp) {temp = 1.0 / temp;} //invert -- we would NOT do this if the thermistor was connected to Vcc instead of GND

	return temp;
}

//Calculate temperature using the full Steinhart-Hart equation with 3 coefficients
double GenericThermistor::getTempWithSteinhartHart(int ADC_Value) {
	double temp;
	Serial.println("Inside getTempWithSteinhartHard function. The ADC value passed in is ");
	Serial.println(ADC_Value);

	Serial.print("Series Reistor is listed at ");
	Serial.println(this->seriesRes);

	if(this->isPullUp) {
		Serial.println("Using pull-up configuration.");
		temp = log((this->seriesRes) / ((1024.0 / ADC_Value - 1))); // for pull-up configuration
	} else {
		Serial.println("Using pull-down configuration.");
		temp = log((this->seriesRes) * ((1024.0 / ADC_Value - 1))); // for pull-down configuration
	}
	Serial.print("Step 1 one of calculation: ");
	Serial.println(temp);

	temp = 1 / ((this->coeff_A) + ((this->coeff_B) + ((this->coeff_C) * temp * temp ))* temp );

	Serial.print("Returning temp in Kelvin: ");
	Serial.println(temp);

	return temp;
}

//Return temperature in Kelvin
double GenericThermistor::getTempK() {
	double tempK;
	int samples[this->numSamples];

	for (int i = 0; i < this->numSamples; i++) {
		samples[i] = analogRead(this->pin);
		delay(10);
	}

	int ADC_average = 0;
	for (int i = 0; i < this->numSamples; i++) {
		ADC_average += samples[i];
	}
	ADC_average /= this->numSamples;

	Serial.print("ADC Average: ");
	Serial.println(ADC_average);

	if(this->useBeta) {tempK = this->getTempWithBeta(ADC_average);}
	else {tempK = this->getTempWithSteinhartHart(ADC_average);}

	tempK += this->tempOffsetK;

	return tempK;
}

//Return temperature in Celcius
double GenericThermistor::getTempC() {
	Serial.println("Inside getTempC");

	double tempC = this->getTempK();
	tempC -= 273.15;
	Serial.print("Returning ");
	Serial.print(tempC);
	Serial.println(" Celcius.");
	return tempC;
}

//Return temperature in Fahrenheit
double GenericThermistor::getTempF() {
	Serial.println("Inside getTempF");

	double tempF = this->getTempC();
	Serial.print("Converting ");
	Serial.print(tempF);
	Serial.print(" Kelvin to ");
	tempF = (tempF * 9.0) / 5.0 + 32;
	Serial.print(tempF);
	Serial.println(" Fahrenheit.");
	return tempF;
}

