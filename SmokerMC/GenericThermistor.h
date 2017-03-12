/*
 * GenericThermistor.h
 *
 *  Created on: Mar 4, 2017
 *      Author: Robert Shields
 */

#ifndef GENERICTHERMISTOR_H_
#define GENERICTHERMISTOR_H_

//Set to 1 to include debug code, set to 0 to exclude for smaller final size.
#define THERMISTORDEBUG 1

class GenericThermistor {
private:
	double getTempWithBeta(int ADC_Value);
	double getTempWithSteinhartHart(int ADC_Value);

public:

	//Public Variables
	bool useBeta; //use the Beta equation? If false use the full Steinhart-Hart equation
	bool isPullUp; //is thermistor tied to Vcc?  If not it is tied to GND and the math is a bit different
	int pin;  //the analog pin which this resistor is to be read from
	double beta; //the Beta coefficient, if using the Beta variant of Steinhart-Hart
	int numSamples; //analog pin will be read this many times and result averaged for data smoothing
	double tempOffsetK; //
	unsigned long thermistorNominalResistance; //the nominal resistance of the thermistor
	double thermistorNominalTemperature; //the temperature at which the thermistor's nominal resistance is reported, usually 25C.
	double seriesRes; //the value of the "other" resistor used in the voltage divider
	double coeff_A, coeff_B, coeff_C; //the Steinhart-Hart coefficients

	int getADCReading(int pin);
	double getTempC();
	double getTempF();
	double getTempK();
};

#endif /* GENERICTHERMISTOR_H_ */
