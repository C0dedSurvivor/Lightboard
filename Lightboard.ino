int currentLight = 0;

void setup() {
  // initialize digital pins as outputs.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    bool left = analogRead(A3) > 1000;
    bool right = analogRead(A0) > 1000;
    bool innerleft = analogRead(A2) > 1000;
    bool innerright = analogRead(A1) > 1000;
    if(left){
        digitalWrite(3 + currentLight, HIGH);
    }
    if(right){
        digitalWrite(8 - currentLight, HIGH);
    }
    if(innerleft){
        digitalWrite(3 + currentLight, HIGH);
        digitalWrite(8 - currentLight, HIGH);
    }
    if(innerright){
        digitalWrite(8 - ((2 * currentLight) % 6), HIGH);
    }
    if(left || right || innerleft || innerright)
        currentLight += 1;
    if(currentLight > 5)
        currentLight = 0;
    delay(100);              // wait for a second
}
