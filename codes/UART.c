// Master:
void setup() {
  Serial.begin(9600); // UART starts at 9600 baud
  delay(1000);        // Give time for Serial to initialize
}

void loop() {
  Serial.println("Hello from Master"); // Send message
  delay(1000);                         // Wait 1 second
}
//---------------------------------------------------------
// Slave:
void setup() {
  Serial.begin(9600); // Same baud rate as master
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(msg);
  }
}
