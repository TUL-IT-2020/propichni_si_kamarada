#define FORCE_SENSOR_PIN A5
#define SEL 4
#define TIME 1

void setup() {
  Serial.begin(9600);
  pinMode(SEL, OUTPUT);
}

void loop() {

  digitalWrite(SEL, 0);
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  Serial.print("Force sensor reading = ");
  Serial.print(analogReading);
  delay(TIME);
  
  digitalWrite(SEL, 1);
  analogReading = analogRead(FORCE_SENSOR_PIN);
  Serial.print("\t Force dumy reading = ");
  Serial.println(analogReading);
  delay(TIME);
}
