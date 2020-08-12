#define LED_BUILTIN 2

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.print("Turning on LED\n");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  Serial.print("Turning off LED\n");
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}
