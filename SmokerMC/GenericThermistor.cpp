/*
 * GenericThermistor.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#include "GenericThermistor.h"
#include <math.h>
#include "Arduino.h"

GenericThermistor::GenericThermistor(int pin, int beta, unsigned long seriesRes,
		unsigned long thermistorNominalRes, double thermistorNominalTemp, bool isPullUp, int numSamples,
		double tempOffset) {
	this->useBeta = true;
	this->pin = pin; //analog pin the thermistor is on
	this->beta = beta; //Beta coefficient of the thermistor
	this->seriesRes = seriesRes; //value of series resitor in voltage divider
	this->thermistorNominalResistance = thermistorNominalRes; //the nominal resistance of the thermistor
	this->thermistorNominalTemperature = thermistorNominalTemp; //the temperature at which the thermistor's nominal resistance is reported, usually 25C.
	this->isPullUp = isPullUp; //whether or not the thermistor is tied to Vcc (othereise it is pull-down configuration)
	this->numSamples = numSamples; //for data smoothing, thermistor value will be read this many times and result averaged, default = 5
	this->tempOffsetK = tempOffset; //plus or minus calibration adjustment to final temp, in Kelvin
}

GenericThermistor::GenericThermistor(int pin, double a, double b, double c, unsigned long seriesRes,
		bool isPullUp, int numSamples, double tempOffset) {
	this->useBeta = false;
	this->pin = pin; //analog pin the thermistor is on
	this->coeff_A = a; //Steinhart-Hart coefficient A
	this->coeff_B = b; //Steinhart-Hart coefficient B
	this->coeff_C = c; //Steinhart-Hart coefficient C
	this->seriesRes = seriesRes; //value of series resitor in voltage divider
	this->isPullUp = isPullUp; //whether or not the thermistor is tied to Vcc (othereise it is pull-down configuration)
	this->numSamples = numSamples; //for data smoothing, thermistor value will be read this many times and result averaged, default = 5
	this->tempOffsetK = tempOffset; //plus or minus calibration adjustment to final temp, in Kelvin
}

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

	if(this->isPullUp) {
		temp = log(this->seriesRes / ((1024.0 / ADC_Value - 1))); // for pull-up configuration
	} else {
		temp = log(this->seriesRes * ((1024.0 / ADC_Value - 1))); // for pull-down configuration
	}

	temp = 1 / (this->coeff_A + (this->coeff_B + (this->coeff_C * temp * temp ))* temp );

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

	if(this->useBeta) {tempK = this->getTempWithBeta(ADC_average);}
	else {tempK = this->getTempWithSteinhartHart(ADC_average);}

	tempK += this->tempOffsetK;

	return tempK;
}

//Return temperature in Celcius
double GenericThermistor::getTempC() {
	double tempC = this->getTempK();
	tempC -= 273.15;
	return tempC;
}

//Return temperature in Fahrenheit
double GenericThermistor::getTempF() {
	double tempF = this->getTempK();
	tempF = (tempF * 9.0) / 5.0 + 32;
	return tempF;
}

