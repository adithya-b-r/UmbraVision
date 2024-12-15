#define echoPin 2 // Echo pin
#define trigPin 3 // Trig pin
#define buzzer 4

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 90){
    digitalWrite(buzzer, HIGH);
    Serial.println("Buzzer ON");
    delay(300);
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}