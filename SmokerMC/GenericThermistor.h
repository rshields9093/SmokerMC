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
	GenericThermistor(int pin, int beta, unsigned long seriesRes, unsigned long thermistorNominal, int numSamples=5);
	GenericThermistor(int pin, float a, float b, float c, unsigned long seriesRes, int numSamples=5);

	//Public Variables
	bool useBeta;
	int pin, beta, numSamples;
	unsigned long thermistorNominal, seriesRes;
	double coeff_A, coeff_B, coeff_C;

	double getTempC() const;
	double getTempF() const;
	double getTempK() const;
	double getTempWithBeta(int ADC_Value);
	double getTempWithSteinhartHart(int ADC_Value);
};

#endif /* GENERICTHERMISTOR_H_ */
