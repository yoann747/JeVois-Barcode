#define ARDUINO
#include <SoftwareSerial.h>
#include <Hexapod_Lib.h>
#include <Servo.h>
  // put your setup code here, to run once:
 /*
  mySerial.begin(115200);
  mySerial.setTimeout(1000); //Tx Led frequency 
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);
  
  mySerial.println("setpar serlog None");
  mySerial.println("setpar serout Hard");
    

}
*/




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
  
  
 //rep [INLEN + 1] = instr [INLEN + 1];
 //char * tok = strtok(instr, " \r\n");  
//int state = 0; int targx = 0, targy = 0;

mySerial.println(instr);
  
     /*
     while (tok)
 {
switch (state)
      {       case 0: if (strcmp(tok, "N2") == 0 || strcmp(tok, "N3") == 0 ) state = 1; else state = 1000; break;
               case 1: 
                      default: break; // Skip any additional tokens
}
}

*/
   

   

  

   }
 

 
 
  //mySerial.println(*tok);


