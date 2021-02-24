int sensorPin0 = A0;
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;
int sensorPin4 = A4;
int sensorPin5 = A5;
int sensorPin6 = A6;
int sensorPin7 = A7;

int sensorValue0 = 0;
int sensorValue1 = 0; 
int sensorValue2 = 0; 
int sensorValue3 = 0; 
int sensorValue4 = 0; 
int sensorValue5 = 0; 
int sensorValue6 = 0; 
int sensorValue7 = 0; 
double sensorValueCom = 0;
int sensorValueSum = 0;
double a = 1000/7;

int i = 0;
double sumOf12 = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {

  if (i == 12)
  {
    i = 0;
  }
  
  sensorValue0 = 1024 - analogRead(sensorPin0);
  sensorValue1 = 1024 - analogRead(sensorPin1);
  sensorValue2 = 1024 - analogRead(sensorPin2);
  sensorValue3 = 1024 - analogRead(sensorPin3);
  sensorValue4 = 1024 - analogRead(sensorPin4);
  sensorValue5 = 1024 - analogRead(sensorPin5);
  sensorValue6 = 1024 - analogRead(sensorPin6);
  sensorValue7 = 1024 - analogRead(sensorPin7);
  sensorValueSum = (sensorValue0 + sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5 + sensorValue6 + sensorValue7);

  sensorValueCom = (0 * sensorValue0 + a * sensorValue1 + 2*a * sensorValue2 + 3*a * sensorValue3 + 4*a * sensorValue4 + 5*a * sensorValue5 + 6*a * sensorValue6 + 7*a * sensorValue7) / (sensorValueSum);
 
  /* Serial.print(sensorValue0);
  Serial.print(" ");
  Serial.print(sensorValue1);
  Serial.print(" ");
  Serial.print(sensorValue2);
  Serial.print(" ");
  Serial.print(sensorValue3);
  Serial.print(" ");
  Serial.print(sensorValue4);
  Serial.print(" ");
  Serial.print(sensorValue5);
  Serial.print(" ");
  Serial.print(sensorValue6);
  Serial.print(" ");
  Serial.print(sensorValue7);
  Serial.print(" ");
  Serial.println(" "); */

  double filter [12];
  filter[i] = sensorValueCom;
  for (t; t < 12; t++)
  {
    sumOf12 += filter[t];
  }
  
  double avg = sumOf12 / 12;

  if (avg < 500)
  {
    Serial.println("turn left");
  }
  else if (avg > 500)
  {
    Serial.println("turn right");
  }
  else 
  {
    Serial.println(" ");
  }
  
  Serial.print(sensorValueCom);
  Serial.print(" ");
  Serial.print(avg);
  Serial.println(" ");

  i++;

  delay(20);
}
