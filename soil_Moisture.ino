int analogPin = A0;
int moisture;
int percentage;

void setup() {
  Serial.begin(9600);
}
void loop() {
  moisture=analogRead(analogPin);
  Serial.print("Raw: ");
  Serial.print(moisture);
  Serial.println("");
  delay(1000);
 }
