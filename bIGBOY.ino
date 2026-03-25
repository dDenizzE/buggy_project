#include <Servo.h>
Servo myServo;
int ENA = 11;
int IN1 = 12;
int IN2 = 13;
int IN3 = 9;
int IN4 = 8;
int ENB = 10;
int trig_pin = 5;
int echo = 3;
int servo = 6;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig_pin, OUTPUT);
  myServo.attach(6);
  Serial.begin(9600);
  digitalWrite(trig_pin, LOW);
  digitalWrite(echo, LOW);
  myServo.write(90);
}

void moveforward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void moveback(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void moveright(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 150);
}

void moveleft(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);
}

void mservo() {
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}
void measure_distance(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance ");
  Serial.print(distance);
  Serial.print(" cm,");
  
}

void stop_all() {
  
}
void loop() {
  // put your main code here, to run repeatedly:
  measure_distance();
  delay(200);
  if (distance > 15){
    moveforward();
    delay(500);
  }
    else{
      mservo();

    }




}
