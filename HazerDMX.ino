// Includes
#include <DMXSerial.h>

// Constant Variables
const int relayPin = 2;
const int addrDMX = 254;

// Setup pins
void setup() {
  pinMode(relayPin, OUTPUT);
  DMXSerial.write(addrDMX, 0);
  digitalWrite(relayPin, LOW);
}

//Main Program Loop
void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(lastPacket < 10000) {
    if(DMXSerial.read(addrDMX) <= 85){
      digitalWrite(relayPin, LOW);
    } else {
      digitalWrite(relayPin, HIGH);
    }
  } else {
    digitalWrite(relayPin, LOW);
  }
}
