/*
* Robot-Control - description here . . .
* Created Date: 6th February, 2023
* 
* Note: We are currently using [Songle] (manufacturer) relay to control robot's 
* movement. Other [Tongling] (manufacturer) relay will be used for other robot operations...
* 
* @To-do:
* Memory Optimization [Done]
* Refactoring [ ]
*
* Note: 
* Please redeclare/recheck values here, according to arduino board...
*/


// Red 4-channel relay. . .
#define SONGLE_RELAY_INI_1 4  
#define SONGLE_RELAY_INI_2 7
#define SONGLE_RELAY_INI_3 5
#define SONGLE_RELAY_INI_4 6

// Blue 4-channel relay . . .
#define TONGLING_RELAY_INI_1 10
#define TONGLING_RELAY_INI_2 2
#define TONGLING_RELAY_INI_3 8
#define TONGLING_RELAY_INI_4 9
#define BAUD_RATE 9600


// Set Flag here for log outputs
#define DEBUG_MODE 1


const char FORWARD  = 'F';
const char BACKWARD = 'B';
const char LEFT     = 'L';
const char RIGHT    = 'R';
const char STOP     = 'X';
const char CAMERA_VIEW_UP    = 'W';
const char CAMERA_VIEW_DOWN  = 'S';
const char CAMERA_VIEW_LEFT  = 'D';
const char CAMERA_VIEW_RIGHT = 'A';



/*
* Singleton Class:
* For One point object reference . . .
*/
class Robot {
public:
  static Robot* init() {
    if (instance_ == nullptr) {
      instance_ = new Robot();
    }
    return instance_;
  }

  static void control() {
    if (Serial.available() > 0) {
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

        default:
          break;
      }
    }
  }

private:
  Robot() {}

  static void move_left() {
    /**
     * Do stuff from here . . . 
     */
  }

  static void move_right() {
    /**
     * Do stuff from here . . . 
     */
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

  // camera angle movement. . .   
  static void move_camera_angle_to_up() {
    /**
     * Do stuff from here . . . 
     */
  }

  static void move_camera_angle_to_down() {
    /**
     * Do stuff from here . . . 
     */
  }

  static void move_camera_angle_to_left() {
    /**
     * Do stuff from here . . . 
     */
  }

  static void move_camera_angle_to_right() {
    /**
     * Do stuff from here . . . 
     */
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
  Robot::init()->control();
}
