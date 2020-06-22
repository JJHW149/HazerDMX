// Includes
#include <DMXSerial.h>

// Constant Variables
const int relayPin = 2;
const int addrDMX = 512;

// Setup pins
void setup() {
  DMXSerial.init(DMXReceiver);
  
  pinMode(relayPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  DMXSerial.write(addrDMX, 0);
  digitalWrite(relayPin, LOW);
}

//Main Program Loop
void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(lastPacket < 10000) {
    if(DMXSerial.read(addrDMX) <= 85){
      digitalWrite(relayPin, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    } else {
      digitalWrite(relayPin, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
