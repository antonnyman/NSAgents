void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}
 
void char_from_ruby(char x) {
  if(x == 'r') {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  
  }
  if(x == 'g') {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  
  }
  if(x == 'b') {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  }
  if(x == 'y') {
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  }
}
 
void loop() {
  if(Serial.available() > 0) {
    byte byte_read = Serial.read();
    char_from_ruby((char)byte_read);
  }
 
}