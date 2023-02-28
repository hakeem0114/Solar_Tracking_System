#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  myservo.write(160);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position

    myservo.write(100);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position

    myservo.write(140);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position


      myservo.write(160);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position

    myservo.write(100);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position

    myservo.write(140);              // tell servo to go to position in variable 'pos'
    delay(250);                       // waits 15ms for the servo to reach the position
    

}
