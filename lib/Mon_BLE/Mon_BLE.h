#include <ArduinoBLE.h>
#include "Nos_define.h"

/*struct Tab10Val
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

void Init_PropulsionService();

void Init_CapteursService();

