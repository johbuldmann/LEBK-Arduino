#define LED_PIN 8
#define BUTTON_PIN 7

byte lastButtonState = LOW;
byte sosState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  byte buttonState = digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      sosState = (sosState == HIGH) ? LOW : HIGH;
      // digitalWrite(LED_PIN, sosState);
    }
  }
  if (sosState == HIGH) {
    blinkSOS();
  }
}


void blinkSOS() {
  digitalWrite(LED_PIN, HIGH);  //long blink
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(400);
  digitalWrite(LED_PIN, HIGH);  //long blink
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(400);
  digitalWrite(LED_PIN, HIGH);  //long blink
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(400);
  digitalWrite(LED_PIN, HIGH);  //long blink
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);  //short blink
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);  //short blink
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);  //short blink
  delay(200);
  digitalWrite(LED_PIN, LOW);
  
}
