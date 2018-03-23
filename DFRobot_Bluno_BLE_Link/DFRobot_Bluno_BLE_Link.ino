/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use DFRobot Bluno or BLE Link module
 * to connect your project to Blynk.
 *
 * Please be sure to update your DFRobot firmware to at least V1.97:
 *   https://github.com/DFRobot/BLE_firmware_V1.9
 *
 * For Bluno, read instructions here:
 *   https://www.dfrobot.com/wiki/index.php/Bluno_SKU:DFR0267
 *
 * For BLE-Link, read instructions here:
 *   https://www.dfrobot.com/wiki/index.php/BLE-Link_(SKU:TEL0073)
 *
 * NOTE: BLE support is in beta!
 *
 **************************************************************/

//#define BLYNK_USE_DIRECT_CONNECT

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <BlynkSimpleSerialBLE.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "7ab43b6052b3494a99de78b47238074e";

void setup()
{
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(115200);
  Blynk.begin(Serial, auth);
}

BLYNK_READ(V5) // Widget in the app READs Virtal Pin V5 with the certain frequency
{
  // This command writes Arduino's uptime in seconds to Virtual Pin V5
  Blynk.virtualWrite(5, millis() / 1000);
}

void loop()
{
  Blynk.run();
}

