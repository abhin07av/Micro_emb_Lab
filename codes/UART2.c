// MASTER
void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {

  byte a[] = {B10101,B1001101};
  byte b[] = {5, 7};  

  for(int i=0; i<2; i++){
    byte data = a[i];
    byte len = b[i];

    Serial.write(len);     
    Serial.write(data);
    delay(1000);           
  }

  delay(5000); 
}

//-----------------------------------------------------------------------------------

//SLAVE
// Does UART frame simulation and Serial Plotter output
void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Start\tBit0\tBit1\tBit2\tBit3\tBit4\tBit5\tBit6\tBit7\tParity\tStop");
}

void loop() {

  if (Serial.available() >= 2) {
    //---------------------------------
    byte len = Serial.read();     
    byte data = Serial.read();    

    byte arr[9] = {0};
    for(byte i=0; i<len; i++){
      arr[i] = (data >> i) & 0x01;
    }
    //--------------------------------
    //  UART Frame Construction 
    byte startBit= 0;
    byte stopBit= 1;
    byte parity= 0; // Even parity
    for(byte i=0; i<len; i++){
      parity ^= arr[i]; 
    }
    //-------------------------------
    //  Serial Monitor Output 
    Serial.print("UART Frame: ");

    Serial.print(startBit);
    Serial.print(" ");

    for(byte i=0; i<len; i++){
      Serial.print(arr[i]);
      Serial.print(" ");
    }

    Serial.print(parity);
    Serial.print(" ");

    Serial.print(stopBit);
    Serial.println();
    //----------------------------------
  }
}

