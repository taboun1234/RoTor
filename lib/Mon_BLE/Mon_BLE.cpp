#include "Mon_BLE.h"

    // Service pour gérer deux moteurs
// Bluetooth® Low Energy Propulsion Service 7bfaa100-63c7-4d86-a860-05b13af7cff
BLEService PropulsionService("7bfaa100-63c7-4d86-a860-05b13af7cffd");

// Bluetooth® Low Energy Puissance et sens Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic GaucheCharacteristic("7bfaa101-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
BLEByteCharacteristic DroiteCharacteristic("7bfaa102-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
BLEByteCharacteristic SensGaucheCharacteristic("7bfaa103-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
BLEByteCharacteristic SensDroiteCharacteristic("7bfaa104-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);

void callbackPGauche(BLEDevice central, BLECharacteristic characteristic);
void callbackPDroite(BLEDevice central, BLECharacteristic characteristic);
void callbackSGauche(BLEDevice central, BLECharacteristic characteristic);
void callbackSDroite(BLEDevice central, BLECharacteristic characteristic);

//BLEDescriptor batteryLevelDescriptor("2902", "millis en bonsoir");
BLEDescriptor batteryLevelDescriptor2("2901", "millis en bonsoir sboub blubs");

void Init_PropulsionService(){
    
    // set advertised local name and service UUID:
    BLE.setLocalName("ZGEG"); 
    BLE.setDeviceName("BONSOIR");
    BLE.setAdvertisedService(PropulsionService);

    //switchCharacteristic.addDescriptor(batteryLevelDescriptor);
    GaucheCharacteristic.addDescriptor(batteryLevelDescriptor2);

    // add the characteristic to the service
    PropulsionService.addCharacteristic(GaucheCharacteristic);
    PropulsionService.addCharacteristic(DroiteCharacteristic);
    PropulsionService.addCharacteristic(SensGaucheCharacteristic);
    PropulsionService.addCharacteristic(SensDroiteCharacteristic);
    
    // add service
    BLE.addService(PropulsionService);

    // set the initial value for the characeristic:
    GaucheCharacteristic.writeValue(0);
    DroiteCharacteristic.writeValue(0);
    SensDroiteCharacteristic.writeValue(0);
    SensGaucheCharacteristic.writeValue(0);

    GaucheCharacteristic.setEventHandler(BLEWritten, callbackPGauche);
    DroiteCharacteristic.setEventHandler(BLEWritten, callbackPDroite);
    SensDroiteCharacteristic.setEventHandler(BLEWritten, callbackSDroite);
    SensGaucheCharacteristic.setEventHandler(BLEWritten, callbackSGauche);
    /*digitalWrite(P_GAUCHE,GaucheCharacteristic.value());
    digitalWrite(P_DROITE,DroiteCharacteristic.value());
    digitalWrite(S_DROITE,DroiteCharacteristic.value());
    digitalWrite(S_GAUCHE,GaucheCharacteristic.value());*/
}


void callbackPGauche(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Puissance gauche = ");
  Serial.println(GaucheCharacteristic.value());
  //analogWrite(P_GAUCHE,GaucheCharacteristic.value());
}

void callbackPDroite(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Puissance droite = ");
  Serial.println(DroiteCharacteristic.value());
  //analogWrite(P_DROITE,DroiteCharacteristic.value());
}

void callbackSDroite(BLEDevice central, BLECharacteristic characteristic){

  Serial.print("Sens droite = ");
  Serial.println(SensDroiteCharacteristic.value()==1);
   if (SensDroiteCharacteristic.value()){
      //digitalWrite(S_DROITE,HIGH);
      }
    else{
      //digitalWrite(S_DROITE,LOW);
    }
}

void callbackSGauche(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Sens gauche = ");
  Serial.println(SensGaucheCharacteristic.value());
  if (SensGaucheCharacteristic.value()==1){
    //digitalWrite(S_GAUCHE,HIGH);
  }
  else{
    //digitalWrite(S_GAUCHE,LOW);
  }
}