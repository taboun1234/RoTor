#include <ArduinoBLE.h>
#include "Nos_define.h"

/*struct Tab10Val        // Essai pour faire une seul caractéristque avec toutes les valeurs de nos capteurs mais non abouti
{
    uint16_t capteurA0;
    uint16_t capteurBG;
    uint16_t capteurA1;
    uint16_t capteurA2;
    uint16_t capteurBM;
    uint16_t capteurA3;
    uint16_t capteurA4;
    uint16_t capteurA5;
    uint16_t capteurBD;
    uint16_t capteurA6;
}jean;

class BLETab10ValCharacteristic : public BLETypedCharacteristic<Tab10Val> {
public:
  BLETab10ValCharacteristic(const char* uuid, unsigned int permissions);
};*/

/**
 * @brief Initialisation du service BLE pour le système de propulsion
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Création du service PropulsionService avec instansiation et initialisation des caractéristiques pour les sens de rotation et la puissance des deux moteurs
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Init_PropulsionService();

/**
 * @brief méthode appelée lorsqu'il y a un mur trop proche
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Cette méthode est appelé à la suite d'une interruption de front montant sur la pin INT_MUR
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Init_CapteursService();

