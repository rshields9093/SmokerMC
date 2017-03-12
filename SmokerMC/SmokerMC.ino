#include "Arduino.h"
#include "GenericThermistor.h"
//#include "SoftwareSerial.h"

//variables to hold temperature readings
double ambientTemp, grillTemp, food1Temp;

//create global instances of thermistor objects (they will be configured in setup() function below)
GenericThermistor ambientProbe, grillProbe, food1Probe;

//The setup function is called once at startup of the sketch
void setup() {

	//set up Ambient Temperature Sensor parameters
	ambientProbe.isPullUp = false;
	ambientProbe.useBeta = false;
	ambientProbe.numSamples = 5;
	ambientProbe.pin = 0;
	ambientProbe.coeff_A = 0.001129148;
	ambientProbe.coeff_B = 0.000234125;
	ambientProbe.coeff_C = 0.0000000876741;
	ambientProbe.seriesRes = 10000.0;
	ambientProbe.tempOffsetK = 0.0;

//	//setup parameters for Grill Temperature Probe
//	int grillPin = 1;
	grillProbe.beta = 4094.15;
//	unsigned long grillSerRes = 1000000;
//	unsigned long grillNomRes = 1000000;
//	double grillNomTemp = 25;
//	double grillTempOffset = 0.0;
//	grillProbe = new GenericThermistor(grillPin, grillBeta, grillSerRes, grillNomRes,
//			grillNomTemp, isPullUp, numSamples, grillTempOffset);
//
//	//setup parameters for Food1 Probe
//	int food1Pin = 2;
//	double food1_a = 1.102800003e-3;
//	double food1_b = 1.268962063e-4;
//	double food1_c = 1.820232864e-7;
//	unsigned long food1SerRes = 10000;
//	double food1TempOffset = 0.0;
//	food1Probe = new GenericThermistor(food1Pin, food1_a, food1_b, food1_c,
//			food1SerRes, isPullUp, numSamples, food1TempOffset);

	Serial.begin(9600);
}

// The loop function is called in an endless loop
void loop() {
	ambientTemp = ambientProbe.getTempF();
//	grillTemp = grillProbe.getTempF();
//	food1Temp = food1Probe.getTempF();

	Serial.print("Ambient Temperature: ");
	Serial.print(ambientTemp);
	Serial.println("F");



//	Serial.print(", Grill Temp: ");
//	Serial.print(grillTemp);
//	Serial.print(", Food1 Temp: ");
//	Serial.print(food1Temp);
	Serial.println();

	delay(5000);
}
