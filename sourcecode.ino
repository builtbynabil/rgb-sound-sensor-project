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

void setup(){
  pinMode(r , OUTPUT);
  pinMode(g , OUTPUT);
  pinMode(b , OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int soundSensorReading = digitalRead(soundSensor);
  
  Serial.println(soundSensorReading);
  
  // 0 & 3 = red
  // 1 & 4 = green
  // 2 & 5 = blue
  int chooser = random(0,5);
  if(soundSensorReading == 1){
    setColor(0,0,0);
  }else{
    
    if(chooser == 0 || chooser == 3){
      setColor(255,0,0);
    }else if(chooser == 1 || chooser == 4){
      setColor(0,255,0);
    }else if(chooser == 2 || chooser == 5){
      setColor(0,0,255);
    }else{
      setColor(0,0,0);
    }
    
  }
  
}

void setColor(int rValue, int gValue, int bValue){
  analogWrite(r , rValue);
  analogWrite(g , gValue);
  analogWrite(b , bValue);
}
