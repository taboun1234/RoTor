#include "Mon_BLE.h"
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
void Interrupt_Mur();

/**
 * @brief méthode appelée lorsqu'il y a un mur trop proche
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Cette méthode est appelé à la suite d'une interruption de front montant sur la pin INT_SOL
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Interrput_Sol();

/**
 * @brief Initialise les pin pour la propulsion du robot (pour un MKR WIFI 1010)
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Cette méthode initialise le sens des pin ainsi que les valeur pour le fonctionnement de la partie propulsion (pour un MKR WIFI 1010)
 * 
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Init_Propulsion();

/**
 * @brief Initialise les pin pour les capteurs du robot (pour un MKR WIFI 1010)
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Cette méthode initialise le sens des pin ainsi que les valeur pour le fonctionnement de la partie capteur (pour un MKR WIFI 1010)
 * 
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Init_Capteurs();

/**
 * @brief Initialise les pin pour les brosses et aspirateur du robot (pour un MKR WIFI 1010)
 * @author JOANNIS Naël
 * @date 31-03-2024
 * 
 * Cette méthode initialise le sens des pin ainsi que les valeur pour le fonctionnement de la partie nettoyage (pour un MKR WIFI 1010)
 * 
 * 
 * @param aucun
 * @return ne retourne rien
 * 
 * @version 1.0.0
*/
void Init_Nettoyage();
