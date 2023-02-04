
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
  Serial.println("Turn on all");
  digitalWrite(RELAY_INI_1, HIGH);
  digitalWrite(RELAY_INI_2, HIGH);
  digitalWrite(RELAY_INI_3, HIGH);
  digitalWrite(RELAY_INI_4, HIGH);
  delay(1000);

  Serial.println("Turn off all");
  digitalWrite(RELAY_INI_1, LOW);
  digitalWrite(RELAY_INI_2, LOW);
  digitalWrite(RELAY_INI_3, LOW);
  digitalWrite(RELAY_INI_4, LOW);
  delay(1000);
}
// void setup() {
//   // initialize digital pin LED_BUILTIN as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// // the loop function runs over and over again forever
// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//   delay(1000);                      // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//   delay(1000);                      // wait for a second
// }
