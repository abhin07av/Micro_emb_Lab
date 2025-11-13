// MASTER
#include <SPI.h>

void setup() {
  Serial.begin(9600);

  pinMode(10, OUTPUT);  // Select Slave pin 
  digitalWrite(10, HIGH); // deactivate slave

  SPI.begin(); // Initialize SPI as Master
}

void loop(){

  digitalWrite(10, LOW); // activate slave (set SS low)
  char msg[] = "Hello";
  for (int i = 0; i < sizeof(msg); i++) {
    SPI.transfer(msg[i]); // Send msg byte by byte
  }
  digitalWrite(10, HIGH); // deactivate slave

  Serial.println("Sent: Hello");
  delay(1000); // Wait 1 second
}
//---------------------------------------------------------
// SLAVE
#include <SPI.h>

volatile boolean received = false;
char receivedChar;

void setup() {
  Serial.begin(9600);

  pinMode(MISO, OUTPUT);   // Set MISO as OUTPUT
  SPCR |= _BV(SPE);        // Turns arduino into SPI slave
  SPI.attachInterrupt();   // Enable interrupt when a byte is received
}

ISR(SPI_STC_vect) { // SPI interrupt when a byte is received
  receivedChar = SPDR;     // Read received byte in SPI data register
  received = true;
}

void loop() {
  if(received) {
    Serial.print("Received: ");
    Serial.println(receivedChar);
    received = false;
  }
}
