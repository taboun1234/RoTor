#include <Arduino.h>
#include "Nos_methodes.h"


  // Roues 
#define PUISS_GAUCHE 2  // Pin qui délivre le signal pwm qui control la vitesse du moteur Gauche
#define PUISS_DROITE 3  // Pin qui délivre le signal pwm qui control la vitesse du moteur Droit
#define SENS_AV_DROITE 11 // Pin qui indique met le sens du moteur droit à avancer
#define SENS_AR_DROITE 12 // Pin qui indique met le sens du moteur droit à avancer
#define SENS_AV_GAUCHE 13 // Pin qui indique met le sens du moteur gauche à avancer
#define SENS_AR_GAUCHE 14 // Pin qui indique met le sens du moteur grauche à avancer
#define INT1_CAPTEUR_MD  // Pin qui reçoit le carré 1 du capteur moteur droit
#define INT2_CAPTEUR_MD  // Pin qui reçoit le carré 2 du capteur moteur droit
#define INT1_CAPTEUR_MG  // Pin qui reçoit le carré 1 du capteur moteur gauche
#define INT2_CAPTEUR_MG  // Pin qui reçoit le carré 2 du capteur moteur gauche

  // Capteurs
#define TTL           // Pin qui génère le signal carré de période 2ms (rapport cyclique 50%)
#define RESET_COMPT   // Pin qui perpmet le reset du compteur
#define INT_MUR 0      // Pin qui récupère l'interuption de détection de mur
#define INT_SOL 1      // Pin  qui récupère l'interuption de non détection de sol
#define MES_DIST      // Pin qui récupère la distance mesuré par les capteurs(val entre 0(>10cm?) et 5V("0cm"))
#define LAME_AV       // Pin qui récupère l'état du capteurs lame souple avant
#define LAME_ROUES    // Pin qui récupère l'état du capteurs lame souple roues

#define BTN 0

const int ledPin = LED_BUILTIN; // pin to use for the LED

void setup() {

  Serial.begin(9600);
  //while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  pinMode(PUISS_GAUCHE, OUTPUT);
  pinMode(PUISS_DROITE, OUTPUT);
  pinMode(SENS_AR_DROITE, OUTPUT);
  pinMode(SENS_AV_DROITE, OUTPUT);
  /*pinMode(INT1_CAPTEUR_MD, INPUT);
  pinMode(INT2_CAPTEUR_MD, INPUT);
  pinMode(INT1_CAPTEUR_MG, INPUT);
  pinMode(INT2_CAPTEUR_MG, INPUT);

  pinMode(TTL, OUTPUT);
  pinMode(RESET_COMPT, OUTPUT);
  pinMode(INT_MUR, INPUT);
  pinMode(INT_SOL, INPUT);
  pinMode(MES_DIST, INPUT);
  pinMode(LAME_AV, INPUT);
  pinMode(LAME_ROUES, INPUT);*/
  //PORT->Group[g_APinDescription[a].ulPort].DIRSET.reg = (uint32_t)(1<<g_APinDescription[a].ulPin);


  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);
  }
  
  BLE.setLocalName("RoTor"); 
  BLE.setDeviceName("RoTor");
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




