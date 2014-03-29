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

int orangeLedPin =  7;  // Orange LED connected to digital pin 7
int buttonPin1 = 4;     // "Send" push-button connected to digital pin 4
int blueLedPin =  6;    // Blue LED connected to digital pin 6
int buttonPin2 = 5;     // "Receive" push-button connected to digital pin 5

int buttonState1 = 0;        
int buttonState2 = 0; 

void setup() {
  // Initialize the Orange LED pin as an output
  pinMode(orangeLedPin, OUTPUT);      
  // Initialize the "Send" push-button pin as an input
  pinMode(buttonPin1, INPUT);  
  // Initialize the Orange LED pin as an output
  pinMode(blueLedPin, OUTPUT);      
  // Initialize the "Send" push-button pin as an input
  pinMode(buttonPin2, INPUT);
}

void loop(){
  // Read the state of the "Send" push-button value
  buttonState1 = digitalRead(buttonPin1);
  printf("%d\n",buttonState1);
  // Read the state of the "Send" push-button value
  buttonState2 = digitalRead(buttonPin2);
  printf("%d\n",buttonState2);

  if (buttonState1 == HIGH) {     
    // Turn LED on:    
    digitalWrite(orangeLedPin, HIGH);  
  } 
  else {
    // Turn LED off:
    digitalWrite(orangeLedPin, LOW); 
  }

  if (buttonState2 == HIGH) {     
    // Turn LED on:    
    digitalWrite(blueLedPin, HIGH);  
  } 
  else {
    // Turn LED off:
    digitalWrite(blueLedPin, LOW); 
  }
}

int main (){
	setup();
	while(1) loop();
	return 0;
}