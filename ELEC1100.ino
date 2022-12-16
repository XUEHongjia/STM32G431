/*
  ELEC1100 Your Lab#06 & Project Template
  To program the car tracking the white line on a dark mat
  Group No. 36 (number on your project box):
  Group Member 1 (name: XUE Hongjia & SID: 20761325):
  Group Member 2 (name & SID): Unknown and he was absent during the whole demo
*/
// assign meaningful names to those pins that will be used
const int pinL_Sensor = A5;      //pin A5
const int pinR_Sensor = A3;      //pin A3
const int pinL_PWM = 9;          //pin D9
const int pinR_PWM = 11;         //pin D11
const int pinL_DIR = 10;         //pin D10
const int pinR_DIR = 12;         //pin D12
const int pinB_Sensor = A4;  
//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int bumperSensor=1;             // initial condition is dark 
int Ycrossing_number=0;         //initial Y shape crossing number=0
int Wall_count=0;               //initial white wall number=0
// the setup function runs once when you press reset or power the board
void setup ()
{
  // define pins as input and output
  pinMode(pinL_Sensor, INPUT);
  pinMode(pinR_Sensor, INPUT);

  pinMode(pinB_Sensor, INPUT);   //assign the reading of the bumper sensor(A4) as input
  
  pinMode(pinL_DIR, OUTPUT);
  pinMode(pinR_DIR, OUTPUT);
  
  pinMode(pinL_PWM, OUTPUT);
  pinMode(pinR_PWM, OUTPUT);
  
  // initialize output pins
  digitalWrite(pinL_DIR, HIGH);   //forward direction    
  digitalWrite(pinR_DIR, HIGH);   //forward direction
  analogWrite(pinL_PWM, 0);    //forward speed 
  analogWrite(pinR_PWM, 0);    //forward speed 
}



// the loop function runs over and over again forever

void loop()
{
  leftSensor = digitalRead(pinL_Sensor);
  rightSensor = digitalRead(pinR_Sensor);
  bumperSensor = digitalRead(pinB_Sensor);    // assign the variable 'bumperSensor' as the digital reading of pinB_Sensor
  //whenever the bumper sensor detects a white wall, white wall number=white wall number+1
  //when the white wall number=0, no movement
  if (Wall_count==0) {
       analogWrite(pinL_PWM, 0);
       analogWrite(pinR_PWM, 0);
       digitalWrite(pinL_DIR, 0);
       digitalWrite(pinR_DIR, 0); 
       
     if (!bumperSensor && !leftSensor && !rightSensor) {
        while (!leftSensor && !rightSensor){
       analogWrite(pinL_PWM, 130);
       analogWrite(pinR_PWM, 130);
       digitalWrite(pinL_DIR, HIGH);
       digitalWrite(pinR_DIR, HIGH);
       bumperSensor = digitalRead(pinB_Sensor);
       leftSensor = digitalRead(pinL_Sensor);
       rightSensor = digitalRead(pinR_Sensor);
    }
    Wall_count=Wall_count+1;
    }
    }
  //when the white wall number=1, move forward {
  //when Y shape crossing number<3, if ( !leftSensor && !rightSensor )=>(turn left AND Ycrossing_number=Ycrossing_number+1)
  //when Y shape crossing number=3, if ( !leftSensor && !rightSensor )=>(turn right AND ???}

  if (Wall_count==1){
    if (Ycrossing_number<2) {

      if ( !leftSensor && !rightSensor){
        while( !rightSensor){
          analogWrite(pinL_PWM, 110);
          analogWrite(pinR_PWM, 150);
          digitalWrite(pinL_DIR, LOW);
          digitalWrite(pinR_DIR, HIGH);  
          delay(110);
          leftSensor = digitalRead(pinL_Sensor);
          rightSensor = digitalRead(pinR_Sensor);
        }
        Ycrossing_number=Ycrossing_number+1;
        }
    
       if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 0);
        analogWrite(pinR_PWM, 0);
        delay(30);
        while (!leftSensor && rightSensor){
           analogWrite(pinL_PWM, 80);
           analogWrite(pinR_PWM, 130);
           digitalWrite(pinL_DIR, LOW);
           digitalWrite(pinR_DIR, HIGH);
           leftSensor = digitalRead(pinL_Sensor);
           rightSensor = digitalRead(pinR_Sensor);
         }
         analogWrite(pinR_PWM, 0);
         analogWrite(pinL_PWM, 0);
        delay(30);
        }
    
      if ( leftSensor && !rightSensor ) {
               analogWrite(pinR_PWM, 0);
               analogWrite(pinL_PWM, 0);
                 delay(30);
        while (leftSensor && !rightSensor) {
          analogWrite(pinL_PWM, 130);
          analogWrite(pinR_PWM, 80);
          digitalWrite(pinL_DIR, HIGH);
          digitalWrite(pinR_DIR, LOW);
          leftSensor = digitalRead(pinL_Sensor);
          rightSensor = digitalRead(pinR_Sensor);
        }
        analogWrite(pinL_PWM, 0);
        analogWrite(pinR_PWM, 0);
        delay(30);
        }
    
      if ( leftSensor && rightSensor ) {
        while (leftSensor && rightSensor){
           analogWrite(pinL_PWM, 130);
           analogWrite(pinR_PWM, 130);
           digitalWrite(pinL_DIR, HIGH);
           digitalWrite(pinR_DIR, HIGH);
           leftSensor = digitalRead(pinL_Sensor);
           rightSensor = digitalRead(pinR_Sensor);
        }
    }
    }
    
  if (Ycrossing_number==2){
      if ( !leftSensor && !rightSensor ) {
           analogWrite(pinR_PWM, 0);
           analogWrite(pinL_PWM, 0);
                  delay(50);
        while (!leftSensor){
         analogWrite(pinL_PWM, 140);
         analogWrite(pinR_PWM, 130);
         digitalWrite(pinL_DIR, HIGH);
         digitalWrite(pinR_DIR, LOW); 
         delay(240);
         leftSensor = digitalRead(pinL_Sensor);
         rightSensor = digitalRead(pinR_Sensor);
        }
        Ycrossing_number=Ycrossing_number+1;
        }

      if ( !leftSensor && rightSensor ) {
        digitalWrite(pinL_DIR, LOW);
         digitalWrite(pinR_DIR, HIGH);
      analogWrite(pinL_PWM, 0);
      analogWrite(pinR_PWM, 0);
      delay(50);
        while (!leftSensor && rightSensor){
          digitalWrite(pinL_DIR, LOW);
         digitalWrite(pinR_DIR, HIGH);
          analogWrite(pinL_PWM, 80);
         analogWrite(pinR_PWM, 120);
         leftSensor = digitalRead(pinL_Sensor);
         rightSensor = digitalRead(pinR_Sensor);
        }
        analogWrite(pinR_PWM, 0);
        delay(50);
        }
    
     if ( leftSensor && !rightSensor ) {
         digitalWrite(pinL_DIR, HIGH);
         digitalWrite(pinR_DIR, LOW);
        analogWrite(pinR_PWM, 0);
        analogWrite(pinR_PWM, 0);
        delay(50);
       while (leftSensor && !rightSensor){
        digitalWrite(pinL_DIR, HIGH);
         digitalWrite(pinR_DIR, LOW);
         analogWrite(pinL_PWM, 120);
         analogWrite(pinR_PWM, 80);
         
         leftSensor = digitalRead(pinL_Sensor);
         rightSensor = digitalRead(pinR_Sensor);
       }
       analogWrite(pinL_PWM, 0);
       delay(50);
       }
    
     if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 120);
        analogWrite(pinR_PWM, 120);
        digitalWrite(pinL_DIR, HIGH);
        digitalWrite(pinR_DIR, HIGH);
        leftSensor = digitalRead(pinL_Sensor);
        rightSensor = digitalRead(pinR_Sensor);
       }
       }
   if (Ycrossing_number==3){
   if (bumperSensor==0) {
         while (bumperSensor==0){
       analogWrite(pinL_PWM, 120);
       analogWrite(pinR_PWM, 120);
       digitalWrite(pinL_DIR, LOW);
       digitalWrite(pinR_DIR, LOW);
       bumperSensor = digitalRead(pinB_Sensor); 
        }
        Wall_count=Wall_count+1;
        }
        
        if ( !leftSensor && rightSensor ) {
        while (!leftSensor && rightSensor){
          digitalWrite(pinL_DIR, LOW);
         digitalWrite(pinR_DIR, HIGH);
          analogWrite(pinL_PWM, 110);
         analogWrite(pinR_PWM, 115);
         
         leftSensor = digitalRead(pinL_Sensor);
         rightSensor = digitalRead(pinR_Sensor);
        }
        digitalWrite(pinL_DIR, LOW);
         digitalWrite(pinR_DIR, HIGH);
        analogWrite(pinR_PWM, 110);
        analogWrite(pinL_PWM, 0);
        delay(50);
        }
    
     if ( leftSensor && !rightSensor ) {
       
       while (leftSensor && !rightSensor){
        digitalWrite(pinL_DIR, HIGH);
         digitalWrite(pinR_DIR, LOW);
         analogWrite(pinL_PWM, 115);
         analogWrite(pinR_PWM, 110);
         
         leftSensor = digitalRead(pinL_Sensor);
         rightSensor = digitalRead(pinR_Sensor);
       }
       digitalWrite(pinL_DIR, HIGH);
       digitalWrite(pinR_DIR, LOW);
       analogWrite(pinL_PWM, 110);
       analogWrite(pinR_PWM, 0);
       delay(50);
       }
       
       if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 105);
        analogWrite(pinR_PWM, 105);
        digitalWrite(pinL_DIR, HIGH);
        digitalWrite(pinR_DIR, HIGH);
        leftSensor = digitalRead(pinL_Sensor);
        rightSensor = digitalRead(pinR_Sensor);
       }
       }
  }
    
  //when the white wall number=2, move backward. and if (white wall number=2 AND right sensor=0) => (stop)
  if (Wall_count==2){
           
           if (leftSensor && !rightSensor ) {
            while (leftSensor && !rightSensor){
              delay(260);
           analogWrite(pinL_PWM, 0);
           analogWrite(pinR_PWM, 0);
           digitalWrite(pinL_DIR, LOW);
           digitalWrite(pinR_DIR, LOW);
            }
        }
        else {
          analogWrite(pinL_PWM, 120);
           analogWrite(pinR_PWM, 120);
           digitalWrite(pinL_DIR, LOW);
           digitalWrite(pinR_DIR, LOW);
        }
  }
 }