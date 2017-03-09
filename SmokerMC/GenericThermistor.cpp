/*
 * GenericThermistor.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#include "GenericThermistor.h"
//#include <math.h>
#include "Arduino.h"

GenericThermistor::GenericThermistor(int pin, int beta, unsigned long seriesRes, unsigned long thermistorNominal, int numSamples) {
	useBeta = true;
	this->pin = pin; //analog pin the thermistor is on
	this->beta = beta; //Beta coefficient of the thermistor
	this->seriesRes = seriesRes; //value of series resitor in voltage divider
	this->numSamples = numSamples; //for data smoothing, thermistor value will be read this many times and result averaged, default = 5
}

GenericThermistor::GenericThermistor(int pin, float a, float b, float c, unsigned long seriesRes, int numSamples) {
	this->useBeta = false;
	this->pin = pin; //analog pin the thermistor is on
	this->coeff_A = a; //Steinhart-Hart coefficient A
	this->coeff_B = b; //Steinhart-Hart coefficient B
	this->coeff_C = c; //Steinhart-Hart coefficient C
	this->seriesRes = seriesRes; //value of series resitor in voltage divider
	this->numSamples = numSamples; //for data smoothing, thermistor value will be read this many times and result averaged, default = 5
}

//Calculate temperature using the Beta coefficient method
double GenericThermistor::getTempWithBeta(int ADC_Value) {
	double temp;
	//TODO Calculate temp from ADC using Beta
	return temp;
}

//Calculate temperature using the full Steinhart-Hart equation with 3 coefficients
double GenericThermistor::getTempWithSteinhartHart(int ADC_Value) {
	double temp;
	//TODO Calculate temp from ADC using full Steinhart-Hart
	return temp;
}

//Return temperature in Kelvin
double GenericThermistor::getTempK() const {
	double tempK;
	int adc = analogRead(this->pin);
	if(this->useBeta) {tempK = this->getTempWithBeta(adc);}
	else {tempK = this->getTempWithSteinhartHart(adc);}

	tempK = this->getTempWithBeta(tempK);

	//Just illustrating that calling member function with no args works fine
	double foo = this->getTempF();

	return tempK;
}

//Return temperature in Celcius
double GenericThermistor::getTempC() const {
	double tempC = this->getTempK();
	tempC -= 273.15;
	return tempC;
}

//Return temperature in Fahrenheit
double GenericThermistor::getTempF() const {
	double tempF = this->getTempK();
	tempF = (tempF * 9.0) / 5.0 + 32;
	return tempF;
}

