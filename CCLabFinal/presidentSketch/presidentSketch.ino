

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;// pin that the LED is attached to



// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

int lives = 2;

int delayTime = 2000;
int multiplyByFactor = 0.85;

boolean fired = false;
boolean killed = false;

void setup() {

  Serial.begin(9600);
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
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
  // read the sensor:
  Serial.println(sensorValue);


sensorVal();

 if (sensorValue >= 235) {
    analogWrite(ledPin, 255);
    
  delay(2000);
  analogWrite(ledPin, 0);
    
  } 


 
}


void sensorVal(){
  sensorValue = analogRead(sensorPin);


  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);
}

