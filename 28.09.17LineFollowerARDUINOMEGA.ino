const byte analogPin = A0;   
const byte junctionPulse = 10;   
const byte dir1 = 2;   
const byte dir2 = 3; 
const byte pwm1 = 7;   
const byte pwm2 =4;  

const byte dira = 6;
const byte dirb = 5;    
int readVal, positionVal;  
unsigned int junctionCount = 0;   

void setup() {
  pinMode(junctionPulse, INPUT);

  for (byte i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }

  analogWrite(pwm1, 50);
  analogWrite(pwm2, 50);
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  digitalWrite(dira, LOW);
  digitalWrite(dirb, HIGH);

}

void loop() {
  if (digitalRead(junctionPulse)) {
    while (digitalRead(junctionPulse)) {
      moveForward();
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
  
  analogWrite(pwm2, 120);
  analogWrite(pwm1, 20); 
  
}
void moveLeft() {

  analogWrite(pwm2, 55);
  analogWrite(pwm1, 25);
  
}

void moveForward() {
 
  analogWrite(pwm1, 40);
  analogWrite(pwm2, 40);
  
}

void moveRight() {
  
  analogWrite(pwm2, 25);
  analogWrite(pwm1, 55); 
  
}

void moveRightextreme() {
  
  analogWrite(pwm2, 20);
  analogWrite(pwm1, 120); 
  
}

void wait() {
  
  analogWrite(pwm1, 0);  
  analogWrite(pwm2,0);
  
}



