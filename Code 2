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
  pinMode(pump5,OUTPUT);
}
void dispenseDrink(int number) {

  //This dispenses drinks

  switch (number) {

    case 1:
    digitalWrite(pump1,HIGH);
    delay (15000); // 60000 for 98 milliliters
    digitalWrite(pump1,LOW);
    digitalWrite(pump2,HIGH);
    delay (15000);
    digitalWrite(pump2,LOW); 
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
