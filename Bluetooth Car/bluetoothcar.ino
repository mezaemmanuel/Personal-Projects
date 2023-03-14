#include "BluetoothSerial.h"
BluetoothSerial BT; // Bluetooth Object
void setup() {
  Serial.begin(9600); // Initializing serial connection for debugging
  BT.begin("Nano Movil"); // Name of your Bluetooth Device and in slave mode
  Serial.println("Bluetooth Device is Ready to Pair");
  pinMode (34, OUTPUT); // Change the LED pin to OUTPUT
  pinMode (35, OUTPUT);  
}
void loop() {
   digitalWrite(25, LOW); // LED On
      digitalWrite(26, LOW);
  if (BT.available()) // Check if we receive anything from Bluetooth
  {
    int incoming = BT.read(); // Read what we recevive 
    Serial.print("Received: ");
    Serial.println(incoming);
    if (incoming == 82){ // 1 in ASCII
      digitalWrite(13, HIGH); // LED On
      digitalWrite(26, LOW);
    Serial.println("para un lado"); 
      BT.println("LED turned ON"); // Send the text via BT Serial
    }
    if (incoming == 76){ // 0 in ASCII
      
      digitalWrite(13, LOW); // LED On
      digitalWrite(26, HIGH); // LED Off
      Serial.println("al otro lado"); // Send the text via BT Serial
    }
  }
  delay(20);
}
