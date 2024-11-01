#include <Arduino.h>
#include "displayLCD.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27 ,20,4);


byte vintePorCento[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

byte quarentaPorCento[] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};


byte sessentaPorCento[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};


byte oitentaporCento[] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};


void inicializaLCD ()
{
    lcd.init();
    lcd.backlight();
    lcd.print("Tempo de espera");
    lcd.createChar(0, vintePorCento);
    lcd.createChar(1, quarentaPorCento);
    lcd.createChar(2, sessentaPorCento);
    lcd.createChar(3, oitentaporCento);
}

void temporizador(byte linha, int tempo, int tempoTotal)
{
 lcd.setCursor(0, linha);  
 byte blocosPreenchidos = tempo * 20 / tempoTotal;
 byte blocoParcial = tempo * 20 %  tempoTotal;

for(int i = 0; i < blocosPreenchidos; i++)
{
    lcd.write(byte(255));
}

for(int i = blocosPreenchidos + (blocoParcial > 0 ? 1 : 0); i < 20; i++)
{
    lcd.print(" ");
}

}
