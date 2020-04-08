/*
 * taloselectronics.com
 * Rafael Lozano Rolon
 * soporte@taloelectronics.com
 */
#include <LiquidCrystal_I2C.h>

#define Btn_set A0
#define Sensor A1
#define Buzzer A2

const uint16_t objetivo = 10;
byte flecha[] = {
    B00000,
    B00100,
    B00110,
    B11111,
    B11111,
    B00110,
    B00100,
    B00000};

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.createChar(0, flecha);

    lcd.setCursor(0,0);
    lcd.print("      PUSH-UPS");

    lcd.setCursor(0, 1);
    lcd.write(0);
    lcd.print("Objetivo:");
    lcd.print(objetivo);

    //inicializar pines
    
    pinMode(Sensor, INPUT_PULLUP);
    pinMode(Btn_set, INPUT_PULLUP);
    pinMode(Buzzer, OUTPUT);

    digitalWrite(Buzzer,HIGH);

    Serial.begin(9600);
}

void loop()
{
    double Tiempo_inicial = 0;
    double Tiempo_activo = 0;
    int Contador = 0;
    if (!digitalRead(Btn_set))
    {
        
        while (!digitalRead(Btn_set))
        {
            delay(20);
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("     GET READY  ");
        lcd.setCursor(9,1);
        lcd.print("3");
        digitalWrite(Buzzer,LOW);
        delay(700);
        digitalWrite(Buzzer,HIGH);
        delay(400);

        lcd.setCursor(9, 1);
        lcd.print("2");
        digitalWrite(Buzzer, LOW);
        delay(700);
        digitalWrite(Buzzer, HIGH);
        delay(400);

        lcd.setCursor(9, 1);
        lcd.print("1");
        digitalWrite(Buzzer, LOW);
        delay(700);
        digitalWrite(Buzzer, HIGH);
        
        lcd.clear();
        lcd.print("      PUSH-UPS");

        lcd.setCursor(0, 1);
        lcd.write(0);
        lcd.print("Objetivo:");
        lcd.print(objetivo);

        Tiempo_inicial = millis();
        while (Contador < objetivo)
        {
            Serial.println(Tiempo_activo);
            Tiempo_activo = (millis() - Tiempo_inicial)/1000;
            

            lcd.setCursor(0, 3);
            lcd.write(0);
            lcd.print("Tiempo:");
            lcd.print(Tiempo_activo);
            lcd.print(" s");

            if(!digitalRead(Sensor))
            {
                while (!digitalRead(Sensor))
                {
                    delay(20);
                }
                digitalWrite(Buzzer, LOW);
                delay(200);
                digitalWrite(Buzzer, HIGH);
                Contador++;
            }
            lcd.setCursor(0, 2);
            lcd.write(0);
            lcd.print("Contador:");
            lcd.print(Contador);
        }
        delay(700);
        for (size_t i = 0; i < 3; i++)
        {
            digitalWrite(Buzzer, LOW);
            delay(100);
            digitalWrite(Buzzer, HIGH);
            delay(100);
        }
        
        
    }

    
}