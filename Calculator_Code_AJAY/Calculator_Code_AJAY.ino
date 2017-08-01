
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12); //pins to LCD

long num1,num2 ;
double total;
char operation,button;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {A2,A3,A4,A5}; //row pinouts 
byte colPins[COLS] = {2,3,4,5}; //pinouts of the keypad
//initializes an instance of the Keypad class
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
lcd.begin(16,2); // initialize the lcd
}

void loop()
{
    while(1) 
        {
        button = customKeypad.getKey(); // Button read
        if (button=='C') // Reset
        {
          num1=0;
          num2=0;
          total=0;
          operation=0;
          lcd.clear();
        }
        
        if (button >='0' && button <='9')
        {
          num1 = num1*10 + (button -'0');
          lcd.setCursor(0,0); 
          lcd.print(num1); // 
        }
        if (num1 !=0 && (button=='-' || button=='+' || button=='*' || button=='/')) 
        {
          operation = button; 
          lcd.setCursor(0,1); 
          lcd.print(operation); 
          break;
        }

    }
    
    while(1) 
    {
        if (button =='C'){break;} 
        button = customKeypad.getKey();
        if (button=='C') 
        {
          num1=0;
          num2=0;
          total=0;
          operation=0;
          lcd.clear();
          break;
        }
        if (button >='0' && button <='9') 
        {
          num2 = num2*10 + (button -'0');
          lcd.setCursor(1,1);
          lcd.print(num2);
        }
        if (button == '=' && num2 !=0)
        {
          domath();
                   
          break;  
        }
    }
    while(1) 
    {
      if (button =='C'){break;} 
      button = customKeypad.getKey();
      if (button =='C') 
        {
           lcd.clear();
           lcd.setCursor(0,0);
           num1=0;
           num2=0;
           total=0;
           operation=0;
           break;
        }
    }

}
void domath() 
{
  switch(operation)
    {
      case '+': // Addition
          total = num1+num2;
          break;
      
      case '-': // Subtraction 
          total = num1-num2;
          break;
      
      case '/': // Division. 
          total = (float)num1/(float)num2;
          break;
      
      case '*': // Multiplication
          total = num1*num2;
          break;
          
    }
   
    lcd.setCursor(0,1);
    lcd.print('=');
    lcd.setCursor(1,1);
    lcd.print(total);
    
} 

