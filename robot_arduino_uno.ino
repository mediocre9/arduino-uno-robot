/*
* Robot-Control - description here . . .
* Created Date: 6th February, 2023
* 
* Note: We are currently using [Songle] (manufacturer) relay to control robot's 
* movement. Other [Tongling] (manufacturer) relay will be used for other robot operations...
* 
*/


// Red 4-channel relay. . .
#define SONGLE_RELAY_INI_1 4  // broken pin here . . . brown pair
#define SONGLE_RELAY_INI_2 7
#define SONGLE_RELAY_INI_3 5
#define SONGLE_RELAY_INI_4 6

// Blue 4-channel relay . . .
#define TONGLING_RELAY_INI_1 10
#define TONGLING_RELAY_INI_2 2
#define TONGLING_RELAY_INI_3 8
#define TONGLING_RELAY_INI_4 9
#define BAUD_RATE 9600

#define DEBUG_MODE 1


const char FORWARD = 'F';
const char BACKWARD = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';
const char STOP = 'X';


// Singleton robot class . . .
class Robot {
public:
  static Robot* init() {
    if (instance_ == nullptr) {
      instance_ = new Robot();
    }
    control();
    return instance_;
  }

  static void control() {
    if (Serial.available() > 0) {
      bluetoothResponse_ = Serial.read();
      Serial.print(bluetoothResponse_);
      switch (bluetoothResponse_) {
        case FORWARD:
          move_forward();
          break;

        case BACKWARD:
          move_backward();
          break;

        case LEFT:
          move_left();
          break;

        case RIGHT:
          move_right();
          break;

        default:
#if DEBUG_MODE
          Serial.print(bluetoothResponse_);
#endif
          break;
      }
    }
  }

private:
  Robot() {}

  static void move_left() {
    digitalWrite(TONGLING_RELAY_INI_1, LOW);
    digitalWrite(TONGLING_RELAY_INI_2, LOW);
    digitalWrite(TONGLING_RELAY_INI_3, LOW);
    digitalWrite(TONGLING_RELAY_INI_4, LOW);
  }

  static void move_right() {
    digitalWrite(TONGLING_RELAY_INI_1, HIGH);
    digitalWrite(TONGLING_RELAY_INI_2, HIGH);
    digitalWrite(TONGLING_RELAY_INI_3, HIGH);
    digitalWrite(TONGLING_RELAY_INI_4, HIGH);
  }

  static void move_forward() {
    digitalWrite(SONGLE_RELAY_INI_1, HIGH);
    digitalWrite(SONGLE_RELAY_INI_2, HIGH);
    digitalWrite(SONGLE_RELAY_INI_3, HIGH);
    digitalWrite(SONGLE_RELAY_INI_4, HIGH);
  }

  static void move_backward() {
    digitalWrite(SONGLE_RELAY_INI_1, LOW);
    digitalWrite(SONGLE_RELAY_INI_2, LOW);
    digitalWrite(SONGLE_RELAY_INI_3, LOW);
    digitalWrite(SONGLE_RELAY_INI_4, LOW);
  }

private:
  static Robot* instance_;
  static char bluetoothResponse_;
};
Robot* Robot::instance_ = 0;
char Robot::bluetoothResponse_ = '0';


void initializeRelays() {
  pinMode(SONGLE_RELAY_INI_1, OUTPUT);
  pinMode(SONGLE_RELAY_INI_2, OUTPUT);
  pinMode(SONGLE_RELAY_INI_3, OUTPUT);
  pinMode(SONGLE_RELAY_INI_4, OUTPUT);

  pinMode(TONGLING_RELAY_INI_1, OUTPUT);
  pinMode(TONGLING_RELAY_INI_2, OUTPUT);
  pinMode(TONGLING_RELAY_INI_3, OUTPUT);
  pinMode(TONGLING_RELAY_INI_4, OUTPUT);
}

void setup() {
  Serial.begin(BAUD_RATE);
  initializeRelays();
}

void loop() {
  Robot::init();
}
