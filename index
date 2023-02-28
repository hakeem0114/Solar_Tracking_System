//Initialize Code
#include <Servo.h>
#include <CustomStepper.h>
CustomStepper stepper(8, 9, 10, 11);

const int rightSensorPin = A4; 
const int leftSensorPin = A5;

int rightSensorRead = 0;
int leftSensorRead = 0;
int rightLightPct = 0;
int leftLightPct = 0;
int degreeChange = 1;

int upSensorRead = 0;
int downSensorRead = 0;
int upLightPct = 0;
int downLightPct = 0;
int degreeChange2 = 1;
int servo;

Servo vertical; // vertical servo
int servoh = 0; 
int servoLimitHigh = 160;
int servoLimitLow = 100;
//////////////////////////////////////////////////


void setup() {
  Serial.begin(9600); //Start serial monitor
  stepper.setRPM(5);  //Set stepper speed
  stepper.setSPR(4075.7728395);

     
  vertical.attach(7); // servo at pin 7
  vertical.write(160); //Makes it diagonal
  
  delay(2500);
}

void loop() 
{
///////////////////////////////////////////////////////////////////////////
  rightSensorRead = analogRead(rightSensorPin); //Record analog values from LDRs
  leftSensorRead = analogRead(leftSensorPin);
  rightLightPct = map(rightSensorRead, 0, 1023, 0, 100); //Takes 0-1023 value from analogRead and convert to 0-100% value
  leftLightPct = map(leftSensorRead, 0, 1023, 0, 100);

  upSensorRead = analogRead (rightSensorPin);
  downSensorRead = analogRead(leftSensorPin);
  upLightPct = map(rightSensorRead, 0, 1023, 0, 180);  
  downLightPct = map(leftSensorRead, 0, 1023, 0, 180); //servo max = 180 degrees

  
  degreeChange = map(abs(rightLightPct-leftLightPct),0,100,2,10); // x axis
  degreeChange2 = map(abs(rightLightPct-leftLightPct),0,100,100,160);  //y-axis
////////////////////////////////////////////////////////////////////////
//l/r 

  //Print out analog information
  Serial.print("right = "); 
  Serial.print(rightSensorRead);
  Serial.print(" left = ");
  Serial.print(leftSensorRead);
  Serial.print(" Pct r/l = ");
  Serial.print(rightLightPct);
  Serial.print("/");
  Serial.println(leftLightPct);
  
  if(rightLightPct < 30 && leftLightPct < 30)  //If ldr% is out of range
  {
    Serial.println("No sun detected!");
  } else if(rightLightPct > leftLightPct)  
    {
      Serial.println("Turning CCW!");
      
      rotateRight();  //Acttivates void function 
      stepper.run();
    }else 
      {
        Serial.println("Turning CW!");
        
        rotateLeft();
        stepper.run();
      }

 delay(500);
     
//////////////////////////////////////////////

/////////////////////////////////////////
//up/down

  if(upLightPct < 30 && downLightPct < 30)
  {
    Serial.println("No sun detected!"); 
  }else if(upLightPct > downLightPct)
    {
      Serial.println("Moving Up");
      moveUp();
      
      
    }else
      {
        Serial.println("Moving Down");
        moveDown();
        
        
      }
 delay(500);  
//////////////////////////////////////////////////////////
}


//////////////////////////////////////////////////////////////
//Functions

void moveUp() 
{
  servoh = ++servoh;
 // servoh = ++degreeChange2;
  
// if (servoh > servoLimitHigh)
 {
    servoh = servoLimitHigh;
  }
     vertical.write(servoh);
   delay(50);
}

void moveDown() 
{
  servoh = --servoh;
  //servoh = --degreeChange2;
  
   if (servoh < servoLimitHigh)
  {
    servoh = servoLimitHigh;
   }
     vertical.write(servoh);
     delay(50);
     
}


void rotateLeft(){
  stepper.setDirection(CCW);
  stepper.rotateDegrees(degreeChange);
  while(stepper.isDone() == false){
    stepper.run();
  }
}
void rotateRight(){
  stepper.setDirection(CW);
  stepper.rotateDegrees(degreeChange);
  while(stepper.isDone() == false){
    stepper.run();
  }
}
