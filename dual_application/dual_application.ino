#include <AD779X.h>

// Pinout
// P3.1 = IC16_SCLK   = D7

// P5.1 = x
// P5.2 = IC15_DOUT   = D8
// P5.3 = IC15_SCLK   = D9
// P5.4 = IC15_DIN    = D10

// P6.1 = x
// P6.2 = IC16_DOUT   = D11
// P6.3 = IC16_DIN    = D12
// P6.4 = IC15_CS & IC16_CS = D13

// Two ADCs with 2.5V reference
#define VREF (2.5) 
AD779X ADC_IC15(VREF);
AD779X ADC_IC16(VREF);

void setup() {
  Serial.begin(115200);

  // Begin(int inPin, int outPin, int clkPin, int csPin)

  // Setup(unsigned char numberOfChannels, unsigned char firstChannel, unsigned char secondChannel, unsigned char thirdChannel)
  // default values: 3 channels, 0...2

  // Config(unsigned char gain, unsigned char coding, unsigned char updateRate, unsigned char buffer, unsigned char refDet, unsigned char burnoutCurrent, unsigned char powerSwitch)
  // default values: gain 124, unipolar, 80dB (50 Hz only) rejection, reference detection disabled, buffer enabled, burnout current disabled, power switch disabled

  ADC_IC15.Begin(10, 8, 9, 13);
  ADC_IC15.Setup(); 
  ADC_IC15.Config(1); // gain of 1

  ADC_IC16.Begin(12, 11, 7, 13);
  ADC_IC16.Setup();
  ADC_IC16.Config(1); // gain of 1
}

void loop() {
  if (ADC_IC15.Update() && ADC_IC16.Update()) {
    Serial.print(ADC_IC15.readmV(0));
    Serial.print(" ");
    Serial.println(ADC_IC16.readmV(0));
  }
}
