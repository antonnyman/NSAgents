// Segments. These are the diffrent segments that make up the digit. LOW means ON.
/*
 ___       a
|   |    f   b
|___|      g
|   |    e   c
|___|o     d    p



~ CONNECTION DIAGRAM ~
Arduino pin left, segment middle, display pin right

0 - a - 14
1 - b - 16
2 - c - 13
3 - d - 3
4 - e - 5
5 - f - 11
6 - g - 15
7 - f - 7
8 - d1 - 6
9 - d2 - 8
10 -
11 -
12 -
A0 - plus button
A2 - minus button


*/

int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;
int p = 7;

// digits
int d1 = 9;
int d2 = 8;
int d3 = 9;
int d4 = 8;
int led1 = 13;
int led2 = 12;

// counters, resets et. al.
int counter1 = 0;
int counter2 = 0;
boolean once1 = false;
boolean once2 = false;

int firstSerialNumber;
int secondSerialNumber;


void setup() {
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
//  pinMode(A3, INPUT);
  
  // Serial.begin(9600);
}

void loop() {
//  firstSerialNumber = 0;
//  secondSerialNumber = Serial.read();
  
//  if(digitalRead(A0) == HIGH) {
//    counter1++;
//    delay(300);
//  }
//  if(counter1 > 9) {
//    counter2++;
//    counter1 = 0;
//  }
//
//digitalWrite(led, HIGH);

 if(digitalRead(A1) == HIGH) {
   if(!once1) {
     delay(500);
     digitalWrite(led1, HIGH);
     once1 = true;
   }
 }
  if(digitalRead(A1) == HIGH) {
    if(once1) {
      delay(500);
   digitalWrite(led1, LOW);
   once1 = false;
    }
 }
// 
//  if(digitalRead(A1) == HIGH) {
//   if(!once2) {
//     delay(500);
//     digitalWrite(led2, HIGH);
//     once2 = true;
////   if(counter1 == 0) {
////     counter2--;
////     counter1 = 9;
////   } else
////   counter1--;
////   delay(300); 
//   }
// }
//  if(digitalRead(A1) == HIGH) {
//    if(once2) {
//      delay(500);
//   digitalWrite(led2, LOW);
//   once2 = false;
   
//   if(counter1 == 0) {
//     counter2--;
//     counter1 = 9;
//   } else
//   counter1--;
//   delay(300);
//    }
// }

//if(digitalRead(A2) == HIGH) {
//    counter1++;
//    delay(300);
//  }
//if(counter1 > 9) {
//    counter2++;
//    counter1 = 0;
//}
//
//if(digitalRead(A3) == HIGH) {
//   if(counter1 == 0) {
//     counter2--;
//     counter1 = 9;
//   } else
//   counter1--;
//   delay(300);
//}


pickDigit(1);
displayNumber(counter1);
clearLEDs();

pickDigit(2);
displayNumber(counter2);
clearLEDs();
}

void pickDigit(int x)
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
    case 1: digitalWrite(d1, HIGH); break;
    case 2: digitalWrite(d2, HIGH); break;
    case 3: digitalWrite(d3, HIGH); break;
    default: digitalWrite(d4, HIGH); break;
  }
}

void displayNumber(int x)
{
  switch(x)
  {
    default: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
}

// Segment library
void clearLEDs()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void zero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void three()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}

void nine()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}