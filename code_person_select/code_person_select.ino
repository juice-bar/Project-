#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

//lcd setup
const int rs = 50, en = 51, d4 = 43, d5 = 42, d6 = 41, d7 = 40;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//lcd setup end

int number = NULL;
const byte ROWS = 4;
const byte COLS = 3;
int pump1 = 2;
int pump2 = 3;
int pump3 = 4;
int pump4 = 5;
int pump5 = 6;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {23, 25, 27, 29};
byte colPins[COLS] = {31, 33, 35};

Keypad useKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int servoPin = 10;
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Welcome! Please");
  lcd.setCursor(0, 1);
  lcd.print("select a drink:");
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);
  pinMode(pump4, OUTPUT);
  pinMode(pump5, OUTPUT);
  myservo.attach(10);
}

void dispenseDrink(int number) {

  //This dispenses drinks

  switch (number) {

    case 1:
      pump(25, 25, 25, 25, false, 20);
      break;

    case 2:

      break;

    case 3:

      break;

    case 4:

      break;

    case 5:
      break;

    case 6:
      break;

    case 7:
      break;

    case 8:
      break;

    case 9:
      break;

    case 10:
      break;
  }

}

void selectParts() {
  int parts1, parts2, parts3, parts4;
  boolean hasPowder, confirmed;

  lcd.clear();
  lcd.print("How many parts ");
  lcd.setCursor(0, 1);
  lcd.print("water? ");
  while (parts1 == NULL) {
    parts1 = selectDrink();
  }

  lcd.clear();
  lcd.print("How many parts ");
  lcd.setCursor(0, 1);
  lcd.print("Gatorade? ");
  while (parts2 == NULL) {
    parts2 = selectDrink();
  }

  lcd.clear();
  lcd.print("How many parts ");
  lcd.setCursor(0, 1);
  lcd.print("Sprite? ");
  while (parts3 == NULL) {
    parts3 = selectDrink();
  }

  lcd.clear();
  lcd.print("How many parts ");
  lcd.setCursor(0, 1);
  lcd.print("Orange Juice? ");
  while (parts4 == NULL) {
    parts4 = selectDrink();
  }

  lcd.clear();
  lcd.print("Do you want ");
  lcd.setCursor(0, 1);
  lcd.print("protein powder? ");
  while (hasPowder == NULL) {
    confirm = useKeypad.getKey();
    if (confirm == '#') {
      hasPowder = true;
    }
    else if (confirm = '*') {
      hasPowder = false;
    }
  }

  partsPump(parts1, parts2, parts3, parts4, hasPowder, 30);

}


void partsPump(int parts1, int parts2, int parts3, int parts4, boolean hasPowder, int totalSeconds) {

  int totalParts = parts1 + parts2 + parts3 + parts4;

  double percentPump1 = parts1 / totalParts;
  double percentPump2 = parts2 / totalParts;
  double percentPump2 = parts3 / totalParts;
  double percentPump2 = parts4 / totalParts;

  lcd.clear();
  lcd.print("Dispensing...")
  pump(percentPump1, percentPump2, percentPump3, percentPump4, hasPowder, totalSeconds);

}

void pump(double percentPump1, double percentPump2, double percentPump3, double percentPump4, boolean hasPowder, int totalSeconds) {

  totalSeconds = totalSeconds * 1000;
  double pumpTime1 = totalSeconds * (percentPump1 / 100.0);
  double pumpTime2 = totalSeconds * (percentPump2 / 100.0);
  double pumpTime3 = totalSeconds * (percentPump3 / 100.0);
  double pumpTime4 = totalSeconds * (percentPump4 / 100.0);

  digitalWrite(pump1, HIGH);
  delay (pumpTime1);
  digitalWrite(pump1, LOW);
  digitalWrite(pump2, HIGH);
  delay (pumpTime2);
  digitalWrite(pump2, LOW);
  digitalWrite(pump3, HIGH);
  delay (pumpTime3);
  digitalWrite(pump3, LOW);
  digitalWrite(pump4, HIGH);
  delay (pumpTime4);
  digitalWrite(pump4, LOW);

  if (hasPowder) {
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(400);
    myservo.write(180);
    delay(400);
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(400);
    myservo.write(180);
    delay(400);
  }

}

void loop() {

  lcd.clear();
  number = selectDrink();

  if (number == NULL || number == 12) {
    lcd.print("Please select a ");
    lcd.setCursor(0, 1);
    lcd.print("drink number");
  }

  else if (number != NULL && number != 12) {
    lcd.clear();
    lcd.print("Do you want to");
    lcd.setCursor(0, 1);
    lcd.print("dispense " + (String)number + "?");

    char confirm;

    while (confirm == NULL) {
      confirm = useKeypad.getKey();
      if (confirm == '#') {
        lcd.clear();
        lcd.print("You've selected");
        lcd.setCursor(0, 1);
        lcd.print("drink number " + (String)number + ":");
        dispenseDrink(number);
        number = NULL;
        delay(2000);
        break;
      }
      else if (confirm == '*') {
        number = NULL;
        break;
      }
      confirm = NULL;
    }
  }


  delay(100);
  lcd.display();

}



int selectDrink() {
  char selector = useKeypad.getKey();

  int ret = number;

  if (selector) {

    switch (selector)

    {

      case '1':
        ret = 1;
        break;

      case '2':
        ret = 2;
        break;

      case '3':
        ret = 3;
        break;

      case '4':
        ret = 4;
        break;

      case '5':
        ret = 5;
        break;

      case '6':
        ret = 6;
        break;

      case '7':
        ret = 7;
        break;

      case '8':
        ret = 8;
        break;

      case '9':
        ret = 9;
        break;

      case '0':
        ret = 10;
        break;

      default:
        ret = 12;
        break;

    }


  }
  return ret;

}
