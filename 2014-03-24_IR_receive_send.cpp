/*
 *  IR Remote for Arduino and Raspberry Pi
 *
 *  Copyright (C) 2013 Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/> .
 *
 *  Version 0.1
 *  Author: Luis Martin
 */

// We need to use the 'raw' pin reading methods
// because timing is very important here and the digitalRead()
// procedure is slower!

#include "arduPi.h"

#include <iostream>

void SendIRCode();
void printpulses();

#define IRpin 2

// The maximum pulse we'll listen for - 65 milliseconds is a long time
#define MAXPULSE 65000

// Timing resolution 
#define RESOLUTION 20

int IRledPin =  3;      // IR emitter LED connected to digital pin 3
int orangeLedPin =  7;  // Orange LED connected to digital pin 7
int buttonPin1 = 4;     // "Send" push-button connected to digital pin 4
int blueLedPin =  6;    // Blue LED connected to digital pin 6
int buttonPin2 = 5;     // "Receive" push-button connected to digital pin 5

int buttonState1 = 0;        
int buttonState2 = 0;

// Store up to 100 pulse pairs 
uint16_t pulses[100][2]; // Pair is high and low pulse
uint8_t currentpulse = 0; // Index for pulses we're storing
uint8_t sendpulse = 0; // Index for send pulses

void setup(void) {
	
	std::cout << "Setup" << std::endl;
	
  // Initialize the Orange LED pin as an output
  pinMode(orangeLedPin, OUTPUT);      
  // Initialize the "Send" push-button pin as an input
  pinMode(buttonPin1, INPUT);  
  // Initialize the Orange LED pin as an output
  pinMode(blueLedPin, OUTPUT);      
  // Initialize the "Send" push-button pin as an input
  pinMode(buttonPin2, INPUT);
  // Set uart baudrate
  Serial.begin(9600);
}

void loop(void)
{	
	// Read the state of the "Send" push-button value
	buttonState1 = digitalRead(buttonPin1);
	// Read the state of the "Receive" push-button value
	buttonState2 = digitalRead(buttonPin2);

	if (buttonState1 == HIGH) {
		  
		std::cout << "Sending IR signal" << std::endl;
		digitalWrite(orangeLedPin, HIGH); 
		delay(200);
		digitalWrite(orangeLedPin, LOW); 
		delay(200);
		
		SendIRCode();
		delay(15);  // wait 15 milliseconds before sending it again
		SendIRCode();  // repeat IR code if it is neccesary
	 
		//delay(3000);  // wait 3 seconds to resend the code
    }

	if ((buttonState2==HIGH) || (currentpulse != 0)){

	if (buttonState2==HIGH){
		std::cout << "Ready to decode IR!" << std::endl;
		digitalWrite(blueLedPin, HIGH); 
		delay(200);
		digitalWrite(blueLedPin, LOW); 
		delay(200);
	}

	uint16_t highpulse, lowpulse; // Temporary storage timing
	highpulse = lowpulse = 0; // Start out with no pulse length

	while (digitalRead(IRpin)) {
		// count off another few microseconds
		highpulse++;
		delayMicroseconds(RESOLUTION);

		// If the pulse is too long, we 'timed out' - either nothing
		// was received or the code is finished, so print what
		// we've grabbed so far, and then reset
		if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
			printpulses();
			sendpulse=currentpulse;
			currentpulse=0;
			return;
		}
	}
	// we didn't time out so lets stash the reading
	pulses[currentpulse][0] = highpulse;

	// same as above
	while (! digitalRead(IRpin)) {
		// pin is still LOW
		lowpulse++;
		delayMicroseconds(RESOLUTION);
		if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
			printpulses();
			sendpulse=currentpulse;
			currentpulse=0;
			return;
		}
	}
	pulses[currentpulse][1] = lowpulse;

	// we read one high-low pulse successfully, continue!
	currentpulse++;

	}
}

void printpulses(void)
{
  printf("\n\r\n\rReceived:\n");
  for (uint8_t i = 0; i < currentpulse; i++) {
  
    if (i != 0){
    printf("delayMicroseconds(");
    printf("%d",pulses[i][0] * RESOLUTION);
    printf(");\n");
    }
    printf("pulseIR(");
    printf("%d",pulses[i][1] * RESOLUTION);
    printf(");\n");
  }
  delay(1000);
  digitalWrite(orangeLedPin, HIGH); 
  delay(200);
  digitalWrite(orangeLedPin, LOW); 
  delay(200);
  
/*  // Print it in a 'array' format
  printf("int IRsignal[] = {\n");
  printf("// ON, OFF (in 10's of microseconds)\n");
  for (uint8_t i = 0; i < currentpulse-1; i++) {
    printf("\t"); // tab
    printf(pulses[i][1] * RESOLUTION / 10, DEC);
    printf(", ");
    printf(pulses[i+1][0] * RESOLUTION / 10, DEC);
    printf(",\n");
  }
  printf("\t"); // tab
  printf(pulses[currentpulse-1][1] * RESOLUTION / 10, DEC);
  printf(", 0};");
*/ 
}

// This procedure sends a 38KHz pulse to the IRledPin for a certain # of microseconds.
void pulseIR(long microsecs)
{
  while (microsecs > 0) {
   // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // 3 microseconds
   
   /* hang out for 10 microseconds, 
                                     you can also change this to 9 if its not working */
   delayMicroseconds(10);
   digitalWrite(IRledPin, LOW);   // 3 microseconds
   
   /* hang out for 10 microseconds, 
                                     you can also change this to 9 if its not working */
   delayMicroseconds(10);
 
   // So 26 microseconds altogether
   microsecs -= 26;
  }
 
}
 
void SendIRCode()
{
	std::cout << "SendIRCode" << std::endl;

	for (uint8_t i = 0; i < sendpulse; i++) {

		if (i != 0){
			delayMicroseconds(pulses[i][0] * RESOLUTION);
		}

		pulseIR(pulses[i][1] * RESOLUTION);
	}
}

int main(){
	setup();
	while (1) loop();
	return 0;
}
