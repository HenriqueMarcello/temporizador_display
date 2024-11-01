#include <Arduino.h>
#include "displayLCD.h"

#define Button 0  
int contador = 100;

void setup() 
{
    pinMode(Button, INPUT_PULLUP);  
    inicializaLCD();
}

void loop()
{
    temporizador(3, contador, 100);  
    if (digitalRead(Button) == LOW)  
    {
        contador = 100; 
    }
    if (contador > 0)
        contador--;
    else
        contador = 100; 

    delay(1000);  
}