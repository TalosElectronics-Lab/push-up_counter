#include <LiquidCrystal_I2C.h>

#define Btn_mas A0
#define Btn_menos A1
#define Btn_set A2
#define Sensor A3

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("contador push-ups");

    //inicializar pines
    pinMode(Btn_mas, INPUTPULLUP);
    pinMode(Btn_menos, INPUTPULLUP);
    pinMode(Btn_set, INPUTPULLUP);

}

void loop()
{
    
}