/*
 * GenericThermistor.h
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#ifndef GENERICTHERMISTOR_H_
#define GENERICTHERMISTOR_H_

class GenericThermistor {
private:

public:
	//Constructors
	GenericThermistor(int pin, int beta, unsigned long seriesRes, unsigned long thermistorNominalRes,
			double thermistorNominalTemp, bool isPullUp=false, int numSamples=5);
	GenericThermistor(int pin, double a, double b, double c, unsigned long seriesRes,
			bool isPullUp=false, int numSamples=5);

	//Public Variables
	bool useBeta; //use the Beta equation? If false use the full Steinhart-Hart equation
	bool isPullUp; //is thermistor tied to Vcc?  If not it is tied to GND and the math is a bit different
	int pin;  //the analog pin which this resistor is to be read from
	int beta; //the Beta coefficient, if using the Beta variant of Steinhart-Hart
	int numSamples; //analog pin will be read this many times and result averaged for data smoothing
	unsigned long thermistorNominalResistance; //the nominal resistance of the thermistor
	double thermistorNominalTemperature; //the temperature at which the thermistor's nominal resistance is reported, usually 25C.
	unsigned long seriesRes; //the value of the "other" resistor used in the voltage divider
	double coeff_A, coeff_B, coeff_C; //the Steinhart-Hart coefficients

	double getTempC() const;
	double getTempF() const;
	double getTempK() const;
	double getTempWithBeta(int ADC_Value);
	double getTempWithSteinhartHart(int ADC_Value);
};

#endif /* GENERICTHERMISTOR_H_ */
