#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int trigPin = 9;
int echoPin = 10;
int relayPin = 7;
int led = 5;
long duration;
int distance;

void setup() {
  lcd.init();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledpin, OUTPUT);
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
  lcd.setCursor(0,0);
  lcd.print("DISTANCE: ");
  lcd.println(distance);

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 10) {
    digitalWrite(relayPin, HIGH);
    delay(2000);
    lcd.setCursor(1,0);
    lcd.print("WASH YOUR HANDS");
    digitalwrite(ledpin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(ledpin, LOW);
  }

  delay(500);
}
