#include "Arduino.h"
#include "GenericThermistor.h"
//#include "SoftwareSerial.h"

//temperature "probes" to be used, specific setup details in the setup() function
GenericThermistor ambientProbe, grillProbe, food1Probe;

//variables to hold temperature readings
double ambientTemp, grillTemp, food1Temp;

//The setup function is called once at startup of the sketch
void setup() {
	//setup parameters that apply to all temp sensors
	bool isPullUp = true;
	int numSamples = 5;

	//setup parameters for Ambient Temperature Sensor
	int ambientPin = 0;
	double ambient_a = 0.001129148;
	double ambient_b = 0.000234125;
	double ambient_c = 0.0000000876741;
	unsigned long ambientSerRes = 10000;
	double ambientTempOffset = 0.0;
	ambientProbe = new GenericThermistor(ambientPin, ambient_a, ambient_b, ambient_c,
			ambientSerRes, isPullUp, numSamples, ambientTempOffset);

	//setup parameters for Grill Temperature Probe
	int grillPin = 1;
	int grillBeta = 4098;
	unsigned long grillSerRes = 1000000;
	unsigned long grillNomRes = 1000000;
	double grillNomTemp = 25;
	double grillTempOffset = 0.0;
	grillProbe = new GenericThermistor(grillPin, grillBeta, grillSerRes, grillNomRes,
			grillNomTemp, isPullUp, numSamples, grillTempOffset);

	//setup parameters for Food1 Probe
	int food1Pin = 2;
	double food1_a = 1.102800003e-3;
	double food1_b = 1.268962063e-4;
	double food1_c = 1.820232864e-7;
	unsigned long food1SerRes = 10000;
	double food1TempOffset = 0.0;
	food1Probe = new GenericThermistor(food1Pin, food1_a, food1_b, food1_c,
			food1SerRes, isPullUp, numSamples, food1TempOffset);

	Serial.begin(9600);
}

// The loop function is called in an endless loop
void loop() {
	ambientTemp = ambientProbe.getTempF();
	grillTemp = grillProbe.getTempF();
	food1Temp = food1Probe.getTempF();

	Serial.print("Ambient Temp: ");
	Serial.print(ambientTemp);
	Serial.print(", Grill Temp: ");
	Serial.print(grillTemp);
	Serial.print(", Food1 Temp: ");
	Serial.print(food1Temp);
	Serial.println();

	delay(5000);
}
