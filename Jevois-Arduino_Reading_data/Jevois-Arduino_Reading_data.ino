#define ARDUINO
#include <SoftwareSerial.h>
#include <Hexapod_Lib.h>
#include <Servo.h>
  // put your setup code here, to run once:
 
#define LEDPIN 13
#define mySerial Serial
//SoftwareSerial mySerial(0,1); 

// Buffer for received serial port bytes:
// LED_BUILTIN
#define INLEN 128
char instr[INLEN + 1];

void setup() {
  // put your setup code here, to run once:
 
  mySerial.begin(115200);
  //mySerial.setTimeout(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  mySerial.println("setpar serlog None");
  mySerial.println("setpar serout Hard");
    

}


void loop() {
 
 digitalWrite(LEDPIN , LOW);
  byte len = mySerial.readBytesUntil('\n', instr, INLEN);
  instr[len] = 0;
 // mySerial.println(len);
 digitalWrite(LEDPIN , HIGH);


mySerial.println(instr);
  
 

   }
 

 
