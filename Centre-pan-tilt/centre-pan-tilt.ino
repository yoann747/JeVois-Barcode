   
    #include <Servo.h>
    #define SU1                     6
    #define SU2                     5
    #define SU3                     9

Servo myservoSU1;
Servo myservoSU2;
Servo myservoSU3;
    
int pos    = 1500; // center position is 1,5ms -> 1500µs
int _delay = 100;  // delay between set the servo pos, to reduce the supply current


void setup() {
  // put your setup code here, to run once:
    myservoSU1.attach(SU1);    // attaches the servo on pin 6 to the servo object
    myservoSU2.attach(SU2);    // attaches the servo on pin 5 to the servo object
    myservoSU3.attach(SU3);    // attaches the servo on pin 9 to the servo object
}


void loop() {
  // put your main code here, to run repeatedly:

    myservoSU1.writeMicroseconds(pos);
    delay(_delay);
    
    
    myservoSU2.writeMicroseconds(pos);
    delay(_delay);

    myservoSU2.writeMicroseconds(pos);
    delay(_delay);
}
