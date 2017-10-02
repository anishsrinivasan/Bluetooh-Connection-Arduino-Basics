# Bluetooh-Connection-Arduino-Basics

This is some of the simple steps to connect your Bluetooth Enabled Arduino to your Smartphone and control using it.

**Requirements**

- Arduino
- Breadboard
- Bluetooth Module (HC 05)
- Jumpwires
- PC
- Some LEDs to lit the project. 

**Setup**

- Connect the Bluetooth Module to the Arduino
 
 >GND - GND
 VCC - 5V or 3.3V
 RX - TX
 TX - RX 

- Now Connect the LEDs to 4th and 5th Pins of the Arduino
- Upload the Code to Arduino (Make sure that the RX and TX Pins aren't connected to the board during uploading)
- Install the APK Provided.
- Open the Serial Monitor and Connect to the Arduino using the App on your Smartphone.
- Voila.

**Source Code - Arduino :**



    #include < SoftwareSerial.h >
    SoftwareSerial BTserial(8, 9); // RX, TX
    
    char c = ' ';
    int left = 5;
    int right = 4;
    void setup() {
    
      Serial.begin(9600);
      Serial.print("Sketch:   ");
      Serial.println(__FILE__);
      Serial.print("Uploaded: ");
      Serial.println(__DATE__);
      Serial.println(" ");
    
      BTserial.begin(9600);
      Serial.println("BTserial started at 9600");
      Serial.println(" ");
      pinMode(left, OUTPUT);
      pinMode(right, OUTPUT);
    }
    
    void loop() {
      // Read from the Bluetooth module and send to the Arduino Serial Monitor
      if (BTserial.available()) {
        c = BTserial.read();
        Serial.write(c);
        Serial.println(c);
      }
      // Read from the Serial Monitor and send to the Bluetooth module
      if (Serial.available()) {
        c = Serial.read();
        BTserial.write(c);
        Serial.println(c);
        switch (c) {
        case '1':
          Serial.println("Left");
          digitalWrite(left, HIGH);
          digitalWrite(right, LOW);
          break;
        case '2':
          Serial.println("Right");
          digitalWrite(right, HIGH);
          digitalWrite(left, LOW);
          break;
        case '3':
          Serial.println("Random");
          digitalWrite(left, LOW);
          digitalWrite(right, LOW);
          delay(500);
          digitalWrite(left, HIGH);
          digitalWrite(right, LOW);
          delay(1000);
          digitalWrite(right, HIGH);
          digitalWrite(left, LOW);
          delay(1000);
          break;
        default:
          Serial.println("D");
          break;
        }
      }
    
    }
`
`
