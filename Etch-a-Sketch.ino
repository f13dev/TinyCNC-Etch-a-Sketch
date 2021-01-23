#include <Servo.h>
#include <Encoder.h>

#define SERVO_X 11
#define SERVO_Y 12
#define SERVO_Z 10

int BTN_UP = 6;
int BTN_DN = 7;

Encoder knobX(2, 3);
Encoder knobY(4, 5);

int increment = 1;

struct point {
  float x;
  float y;
  float z;
};

Servo servoX;
Servo servoY;
Servo servoZ;
struct point actuatorPos;


void setup() {
  Serial.begin( 115200 );
  servoX.attach(SERVO_X);
  servoY.attach(SERVO_Y);
  servoZ.attach(SERVO_Z);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DN, INPUT_PULLUP);

  actuatorPos.x = 80;
  actuatorPos.y = 110;
  actuatorPos.z = 260;

  servoX.write(actuatorPos.x);
  servoY.write(actuatorPos.y);
  servoZ.write(actuatorPos.z);

  Serial.println( "Digital Etchasketch" );
}

long encX = -999;
long encY = -999;

void loop() {
  long newX, newY;
  newX = knobX.read();
  newY = knobY.read();
  if (newX != encX) {
    if (newX > encX) {
      actuatorPos.x = actuatorPos.x + increment;
      servoX.write(actuatorPos.x);
    } else {
      actuatorPos.x = actuatorPos.x - increment;
      servoX.write(actuatorPos.x);
    }
  }
  if (newY != encY) {
    if (newY > encY) {
      actuatorPos.y = actuatorPos.y + increment;
      servoY.write(actuatorPos.y);
    } else {
      actuatorPos.y = actuatorPos.y - increment;
      servoY.write(actuatorPos.y);
    }
  }
  int up = digitalRead(6);
  int dn = digitalRead(7);
  if (up == LOW) {
    servoZ.write(10);
  }
  if (dn == LOW) {
    servoZ.write(260);
  }
  if (newX != encX || newY != encY) {
    Serial.print("X = ");
    Serial.print(newX);
    Serial.print(", Y = ");
    Serial.print(newY);
    Serial.println();
    encX = newX;
    encY = newY;
  }
}
