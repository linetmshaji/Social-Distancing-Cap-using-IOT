
//Defines the pins that connected to the I/O pins of the Arduino Uno Board
#define trigPin 7
#define echoPin 6
#define orange 9
#define red 8
#define buzzer 5
//Defines frequncy of sound to be produced
int sound = 150;
int sound1 = 300;
// Code for configuring pins as input or output
void setup(){
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(orange, OUTPUT);
pinMode(red, OUTPUT);
pinMode(buzzer, OUTPUT);
}
// code for continuously measuring the distance between object and the
sensor and to provide alert by glowing LED and by producing buzzer code
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
/*Sound travels 340 m/s. Here We have to caluclate distance in cm, So we need to convert the speed into cm/micro seconds, 
then the speed become 29.412 ms/cm.Formula = [(Time/2)]/Speed(29.1)*/
distance = (duration/2) / 29.412;
if (distance <=122) {
digitalWrite(orange, HIGH);
sound1 = 150;
}
else {
digitalWrite(orange,LOW);
}
if (distance <=80) {
digitalWrite(red, HIGH);
sound = 300;
}else {
digitalWrite(red,LOW);
}
if (distance <= 80){
Serial.print(distance);
Serial.println(" cm");
tone(buzzer, sound);
}else if(distance>80 && distance<=122){
Serial.print(distance);
Serial.println(" cm");
tone(buzzer, sound1);
}else {
Serial.println("Out of range");
noTone(buzzer);
}
delay(500);
}
