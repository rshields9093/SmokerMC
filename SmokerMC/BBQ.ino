/*
 * Electric smoker project.
 * 
 * Consider using a 3.3V analog reference as described in the sketch "TempProbe_BetaOnlyMethod" to reduce noise
 */


#include <math.h>

//If DEBUG is true will output more details to serial monitor
#define DEBUG true

// resistance at 25 degrees C
#define THERMISTORNOMINAL 1000000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// The beta coefficient of the thermistor (usually 3000-4000)
// 4800 seems to give good results for ET-732 probes at around 200F)
#define BCOEFFICIENT 4800
// the value of the 'other' or 'balance' resistor
#define SERIESRESISTOR 1000000    
 
#define TEMPSCALE 'F' //possible options are 'F', 'C', or 'K'

// What pin to connect the sensor to
#define GRILLPIN 0
#define FOOD1PIN 1
#define FOOD2PIN 2 
#define AMBIENTPIN 3

//Analog pin will be sampled this many times and results averaged for smoother response curve
#define NUMSAMPLES 10  

int samples[NUMSAMPLES];

void setup(void) {
  if(DEBUG) {Serial.begin(9600);}
}
 
void loop(void) {
  float grillTemp = getTemp(GRILLPIN);
  //float food1Temp = getTemp(FOOD1PIN);
  //float food2Temp = getTemp(FOOD2PIN);
  //float ambientTemp = getTemp(AMBIENTPIN);

  if(DEBUG) {
    Serial.print("Grill Temperature: ");
    Serial.println(grillTemp);
  }
  
  delay(5000);
}

float getTemp(int pin) {
  uint8_t i;
  float average;
  float temp;
 
  // take N samples in a row, with a slight delay
  for (i=0; i < NUMSAMPLES; i++) {
   samples[i] = analogRead(pin);
   delay(10);
  }
 
  // average all the samples
  average = 0;
  for (i=0; i < NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;

  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;

  //Calculate temperature using the simplified "B parameter equation" variant of Steinhart-Hart
  //For more info see https://learn.adafruit.com/thermistor/overview?view=all#using-a-thermistor
  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  
  if (TEMPSCALE == 'K') {
    temp = steinhart;
  }
  else if(TEMPSCALE == 'C') {
    steinhart -= 273.15;    // convert to C
    temp = steinhart;
  }
  else if (TEMPSCALE == 'F') {
    steinhart = (steinhart * 9.0) / 5.0 +32; // convert to F
    temp = steinhart;  
  }
  else {
    steinhart = (steinhart * 9.0) / 5.0 +32; // convert to F if cannot determine scale
    temp = steinhart;  
  }
  
  return temp;
}

//helper/debug function calculates resistence from raw ADC reading
float getResistence (float adc) {
  // convert ADC value to resistance
  float resistence = (1023 / adc)  - 1;
  Serial.println(resistence);
  resistence = SERIESRESISTOR / resistence;
  Serial.println(resistence);
  return resistence;
}



