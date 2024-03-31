#include <Arduino.h>
#include "Nos_methodes.h"


  

const int ledPin = LED_BUILTIN; // pin to use for the LED

void setup() {

  Serial.begin(9600);
  //while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  Init_Propulsion();

  
  //PORT->Group[g_APinDescription[a].ulPort].DIRSET.reg = (uint32_t)(1<<g_APinDescription[a].ulPin);


  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }
  
  BLE.setLocalName("RoTor"); 
  BLE.setDeviceName("Aspirateur");
  Init_PropulsionService();
  //Init_CapteursService();


  // start advertising
  Serial.println("BLE LED Peripheral");
  Serial.print("Local address is: ");
  Serial.println(BLE.address());
  
  BLE.advertise();
  attachInterrupt(digitalPinToInterrupt(INT_MUR),Interrupt_Mur,RISING);
  attachInterrupt(digitalPinToInterrupt(INT_SOL),Interrput_Sol,RISING);
}

void loop() {
  // listen for Bluetooth® Low Energy peripherals to connect:
  BLEDevice central = BLE.central();
      
  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // put your code here...

    }
    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  } 
}




