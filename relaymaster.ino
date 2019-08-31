
int incomingByte = 0;
const int relayA =  3;
const int relayB = 12;
const int relayC = 6;
const int relayD = 11;
const int relayE = 4;
const int relayF = 2;

int astate = LOW;
int bstate = LOW;
int cstate = LOW;
int dstate = LOW;
int estate = LOW;
int fstate = LOW;


unsigned long prevA = 0;
unsigned long prevB = 0;
unsigned long prevC = 0;
unsigned long prevD = 0;
unsigned long prevE = 0;
unsigned long prevF = 0;




bool activeA = false;
bool activeB = false;
bool activeC = false;
bool activeD = false;
bool activeE = false;
bool activeF = false;





int smallincrement = 1;
int bigincrement = 20;
long interval = 200;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(relayA, OUTPUT);
  pinMode(relayB, OUTPUT);
  pinMode(relayC, OUTPUT);
  pinMode(relayD, OUTPUT);
  pinMode(relayE, OUTPUT);
  pinMode(relayF, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte);

    if (incomingByte == 97) { //a: decrease interval
      interval = interval - bigincrement;
      if (interval < 0) {
        interval = 0;
      }
      Serial.print("interval: ");
      Serial.println(interval);
    }
    if (incomingByte == 113) { //q: increase interval
      interval = interval + bigincrement;
      Serial.print("interval: ");
      Serial.println(interval);
    }
    if (incomingByte == 115) { //s: decrease interval
      interval = interval - smallincrement;
      if (interval < 0) {
        interval = 0;
      }
      Serial.print("interval: ");
      Serial.println(interval);
    }
    if (incomingByte == 119) { //w: increase interval
      interval = interval + smallincrement;
      Serial.print("interval: ");
      Serial.println(interval);
    }
    



    
    if (incomingByte == 49) { //1: toggle
      activeA = !activeA;
      if(activeA){
        Serial.println("A activated.");
      } else {
        Serial.println("A de-activated.");
      }      
    }
    if (incomingByte == 50) { //2: toggle
      activeB = !activeB;
      if(activeB){
        Serial.println("B activated.");
      } else {
        Serial.println("B de-activated.");
      }      
    }
    if (incomingByte == 51) { //3: toggle
      activeC = !activeC;
      if(activeC){
        Serial.println("C activated.");
      } else {
        Serial.println("C de-activated.");
      }      
    }
    if (incomingByte == 52) { //4: toggle
      activeD = !activeD;
      if(activeD){
        Serial.println("D activated.");
      } else {
        Serial.println("D de-activated.");
      }      
    }
    if (incomingByte == 53) { //5: toggle
      activeE = !activeE;
      if(activeE){
        Serial.println("E activated.");
      } else {
        Serial.println("E de-activated.");
      }      
    }
    if (incomingByte == 54) { //6: toggle
      activeF = !activeF;
      if(activeF){
        Serial.println("F activated.");
      } else {
        Serial.println("F de-activated.");
      }      
    }
    
    

  }
  unsigned long currentMillis = millis();
  if (currentMillis - prevA >= (interval + ((interval / 6) * 1)) && activeA) {
    prevA = currentMillis;
    if (astate == LOW) {
      astate = HIGH;
    } else {
      astate = LOW;
    }
    digitalWrite(relayA, astate);
  }
  if (currentMillis - prevB >= (interval + ((interval / 6) * 2)) && activeB) {
    prevB = currentMillis;
    if (bstate == LOW) {
      bstate = HIGH;
    } else {
      bstate = LOW;
    }
    digitalWrite(relayB, bstate);
  }
  if (currentMillis - prevC >= (interval + ((interval / 6) * 3)) && activeC) {
    prevC = currentMillis;
    if (cstate == LOW) {
      cstate = HIGH;
    } else {
      cstate = LOW;
    }
    digitalWrite(relayC, cstate);
  }
  if (currentMillis - prevD >= (interval + ((interval / 6) * 4)) && activeD) {
    prevD = currentMillis;
    if (dstate == LOW) {
      dstate = HIGH;
    } else {
      dstate = LOW;
    }
    digitalWrite(relayD, dstate);
  }
  if (currentMillis - prevE >= (interval + ((interval / 6) * 5)) && activeE) {
    prevE = currentMillis;
    if (estate == LOW) {
      estate = HIGH;
    } else {
      estate = LOW;
    }
    digitalWrite(relayE, estate);
  }
  if (currentMillis - prevF >= (interval + ((interval / 6) * 6)) && activeF) {
    prevF = currentMillis;
    if (fstate == LOW) {
      fstate = HIGH;
    } else {
      fstate = LOW;
    }
    digitalWrite(relayF, fstate);
  }
  

}
