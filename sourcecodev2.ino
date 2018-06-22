/*
 * 
 * MADE BY NABIL RIDHWANSHAH
 * TWITTERl @SKRURAI1
 * INSTAGRAM: @NAB1LLL
 * GITHUB: BUILTBYNABIL
*/

/*

ITEMS NEEDED:
- RGB LED
- SOUND SENSOR
- ARDUINO MEGA

FOR BEGINNERS:
1. CONNECT SOUND SENSOR PIN 52
2. CONNECT RGB LED TO RESPECTIVE PINS:
  R = 5
  G = 6
  B = 7

FOR ADVANCED USERS:
IF YOU KNOW THAT YOUR SOUND SENSOR SUPPORTS ANALOG INPUT, CONNECT IT TO THE ANALOG INPUT AND CHANGE THE 'int soundSensor' TO THE ANALOG INPUT PIN
*/

int r = 5;
int g = 6;
int b = 7;

int soundSensor = 52;

int pot = A0;

void setup(){
  pinMode(r , OUTPUT);
  pinMode(g , OUTPUT);
  pinMode(b , OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int soundSensorReading = digitalRead(soundSensor);
  int potReading = analogRead(pot);

  
  int potReadingMap = map(potReading , 0 , 1024 , 0 , 3);

  Serial.println(potReadingMap);
  
  // 1 is idle || 0 is active
  if(soundSensorReading == 1){
    setColor(0,0,0);
  }else{

    switch(potReadingMap) {
      case 0:
      setColor(255,0,0);
      break;

      case 1:
      setColor(0,255,0);
      break;

      case 2:
      setColor(0,0,255);
      break;
    }
    
  }
  
}

void setColor(int rValue, int gValue, int bValue){
  analogWrite(r , rValue);
  analogWrite(g , gValue);
  analogWrite(b , bValue);
}
