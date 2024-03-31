

    // Roues 
#define PUISS_GAUCHE 2  // Pin qui délivre le signal pwm qui control la vitesse du moteur Gauche
#define PUISS_DROITE 3  // Pin qui délivre le signal pwm qui control la vitesse du moteur Droit
#define SENS_AV_DROITE 11 // Pin qui indique met le sens du moteur droit à avancer
#define SENS_AR_DROITE 12 // Pin qui indique met le sens du moteur droit à avancer
#define SENS_AV_GAUCHE 13 // Pin qui indique met le sens du moteur gauche à avancer
#define SENS_AR_GAUCHE 14 // Pin qui indique met le sens du moteur grauche à avancer
#define INT1_CAPTEUR_MD A1 // Pin qui reçoit le carré 1 du capteur moteur droit
#define INT2_CAPTEUR_MD A2 // Pin qui reçoit le carré 2 du capteur moteur droit
#define INT1_CAPTEUR_MG 4 // Pin qui reçoit le carré 1 du capteur moteur gauche
#define INT2_CAPTEUR_MG 5 // Pin qui reçoit le carré 2 du capteur moteur gauche

    // Capteurs
#define TTL_COMPT 10  // Pin qui génère le signal carré de période 2ms (rapport cyclique 50%)
#define RESET_COMPT A6 // Pin qui perpmet le reset du compteur
#define INT_MUR 0     // Pin qui récupère l'interuption de détection de mur
#define INT_SOL 1     // Pin  qui récupère l'interuption de non détection de sol
#define MES_DIST A5   // Pin qui récupère la distance mesuré par les capteurs(val entre 0(>10cm?) et 5V("0cm"))
#define LAME_AV 9     // Pin qui récupère l'état du capteurs lame souple avant
#define LAME_ROUES 8  // Pin qui récupère l'état du capteurs lame souple roues

    // Brosses et aspiration
#define BROSSES_AV A3 // Pin qui active le moteur des brosses avant (vitesse réglable)
#define BROSSES_AR 6 // Pin qui active le moteur de la brosse arrière (vitesse réglable)
#define ASPIRATION 7 // Pin qui active le moteur d'aspiration (vitesse réglable)

#define BTN 0