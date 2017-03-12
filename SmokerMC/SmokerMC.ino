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
	ambientProbe.isPullUp = true;
	ambientProbe.useBeta = false;
	ambientProbe.numSamples = 5;
	ambientProbe.pin = 0;
	ambientProbe.coeff_A = 0.001129148;
	ambientProbe.coeff_B = 0.000234125;
	ambientProbe.coeff_C = 0.0000000876741;
	ambientProbe.seriesRes = 10000.0;
	ambientProbe.tempOffsetK = 0.0;

	//setup parameters for Grill Temperature Probe
	grillProbe.isPullUp = true;
	grillProbe.useBeta = false;
	grillProbe.pin = 1;
	grillProbe.coeff_A = 1.102800003e-3;
	grillProbe.coeff_B = 1.268962063e-4;
	grillProbe.coeff_C = 1.820232864e-7;
	grillProbe.seriesRes = 1000000;
	grillProbe.numSamples = 5;
	grillProbe.tempOffsetK = 0.0;

	//setup parameters for Food1 Probe
	food1Probe.isPullUp = true;
	food1Probe.useBeta = false;
	food1Probe.pin = 2;
	food1Probe.coeff_A = 1.102800003e-3;
	food1Probe.coeff_B = 1.268962063e-4;
	food1Probe.coeff_C = 1.820232864e-7;
	food1Probe.seriesRes = 1000000;
	food1Probe.numSamples = 5;
	food1Probe.tempOffsetK = 0.0;

	Serial.begin(9600);
}

// The loop function is called in an endless loop
void loop() {
	ambientTemp = ambientProbe.getTempF();
	grillTemp = grillProbe.getTempF();
	food1Temp = food1Probe.getTempF();

	//for human consumption
	/*Serial.print("Ambient Temperature: ");
	Serial.print(ambientTemp);
	Serial.print(", Grill Temp: ");
	Serial.print(grillTemp);
	Serial.print(", Food1 Temp: ");
	Serial.print(food1Temp);
	Serial.println();*/

	//for copy/paste to CVS file
	Serial.print(ambientTemp);
	Serial.print(",");
	Serial.print(grillTemp);
	Serial.print(",");
	Serial.print(food1Temp);
	Serial.println();

	delay(5000);
}
