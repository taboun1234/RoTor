#include "Mon_BLE.h"



      // Service pour gérer deux moteurs
  // Bluetooth® Low Energy Propulsion Service 7bfaa100-63c7-4d86-a860-05b13af7cff
BLEService PropulsionService("7bfaa100-63c7-4d86-a860-05b13af7cffd");

  // Bluetooth® Low Energy Puissance et sens Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic PuissanceGaucheCharacteristic("7bfaa101-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
BLEByteCharacteristic PuissanceDroiteCharacteristic("7bfaa102-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
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
    BLE.setAdvertisedService(PropulsionService);

    //switchCharacteristic.addDescriptor(batteryLevelDescriptor);
    PuissanceGaucheCharacteristic.addDescriptor(batteryLevelDescriptor2);

    // add the characteristic to the service
    PropulsionService.addCharacteristic(PuissanceGaucheCharacteristic);
    PropulsionService.addCharacteristic(PuissanceDroiteCharacteristic);
    PropulsionService.addCharacteristic(SensGaucheCharacteristic);
    PropulsionService.addCharacteristic(SensDroiteCharacteristic);
    
    // add service
    BLE.addService(PropulsionService);

    // set the initial value for the characeristic:
    PuissanceGaucheCharacteristic.writeValue(0);
    PuissanceDroiteCharacteristic.writeValue(0);
    SensDroiteCharacteristic.writeValue(0);
    SensGaucheCharacteristic.writeValue(0);

    PuissanceGaucheCharacteristic.setEventHandler(BLEWritten, callbackPGauche);
    PuissanceDroiteCharacteristic.setEventHandler(BLEWritten, callbackPDroite);
    SensDroiteCharacteristic.setEventHandler(BLEWritten, callbackSDroite);
    SensGaucheCharacteristic.setEventHandler(BLEWritten, callbackSGauche);
    
    digitalWrite(PUISS_GAUCHE,PuissanceGaucheCharacteristic.value());
    digitalWrite(PUISS_DROITE,PuissanceDroiteCharacteristic.value());
    digitalWrite(SENS_AR_DROITE,1);
    digitalWrite(SENS_AR_GAUCHE,1);
}

void callbackPGauche(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Puissance gauche = ");
  Serial.println(PuissanceGaucheCharacteristic.value());
  analogWrite(PUISS_GAUCHE,PuissanceGaucheCharacteristic.value());
}

void callbackPDroite(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Puissance droite = ");
  Serial.println(PuissanceDroiteCharacteristic.value());
  analogWrite(PUISS_DROITE,PuissanceDroiteCharacteristic.value());
}

void callbackSDroite(BLEDevice central, BLECharacteristic characteristic){

  Serial.print("Sens droite = ");
  Serial.println(SensDroiteCharacteristic.value()==1);
   if (SensDroiteCharacteristic.value()){
      digitalWrite(SENS_AV_DROITE,HIGH);
      digitalWrite(SENS_AR_DROITE,LOW);
      }
    else{
      digitalWrite(SENS_AV_DROITE,LOW);
      digitalWrite(SENS_AR_DROITE,HIGH);
    }
}

void callbackSGauche(BLEDevice central, BLECharacteristic characteristic){
  Serial.print("Sens gauche = ");
  Serial.println(SensGaucheCharacteristic.value());
  if (SensGaucheCharacteristic.value()==1){
    digitalWrite(SENS_AV_GAUCHE,HIGH);
    digitalWrite(SENS_AR_GAUCHE,LOW);
  }
  else{
    digitalWrite(SENS_AV_GAUCHE,LOW);
    digitalWrite(SENS_AR_GAUCHE,HIGH);
  }
}


/*BLETab10ValCharacteristic::BLETab10ValCharacteristic(const char* uuid, unsigned int properties) : // essai pour utiliser une seule characteristique avec un type structuré créé par mes soins
  BLETypedCharacteristic<Tab10Val>(uuid, properties) 
{
}*/

      // Service pour les capteurs
  // Bluetooth® Low Energy Propulsion Service 7bfaa200-63c7-4d86-a860-05b13af7cff
BLEService CapteursService("7bfaa200-63c7-4d86-a860-05b13af7cffd");

  // Bluetooth® Low Energy Capteurs Characteristic - 7bfaa201 à 7bfaa210 - 10 caractéristiques pour les valeurs des 10 capteurs
//BLETab10ValCharacteristic ValCapteursCharacteristique("7bfaa200-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);
BLEWordCharacteristic CapteurA0Caracteristique ("7bfaa201-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant Tout à gauche
BLEWordCharacteristic CapteurBGCaracteristique ("7bfaa202-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Bas Gauche
BLEWordCharacteristic CapteurA1Caracteristique ("7bfaa203-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant milieu gauche
BLEWordCharacteristic CapteurA2Caracteristique ("7bfaa204-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant centre gauche
BLEWordCharacteristic CapteurBMCaracteristique ("7bfaa205-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Bas centre
BLEWordCharacteristic CapteurA3Caracteristique ("7bfaa206-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant centre
BLEWordCharacteristic CapteurA4Caracteristique ("7bfaa207-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant centre droit
BLEWordCharacteristic CapteurA5Caracteristique ("7bfaa208-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant milieu droit
BLEWordCharacteristic CapteurBDCaracteristique ("7bfaa209-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Bas droit
BLEWordCharacteristic CapteurA6Caracteristique ("7bfaa210-63c7-4d86-a860-05b13af7cffd", BLERead | BLEWriteWithoutResponse);  // Valeur capteur Avant Tout à droite

  // Bluetooth® Low Energy Capteurs Descriptors 
BLEDescriptor CapteurA0Descriptor("2901", "Capteur A0");
BLEDescriptor CapteurBGDescriptor("2901", "Capteur BG");
BLEDescriptor CapteurA1Descriptor("2901", "Capteur A1");
BLEDescriptor CapteurA2Descriptor("2901", "Capteur A2");
BLEDescriptor CapteurBMDescriptor("2901", "Capteur BM");
BLEDescriptor CapteurA3Descriptor("2901", "Capteur A3");
BLEDescriptor CapteurA4Descriptor("2901", "Capteur A4");
BLEDescriptor CapteurA5Descriptor("2901", "Capteur A5");
BLEDescriptor CapteurBDDescriptor("2901", "Capteur BD");
BLEDescriptor CapteurA6Descriptor("2901", "Capteur A6");

void Init_CapteursService(){

    // set advertised local name and service UUID:
    BLE.setAdvertisedService(CapteursService);

    // add the descriptor to the characteristic
    CapteurA0Caracteristique.addDescriptor(CapteurA0Descriptor);
    CapteurBGCaracteristique.addDescriptor(CapteurBGDescriptor);
    CapteurA1Caracteristique.addDescriptor(CapteurA1Descriptor);
    CapteurA2Caracteristique.addDescriptor(CapteurA2Descriptor);
    CapteurBMCaracteristique.addDescriptor(CapteurBMDescriptor);
    CapteurA3Caracteristique.addDescriptor(CapteurA3Descriptor);
    CapteurA4Caracteristique.addDescriptor(CapteurA4Descriptor);
    CapteurA5Caracteristique.addDescriptor(CapteurA5Descriptor);
    CapteurBDCaracteristique.addDescriptor(CapteurBDDescriptor);
    CapteurA6Caracteristique.addDescriptor(CapteurA6Descriptor);

    // add the characteristic to the service
    //CapteursService.addCharacteristic(ValCapteursCharacteristique);
    CapteursService.addCharacteristic(CapteurA0Caracteristique);
    CapteursService.addCharacteristic(CapteurBGCaracteristique);
    CapteursService.addCharacteristic(CapteurA1Caracteristique);
    CapteursService.addCharacteristic(CapteurA2Caracteristique);
    CapteursService.addCharacteristic(CapteurBMCaracteristique);
    CapteursService.addCharacteristic(CapteurA3Caracteristique);
    CapteursService.addCharacteristic(CapteurA4Caracteristique);
    CapteursService.addCharacteristic(CapteurA5Caracteristique);
    CapteursService.addCharacteristic(CapteurBDCaracteristique);
    CapteursService.addCharacteristic(CapteurA6Caracteristique);

    // add service
    BLE.addService(CapteursService);

    // set the initial value for the characeristic:
    //ValCapteursCharacteristique.writeValue(jean);
    CapteurA0Caracteristique.writeValue(0);
    CapteurBGCaracteristique.writeValue(1);
    CapteurA1Caracteristique.writeValue(2);
    CapteurA2Caracteristique.writeValue(3);
    CapteurBMCaracteristique.writeValue(4);
    CapteurA3Caracteristique.writeValue(5);
    CapteurA4Caracteristique.writeValue(6);
    CapteurA5Caracteristique.writeValue(7);
    CapteurBDCaracteristique.writeValue(8);
    CapteurA6Caracteristique.writeValue(9);
}