#include <Servo.h>
#define SERVO_PIN 11
#define LED_PIN_ALARM 8
#define LED_PIN_STATUS 6
#define IR_SENSOR_PIN 13
#define BUTTON_PIN 7
#define BUZZER_PIN 4

Servo myServo;
byte lastButtonState = LOW;
byte Bewegung = LOW;
byte alarm = LOW;

void setup() {
  myServo.attach(SERVO_PIN);
  pinMode(LED_PIN_ALARM, OUTPUT);
  pinMode(LED_PIN_STATUS, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(IR_SENSOR_PIN, INPUT);
}

void loop() {



  byte buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      alarm = (alarm == HIGH) ? LOW : HIGH;
    //   // digitalWrite(LED_PIN_ALARM, sosState);
    }
  }

  if (alarm == HIGH) {
    digitalWrite(LED_PIN_STATUS, HIGH);

  } else if (alarm == LOW) {
    digitalWrite(LED_PIN_STATUS, LOW);
  }

  Bewegung = digitalRead(IR_SENSOR_PIN);

  if (Bewegung == HIGH && alarm == HIGH) {
    moveServo();
    triggerSirene();
  }
}

void moveServo() {
    myServo.write(90);
    delay(500);
    myServo.write(180);
    delay(1000);
}

void triggerSirene() {
    digitalWrite(LED_PIN_ALARM, HIGH);
      tone(BUZZER_PIN, 392);
    delay(800);
      tone(BUZZER_PIN, 660);
    delay(167);
      tone(BUZZER_PIN, 392);
    delay(167);
      tone(BUZZER_PIN, 660);
    delay(167);
      tone(BUZZER_PIN, 392);
    delay(800);
      noTone(BUZZER_PIN);
    delay(1500);
    digitalWrite(LED_PIN_ALARM, LOW);
}
