#define LED_PIN 8
#define IR_SENSOR_PIN 13
#define BUTTON_PIN 7
#define BUZZER_PIN 9

byte lastButtonState = LOW;
byte Bewegung = LOW;
byte alarm = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
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
    //   // digitalWrite(LED_PIN, sosState);
    }
  }



  Bewegung = digitalRead(IR_SENSOR_PIN);

  if (Bewegung == HIGH && alarm == HIGH) {
    triggerSirene();
  }
}

void triggerSirene() {
    digitalWrite(LED_PIN, HIGH);
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
    delay(4500);
    digitalWrite(LED_PIN, LOW);
}
