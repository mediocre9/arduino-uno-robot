// Prototype code . . .

#define RELAY_INI_1 11
#define RELAY_INI_2 10
#define RELAY_INI_3 9
#define RELAY_INI_4 8

#define BAUD_RATE 9600


void setup() {
  Serial.begin(BAUD_RATE);

  pinMode(RELAY_INI_1, OUTPUT);
  pinMode(RELAY_INI_2, OUTPUT);
  pinMode(RELAY_INI_3, OUTPUT);
  pinMode(RELAY_INI_4, OUTPUT);
}


void loop() {
  const int SLEEP_MODE = 500;
  
  digitalWrite(RELAY_INI_1, HIGH);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_2, HIGH);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_3, HIGH);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_4, HIGH);
  delay(SLEEP_MODE);

  digitalWrite(RELAY_INI_1, LOW);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_2, LOW);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_3, LOW);
  delay(SLEEP_MODE);
  digitalWrite(RELAY_INI_4, LOW);
  delay(SLEEP_MODE);
}
