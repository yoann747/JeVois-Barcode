#include <Servo.h>
#include <Hexapod_Lib.h>
#include <SoftwareSerial.h>


#define mySerial Serial
Servo panservo;
#define PANPIN 6
Servo tiltservo;
#define TILTPIN 5

// Initial servo values in degrees:
#define PANZERO 90
#define TILTZERO 90

#define SCALE 100
long pangain = 500;
long tiltgain = 800;
long panval = PANZERO * SCALE;
long tiltval = TILTZERO * SCALE;

//#define LEDPIN 13     
#define mySerial Serial
//SoftwareSerial mySerial(0,1); 

#define INLEN 128
char instr[INLEN + 1];

// Desired target width in standardized JeVois coordinates (a value of 2000 would occupy the whole field of view):
int TARGW = 300;
  

int pos    = 1500; // center position is 1,5ms -> 1500µs
int _delay = 100;  // delay between set the servo pos, to reduce the supply current
int transmove;
int vertmove;



void setup() {
  // put your setup code here, to run once:
    
    
    

    mySerial.begin(115200);
    SERIAL_CMD.begin(SERIAL_CMD_BAUD);
    Serial.begin(SERIAL_STD_BAUD);
    while(!Serial) 
    {
        ;  // wait for serial port to connect. Needed for native USB port only 
    }
 
  mySerial.setTimeout(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
 
  //SERIAL_CMD.println("serial");

    pinMode(PA_PIN,INPUT);
    digitalWrite(PA_PIN,LOW);
    
    // switches T1 and T2
    #ifdef ARDUINO
        pinMode(T1,INPUT);
        pinMode(T2,INPUT);
        //digitalWrite(T1,HIGH); // use internal pull-up resistor
        //digitalWrite(T2,HIGH); // use internal pull-up resistor
    #endif   
    
    panservo.attach(PANPIN);
    panservo.write(panval / SCALE);
    //delay(100);
    
    tiltservo.attach(TILTPIN);
    tiltservo.write(tiltval / SCALE);
    //delay(100);

  mySerial.println("setpar serlog None");
  mySerial.println("setpar serout Hard");
}

void loop() {

  digitalWrite(LED_BUILTIN , LOW);
  byte len = mySerial.readBytesUntil('\n', instr, INLEN);
  //mySerial.println(len);
  instr[len] = 0;
  digitalWrite(LED_BUILTIN , HIGH);
   mySerial.println(instr);
char * tok = strtok(instr, " \r\n");

 int state = 0; int id, targx = 0, targy = 0, targw, targh;


unsigned long period=10000;
unsigned long start = micros();

//for  (unsigned long start = micros(); (micros()-start) < period;  )
//{
    while (tok)
    {
switch (state)
    
      {
       case 0: if (strcmp(tok, "N2") == 0 || strcmp(tok, "N3") == 0 ) state = 1; else state = 1000; break;
       case 1: id = atoi(&tok[1]); state = 2; break; // ignore prefix
       case 2: targx = atoi(tok); state = 3; break;
       case 3: targy = atoi(tok); state = 4; break;
       //case 4: targw = atoi(tok); state = 5; break;
       //case 5: targh = atoi(tok); state = 6; break;
       default: break; // Skip any additional tokens
     }
     //mySerial.println(tok);
      tok = strtok(0, " \r\n");
    }

    
    if (state == 4)
  {  

    panval -= (targx * pangain) / 1000;
    if (panval < 5 * SCALE) panval = 5 * SCALE; else if (panval > 175 * SCALE) panval = 175 * SCALE;
    panservo.write(panval / SCALE);
       
    tiltval += (targy * tiltgain) / 1000;
    if (tiltval < 5 * SCALE) tiltval = 5 * SCALE; else if (tiltval > 175 * SCALE) tiltval = 175 * SCALE;
    tiltservo.write(tiltval / SCALE);
    }
    
   

    //if 
    

     }
 //}
  // put your main code here, to run repeatedly:


