#include "Arduino.h"
#include "Arduino.h"

#include "pitches.h"
//这部分是用英文对应了拍子，这样后面也比较好看
int tune0[]=
{
  G0, G6, GH1,
  GH6, GH3, GH2, GH1,
  GH5, G5, GH1,
  GH4, GH3, G6, G7,
  G7, GH3,
  GH1,
  GL6, GL7,
  G1, G5, G2, G3,
  G4, G2,
};

float duration0[]=
{
  0.5, 0.25, 0.25,
  0.5, 0.5, 0.5, 0.5,
  1, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.5,
  1, 1,
  2,
  1,1,
  0.5, 0.5, 0.5, 0.5,
  1,1,
};

int tune1[] = 
{
  G0, G5, G1, G2,
  G2, G0, G2, G3,
  G4, G3, G4, G4, G5, G4,
  G3, G0,
  G0, G3, GL6, G2,
  G2, G0, GL6, GL7,

  G1, GL7, G1, G1, G2, G2,
  G2, G0,
  G0, G5, G1, G2,
  G2, G0, G2, G3,
  G4, G3, G4, G4, G5, G5, G4,
  G3, G0,

  G0, G0, G3, G3, G6, G3,
  G3, G2, G0, GL6, GL7,
  G1, GL7, G1, G1, G2, G2,
  G2, G0,
  G0, G1, G2,
  G3, G5, G5, G5, G0, G5,

  G5, G6, G4, G5, G5, G4,
  G3, G0, G6, G7,
  GH1, G7, GH1, GH1, G3, G2,
  G2, G6, G6, G6, G0, G6,
  G6, G6, G6, G6, G5, G5,

  G5,
  G6, G2, G7,
  G1, GL5, G1, G5,
  G4, G3, G4, G4, G5, G6, G5,
  G5, G1, GH1,
  G7, G6, G6,

  G5, G6, G4, G3, G4,
  G4, GL6, GL7, G1,
  G4, G5, G5, G5, G3,
  G3, G2, G2,
  G0, GL5, G1, G5,
  G4, G3, G4, G4, G6, G5,
  
  G5, G0, G5,
  G5, G5, G6, G6, G7, G7,
  G7, GH1, GH1, GH1,
  GH1, G0, GH1, G7, GH1, G7,
  G6, G6, G6, G6, G6,

  G6, G0, 
  G6, G3, G2, G1, G5,
  G5, G0, G3,
  G4, G3, GL6, GL6,
  GL7, G3, G2,
  G1,
  GL7, GL6,
  G3,
  G2,

};

float duration1[]=
{
  1, 0.5, 0.25, 0.25,
  1, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,
  1, 1,
  1, 0.5, 0.25, 0.25,
  1, 0.5, 0.25, 0.25,

  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,
  1, 1,
  1, 0.5, 0.25, 0.25,
  1, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.25, 0.5, 0.125, 0.125,
  1,1,

  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,
  0.25, 0.75, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,
  1, 1,
  1, 0.5, 0.5,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25,

  0.5, 0.5, 0.25, 0.5, 0.125, 0.125,
  1, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25,

  2,
  0.5, 0.5, 1,
  0.5, 0.5, 0.5, 0.5,
  0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25,
  1, 0.5, 0.5,
  0.5, 0.25, 1,

  0.5, 0.5, 0.5, 0.25, 0.25,
  0.25, 0.5, 0.5, 0.5,
  0.5, 0.5, 0.5, 0.25, 0.25,
  0.25, 0.75, 1,
  0.5, 0.5, 0.5, 0.5,
  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,

  1.5, 0.25, 0.25, 
  0.5, 0.25, 0.25, 0.25, 0.5, 0.25,
  0.5, 0.25, 0.25, 1,
  0.5, 0.25, 0.25, 0.5, 0.25, 0.25,
  0.5, 0.25, 0.25, 1,

  1, 1,
  0.5, 0.5, 0.5, 0.25, 0.25,
  1.5, 0.25, 0.25,
  0.5, 0.5, 0.5, 0.5,
  1, 0.5, 0.5,
  2,
  1, 1,
  2,
  2,
};

int length0;
int length1;
int tonePin=8;

void setup()
{
  pinMode(tonePin,OUTPUT);
  length0 = sizeof(tune0)/sizeof(tune0[0]);
  length1 = sizeof(tune1)/sizeof(tune1[0]);
}

void loop()
{
  for (int x = 0; x < length0; ++x)
  {
    tone(tonePin, tune0[x]);
    delay(800*duration0[x]);
    //noTone(tonePin);
  }
  for(int x=0;x<length1;x++)
  {
    tone(tonePin,tune1[x]);
    delay(800*duration1[x]);
    noTone(tonePin);
  }
    for(int x=0;x<length1;x++)
  {
    tone(tonePin,tune1[x]);
    delay(800*duration1[x]);
    noTone(tonePin);
  }
  delay(5000);
}



extern "C" void __cxa_pure_virtual() { while (1) ; }
#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

