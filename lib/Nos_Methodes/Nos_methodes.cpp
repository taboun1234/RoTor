#include "Nos_methodes.h"

void Interrupt_Mur(){
  
}

void Interrput_Sol(){

}

void Init_Propulsion(){

        // Initialisation du sens des pins
    pinMode(PUISS_GAUCHE, OUTPUT);
    pinMode(PUISS_DROITE, OUTPUT);
    pinMode(SENS_AR_DROITE, OUTPUT);
    pinMode(SENS_AV_DROITE, OUTPUT);
    pinMode(SENS_AR_GAUCHE, OUTPUT);
    pinMode(SENS_AV_GAUCHE, OUTPUT);
    pinMode(INT1_CAPTEUR_MD, INPUT);
    pinMode(INT2_CAPTEUR_MD, INPUT);
    pinMode(INT1_CAPTEUR_MG, INPUT);
    pinMode(INT2_CAPTEUR_MG, INPUT);

        // Initialisation des valeurs
    analogWrite(PUISS_GAUCHE,0);
    analogWrite(PUISS_DROITE,0);
    digitalWrite(SENS_AR_DROITE,0);
    digitalWrite(SENS_AV_DROITE, 0);
    digitalWrite(SENS_AR_GAUCHE, 0);
    digitalWrite(SENS_AV_GAUCHE, 0);
}

void Init_Capteurs(){

        // Initialisation du sens des pins
    pinMode(TTL_COMPT, OUTPUT);
    pinMode(RESET_COMPT, OUTPUT);
    pinMode(INT_MUR, INPUT);
    pinMode(INT_SOL, INPUT);
    pinMode(MES_DIST, INPUT);
    pinMode(LAME_AV, INPUT);
    pinMode(LAME_ROUES, INPUT);

        // Initialisation des valeurs
    tone(TTL_COMPT,500);    // activation du signal qui permet le changement de capteur (f = 500 Hz -> période = 2 ms)
    digitalWrite(RESET_COMPT,0);
}

void Init_Nettoyage(){

        // Initialisation du sens des pins
    pinMode(BROSSES_AV,OUTPUT);
    pinMode(BROSSES_AR,OUTPUT);
    pinMode(ASPIRATION,OUTPUT);

        // Initialisation des valeurs
    analogWrite(BROSSES_AV,0);
    analogWrite(BROSSES_AR,0);
    analogWrite(ASPIRATION,0);
}
