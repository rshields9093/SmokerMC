/*
 * This sketch assumes the thermistor is on the Vcc end of the voltage divider. You may get negative temps otherwise. 
 * 
 * Testing on hot water this sketch is reading temperatures ~4 degrees too low with food probe 
 * and ~4 degrees too high with grill probe as compared to readings on my ThermoWorks food thermometer.
 * 
 * Also note that when using the ET-732 food probe with the Maverick unit it came with it was reading 4 -5 degrees higher than 
 * the ThermoWorks.  
 * 
 * 
 * 
 * 
 */


#include <math.h>

#define NUMSAMPLES 10

int samples[NUMSAMPLES];

//ET-732 Steinhart coefficients per HeaterMeter project on GitHub
//5.36924e-4,1.91396e-4,6.60399e-8 

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(1000000.0*((1024.0/RawADC-1))); 
 //Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = 1 / (5.36924e-4 + (1.91396e-4 + (6.60399e-8 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

void setup() {
 Serial.begin(9600);
}

void loop() {             
  
  uint8_t i;
  float average;
 
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(0);
   delay(10);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  double temp;            
  temp=Thermistor(average);   
  Serial.print("Temperature = ");
  Serial.print(temp);   
  Serial.println(" F");
  delay(1000);            
}



