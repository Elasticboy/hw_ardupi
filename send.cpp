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

#include "arduPi.h"
#include <iostream>

void SendIRCode();

int IRledPin =  3;      // IR emitter LED connected to digital pin 3
int orangeLedPin =  7;  // Orange LED connected to digital pin 7
int buttonPin1 = 4;     // "Send" push-button connected to digital pin 4
int buttonState1 = 0;  

void setup()   {                
  // Initialize the Orange LED pin as an output
  pinMode(orangeLedPin, OUTPUT);      
  // Initialize the "Send" push-button pin as an input
  pinMode(buttonPin1, INPUT);
  // Initialize the IR digital pin as an output
  pinMode(IRledPin, OUTPUT);      
  // Set uart baudrate
  Serial.begin(9600);
}
 
void loop()   {
  // Read the state of the "Send" push-button value
  buttonState1 = digitalRead(buttonPin1);
  
  if (buttonState1 == HIGH) {   
   printf("Sending IR signal\n");
    digitalWrite(orangeLedPin, HIGH); 
    delay(200);
    digitalWrite(orangeLedPin, LOW); 
    delay(200);
    
    for (int i = 0; i < 20; i++) {
		SendIRCode();
		delay(15);  // wait 15 milliseconds before sending it again
		//SendIRCode();  // repeat IR code if it is neccesary
	}
 
    delay(3000);  // wait 3 seconds to resend the code
    }
}
 
// This procedure sends a 38KHz pulse to the IRledPin for a certain # of microseconds.
void pulseIR(long microsecs) {
 

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
 
void SendIRCode() {
	
	std::cout << "sendIR" << std::endl;
	
	pulseIR(1440);
	delayMicroseconds(420);
	pulseIR(1160);
	delayMicroseconds(540);
	pulseIR(520);
	delayMicroseconds(540);
	pulseIR(1160);
	delayMicroseconds(560);
	pulseIR(560);
	delayMicroseconds(140);
	pulseIR(20);
	delayMicroseconds(540);
	pulseIR(1180);
	delayMicroseconds(320);
	pulseIR(520);
	delayMicroseconds(16180);
	pulseIR(2140);
	delayMicroseconds(500);
	pulseIR(1140);
	delayMicroseconds(560);
	pulseIR(560);
	delayMicroseconds(540);
	pulseIR(700);
	delayMicroseconds(500);
	pulseIR(600);
	delayMicroseconds(980);
	pulseIR(1140);
	delayMicroseconds(520);
	pulseIR(560);
	delayMicroseconds(520);
	pulseIR(540);
	delayMicroseconds(520);
	pulseIR(600);
	delayMicroseconds(520);
	pulseIR(580);
	delayMicroseconds(16080);
	pulseIR(1400);
	delayMicroseconds(520);
	pulseIR(400);
	delayMicroseconds(520);
	pulseIR(600);
	delayMicroseconds(520);
	pulseIR(1140);
	delayMicroseconds(480);
	pulseIR(580);
	delayMicroseconds(360);
	pulseIR(140);
	delayMicroseconds(8560);
	pulseIR(940);
	delayMicroseconds(500);
	pulseIR(560);
	delayMicroseconds(520);
	pulseIR(860);
	delayMicroseconds(500);
	pulseIR(600);
	delayMicroseconds(520);
	pulseIR(1160);
	delayMicroseconds(140);
	pulseIR(600);
	delayMicroseconds(520);
	pulseIR(560);
	delayMicroseconds(40);
	pulseIR(260);
	delayMicroseconds(420);
	pulseIR(560);
	delayMicroseconds(520);
	pulseIR(620);
	delayMicroseconds(16620);
	pulseIR(2200);
	delayMicroseconds(540);
	pulseIR(1140);
	delayMicroseconds(160);
	pulseIR(560);
	delayMicroseconds(560);
	pulseIR(720);
	delayMicroseconds(160);
	pulseIR(1100);
	delayMicroseconds(560);
	pulseIR(540);
	delayMicroseconds(540);
	pulseIR(540);
	delayMicroseconds(520);
	pulseIR(580);
	delayMicroseconds(540);
	pulseIR(560);
	delayMicroseconds(8340);
	pulseIR(60);
	delayMicroseconds(460);
	pulseIR(600);
	delayMicroseconds(540);
	pulseIR(920);
	delayMicroseconds(240);
	pulseIR(560);
	delayMicroseconds(560);
	pulseIR(240);
	delayMicroseconds(80);
	pulseIR(580);
	delayMicroseconds(520);
	pulseIR(580);
	delayMicroseconds(17140);
	pulseIR(2240);
	delayMicroseconds(500);
	pulseIR(1200);
	delayMicroseconds(540);
	pulseIR(560);
	delayMicroseconds(200);
	pulseIR(1140);
	delayMicroseconds(540);
	pulseIR(160);
	delayMicroseconds(240);
	pulseIR(500);
	delayMicroseconds(560);
	pulseIR(1140);
	delayMicroseconds(480);
	pulseIR(600);
	delayMicroseconds(500);
	pulseIR(600);
	delayMicroseconds(560);
	pulseIR(560);
	delayMicroseconds(540);
	pulseIR(200);
	delayMicroseconds(16840);
	pulseIR(1840);
	delayMicroseconds(60);
	pulseIR(1160);
	delayMicroseconds(500);
	pulseIR(580);
	delayMicroseconds(500);
	pulseIR(1120);
	delayMicroseconds(540);
	pulseIR(560);
	delayMicroseconds(540);
	pulseIR(580);
	delayMicroseconds(280);
	pulseIR(1040);
	delayMicroseconds(560);
	pulseIR(240);
	delayMicroseconds(15720);
	pulseIR(2000);
	delayMicroseconds(520);
	pulseIR(1160);
	delayMicroseconds(520);
	pulseIR(560);
	delayMicroseconds(540);
	pulseIR(1160);
	delayMicroseconds(220);
	pulseIR(560);
	delayMicroseconds(520);
	pulseIR(1200);
	delayMicroseconds(540);
	pulseIR(580);
	delayMicroseconds(540);
	pulseIR(580);
	delayMicroseconds(540);
	pulseIR(560);
	delayMicroseconds(560);
	pulseIR(560);
	delayMicroseconds(14160);
	pulseIR(1600);
	delayMicroseconds(540);
	pulseIR(680);
	delayMicroseconds(340);
	pulseIR(500);
	delayMicroseconds(540);
	pulseIR(1180);
	delayMicroseconds(540);
	pulseIR(560);
	delayMicroseconds(560);
	pulseIR(560);
	delayMicroseconds(560);
	pulseIR(1160);
	delayMicroseconds(40);
	pulseIR(560);
	delayMicroseconds(520);
	pulseIR(560);
}

int main (){
	setup();
	while (1) loop();
	return 0;
}
