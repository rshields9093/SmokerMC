/*
 * GenericThermistor.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#include "GenericThermistor.h"
#include <math.h>
#include "Arduino.h"

/*Calculate temperature using the Beta coefficient method
 *
 *WARNING: This function is still buggy. Until this is resolved users of this class
 *WARNING: should ony use the non-Beta method of calaculating temperature (set useBeta = false).
 *
 *TODO debug this function. Right now it returns zero or infinite temperature.
 */
double GenericThermistor::getTempWithBeta(int ADC_Value) {
	double temp = ADC_Value;
	Serial.println("Inside getTempWithBeta");
	Serial.print("ADC Value: ");
	Serial.println(ADC_Value);

	Serial.print("Series Resistor: ");
	Serial.println(this->seriesRes);

	Serial.print("Nominal Resistence: ");
	Serial.println(this->thermistorNominalResistance);

	Serial.print("Beta Value: ");
	Serial.println(this->beta);

	Serial.print("Step 0: ");
	Serial.println(ADC_Value);

	// convert the value to resistance
	temp = 1023 / temp - 1;
	Serial.print("Step 1: ");
	Serial.println(temp);

	temp = this->seriesRes / temp;
	Serial.print("Step 2 (resistance): ");
	Serial.println(temp);

	temp = temp / this->thermistorNominalResistance;     // (R/Ro)
	Serial.print("Step 3: ");
		Serial.println(temp);

	temp = log(temp); // ln(R/Ro)
	Serial.print("Step 4: ");
		Serial.println(temp);

	temp /= this->beta; // 1/B * ln(R/Ro)
	Serial.print("Step 5: ");
		Serial.println(temp);

	temp += 1.0 / (this->thermistorNominalTemperature + 273.15); // + (1/To)
	Serial.print("Step 6: ");
		Serial.println(temp);

	if( ! this->isPullUp) {temp = 1.0 / temp;} //invert -- we would NOT do this if the thermistor was connected to Vcc instead of GND
	Serial.print("Step 7: ");
		Serial.println(temp);

	Serial.print("Returning Kelvin Temp: ");
	Serial.println(temp);
	return temp;
}

//Calculate temperature using the full Steinhart-Hart equation with 3 coefficients
double GenericThermistor::getTempWithSteinhartHart(int ADC_Value) {
	double temp;

	if(this->isPullUp) {
		temp = log((this->seriesRes) / ((1024.0 / ADC_Value - 1))); // for pull-up configuration
	} else {
		temp = log((this->seriesRes) * ((1024.0 / ADC_Value - 1))); // for pull-down configuration
	}

	temp = 1 / ((this->coeff_A) + ((this->coeff_B) + ((this->coeff_C) * temp * temp ))* temp );

	return temp;
}

/*Return temperature in Kelvin. As all the thermistor to temperature algorithms use Kelvin,
 * this is the most fundamental temperature call. Calls for Celcius or Fahrenheit temps
 * first call this function and then convert the Kelvin return value.
 *
 * This function takes a number of analog readings equal to numSamples and averages the result
 * in order to smooth out the data.
*/
double GenericThermistor::getTempK() {
	double tempK;
	int reading = getADCReading(this->pin); //get ADC value

	//depending on the algorithm chosen call the correct function to convert the reading to a temperature
	if(this->useBeta) {tempK = this->getTempWithBeta(reading);}
	else {tempK = this->getTempWithSteinhartHart(reading);}

	tempK += this->tempOffsetK; //adjust with offset, if any

	return tempK;
}

//Return temperature in Celcius
double GenericThermistor::getTempC() {
	double tempC = this->getTempK(); //first get temp in Kelvins
	tempC -= 273.15; //then convert Kelvins to Celcius
	return tempC;
}

//Return temperature in Fahrenheit
double GenericThermistor::getTempF() {
	double tempF = this->getTempC(); //first get temp in Celcius
	tempF = (tempF * 9.0) / 5.0 + 32; //then convert to Fahrenheit
	return tempF;
}

int GenericThermistor::getADCReading(int pin) {
	int samples[this->numSamples]; //create array to hold ADC readings

	analogRead(pin); //very occasionally you get garbage on first read, so just discard that one.
	//take a number of sample ADC readings and store in array
	for (int i = 0; i < this->numSamples; i++) {
		samples[i] = analogRead(pin);
		delay(10);
	}

	//average the ADC readings stored int the array
	int ADC_average = 0;
	for (int i = 0; i < this->numSamples; i++) {
		ADC_average += samples[i];
	}
	ADC_average /= this->numSamples;

	return ADC_average;
}
