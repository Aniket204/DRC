const byte analogPin = A0;   
const byte junctionPulse = 10;
const byte Dir_Left = 2;   
const byte Dir_Right = 3;  
//const byte dira = 6;
//const byte dirb = 5;
const byte Speed_Left = 7;   
const byte Speed_Right = 4;   
int readVal,positionVal;   
unsigned int junctionCount = 0;   

void setup() {
  pinMode(junctionPulse,INPUT);
  for(byte i=10;i<=13;i++) {
    pinMode(i,OUTPUT);
  }
  analogWrite(Speed_Left, 50);
  analogWrite(Speed_Right, 50);


  digitalWrite(Dir_Left,LOW);
  digitalWrite(Dir_Right,LOW);

}

void loop() {
  
  if (digitalRead(junctionPulse)) {
    while (digitalRead(junctionPulse)) {
      moveJunction();
    }
    junctionCount++;
  }

  readVal = analogRead(analogPin);   
  
  positionVal = ((float)readVal / 921) * 70;
  
  if (0<positionVal && positionVal <= 14)
    moveLeftextreme();
  
  else if (14 < positionVal && positionVal <= 28)
    moveLeft();
    
  else if (28 < positionVal && positionVal <= 42)
    moveForward();
    
  else if (42 < positionVal && positionVal <= 56)
    moveRight();
  
  else if (56 < positionVal && positionVal <= 70)
    moveRightextreme();
    
   else
    wait();
}

void moveLeftextreme() {
  analogWrite(Speed_Right, 120);
  analogWrite(Speed_Left, 20); 
}
void moveLeft() {
  analogWrite(Speed_Right, 55);
  analogWrite(Speed_Left, 25);
}
void moveForward() {
  // For robot to move forward, both motors have to be same speed
  analogWrite(Speed_Left, 40);
  analogWrite(Speed_Right, 40);
}
void moveRight() {
  analogWrite(Speed_Left, 25);
  analogWrite(Speed_Left, 55); 
}
void moveRightextreme() {
  analogWrite(Speed_Right, 20);
  analogWrite(Speed_Left, 120); 
}

void wait() {
  analogWrite(Speed_Left, 0);  
  analogWrite(Speed_Right, 0);  
}

void moveJunction() {
  delay(500);
  digitalWrite(Dir_Left,HIGH);
  digitalWrite(Dir_Right,LOW);
  //we are goin LEFT!
   analogWrite(Speed_Left, 40);  
  analogWrite(Speed_Right, 40);    
}

