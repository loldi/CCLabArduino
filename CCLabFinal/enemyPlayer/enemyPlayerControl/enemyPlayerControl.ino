
// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;// pin that the LED is attached to
const int gun = 8;

int enemy2 = 5;
int gun2 = 3;


// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

int lives = 2;

boolean fired = false;
boolean killed = false;

void setup() {

  Serial.begin(9600);
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(13, HIGH);


  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  
  sensorVal();

  if (lives == 0) {
    killed = true;
    delay(3000);
    lives = 2;
    killed = false;
  }

//  if (lives == 2){
  enemyControl(9,8);
//  delay(500);
//  enemyControl(5,3);
//  }
//
//  if (lives == 1){
//    enemyControl(5,3);
//  }
  Serial.println(sensorValue);
}

void enemyControl(int pinNumber, int gunNumber) {

  

  if (lives > 0 && killed == false) {
    Serial.println("preparing to fire..");
    digitalWrite(pinNumber, HIGH);
    delay(1000);
    digitalWrite(pinNumber, LOW);
    delay(500);
    digitalWrite(pinNumber, HIGH);
    delay(500);
    digitalWrite(pinNumber, LOW);
    delay(250);
    digitalWrite(pinNumber, HIGH);
    delay(250);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);

    digitalWrite(pinNumber, HIGH);

    digitalWrite(gunNumber, HIGH);
    Serial.println("FIRED");
    delay(500);
    digitalWrite(gunNumber, LOW);
    delay(500);
    playerControl(pinNumber);
    Serial.println("FIRE BACK!");
    delay(2000);
    digitalWrite(pinNumber, LOW);

  }   else {
    digitalWrite(gunNumber, LOW);
    digitalWrite(pinNumber, LOW);
  }

}

void playerControl(int pinNumber) {

  sensorVal();
  if (sensorValue >= 235 && lives > 0) {
    tone(6, 440);
    delay(1000);
    noTone(6);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    delay(100);
    digitalWrite(pinNumber, HIGH);
    delay(100);
    digitalWrite(pinNumber, LOW);
    lives = lives - 1;
    digitalWrite(pinNumber, HIGH);
  } else {
    analogWrite(pinNumber, 0);
  }

}

void sensorVal() {
  sensorValue = analogRead(sensorPin);


  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
}



