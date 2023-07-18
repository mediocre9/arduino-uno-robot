// Red 4-channel relay. . .
#define SONGLE_RELAY_INI_1 13
#define SONGLE_RELAY_INI_2 7
#define SONGLE_RELAY_INI_3 5
#define SONGLE_RELAY_INI_4 6

// Blue 4-channel relay . . .
#define TONGLING_RELAY_INI_1 11
#define TONGLING_RELAY_INI_2 9
#define TONGLING_RELAY_INI_3 8
#define TONGLING_RELAY_INI_4 10

#define BAUD_RATE 9600
#define DELAY 250
#define DEBUG_MODE 1


const char FORWARD = 'F';
const char BACKWARD = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';
const char STOP = 'X';


const char CAMERA_VIEW_UP = 'W';
const char CAMERA_VIEW_DOWN = 'S';
const char CAMERA_VIEW_LEFT = 'D';
const char CAMERA_VIEW_RIGHT = 'A';
const char CAMERA_STOP = '0';


class Robot {
public:
  static Robot* init() {
    if (instance_ == nullptr) {
      instance_ = new Robot();
      stop_camera();
    }
    return instance_;
  }

  static void control() {
    if (Serial.available() > 0) {
      delay(DELAY);
      bluetoothResponse_ = Serial.read();

#if DEBUG_MODE
      Serial.print(bluetoothResponse_);
#endif

      switch (bluetoothResponse_) {

        // for robot movement . . .
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

        case STOP:
          stop_movement();
          break;

          // for camera angle view . . .
        case CAMERA_VIEW_UP:
          move_camera_angle_to_up();
          break;

        case CAMERA_VIEW_DOWN:
          move_camera_angle_to_down();
          break;

        case CAMERA_VIEW_LEFT:
          move_camera_angle_to_left();
          break;

        case CAMERA_VIEW_RIGHT:
          move_camera_angle_to_right();
          break;

        case CAMERA_STOP:
          stop_camera();
          break;
          
        default:
          break;
      }
    }
  }

private:
  Robot() {}

  static void stop_movement() {
    digitalWrite(SONGLE_RELAY_INI_1, LOW);
    digitalWrite(SONGLE_RELAY_INI_2, LOW);
    digitalWrite(SONGLE_RELAY_INI_3, LOW);
    digitalWrite(SONGLE_RELAY_INI_4, LOW);
  }

  static void move_forward() {
    digitalWrite(SONGLE_RELAY_INI_1, LOW);
    digitalWrite(SONGLE_RELAY_INI_2, HIGH);
    digitalWrite(SONGLE_RELAY_INI_3, LOW);
    digitalWrite(SONGLE_RELAY_INI_4, HIGH);
  }

  static void move_backward() {
    digitalWrite(SONGLE_RELAY_INI_1, HIGH);
    digitalWrite(SONGLE_RELAY_INI_2, LOW);
    digitalWrite(SONGLE_RELAY_INI_3, HIGH);
    digitalWrite(SONGLE_RELAY_INI_4, LOW);
  }

  static void move_left() {
    digitalWrite(SONGLE_RELAY_INI_1, LOW);
    digitalWrite(SONGLE_RELAY_INI_2, HIGH);
    digitalWrite(SONGLE_RELAY_INI_3, HIGH);
    digitalWrite(SONGLE_RELAY_INI_4, LOW);
  }

  static void move_right() {
    digitalWrite(SONGLE_RELAY_INI_1, HIGH);
    digitalWrite(SONGLE_RELAY_INI_2, LOW);
    digitalWrite(SONGLE_RELAY_INI_3, LOW);
    digitalWrite(SONGLE_RELAY_INI_4, HIGH);
  }



  // camera angle movement. . .
  static void stop_camera() {
    digitalWrite(TONGLING_RELAY_INI_1, HIGH);
    digitalWrite(TONGLING_RELAY_INI_2, HIGH);
    digitalWrite(TONGLING_RELAY_INI_3, HIGH);
    digitalWrite(TONGLING_RELAY_INI_4, HIGH);
  }

  static void move_camera_angle_to_up() {
    digitalWrite(TONGLING_RELAY_INI_1, HIGH);
    digitalWrite(TONGLING_RELAY_INI_2, LOW);
    digitalWrite(TONGLING_RELAY_INI_3, HIGH);
    digitalWrite(TONGLING_RELAY_INI_4, LOW);
  }

  static void move_camera_angle_to_down() {
    digitalWrite(TONGLING_RELAY_INI_1, LOW);
    digitalWrite(TONGLING_RELAY_INI_2, HIGH);
    digitalWrite(TONGLING_RELAY_INI_3, LOW);
    digitalWrite(TONGLING_RELAY_INI_4, HIGH);
  }

  static void move_camera_angle_to_left() {
    digitalWrite(TONGLING_RELAY_INI_1, LOW);
    digitalWrite(TONGLING_RELAY_INI_2, HIGH);
    digitalWrite(TONGLING_RELAY_INI_3, HIGH);
    digitalWrite(TONGLING_RELAY_INI_4, LOW);
  }

  static void move_camera_angle_to_right() {
    digitalWrite(TONGLING_RELAY_INI_1, HIGH);
    digitalWrite(TONGLING_RELAY_INI_2, LOW);
    digitalWrite(TONGLING_RELAY_INI_3, LOW);
    digitalWrite(TONGLING_RELAY_INI_4, HIGH);
  }

private:
  static Robot* instance_;
  static char bluetoothResponse_;
};
Robot* Robot::instance_ = nullptr;
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
  Robot::init()->control();
}
