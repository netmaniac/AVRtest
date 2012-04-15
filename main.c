#include <avr/interrupt.h>	// Definicje nazw pinow układu

#define F_CPU 1000000UL		// Zapisanie predkosci procesora w Hz dla biblioteki delay.h
#include <util/delay.h>


// Deklaracja funkcji mrugajacej dioda
void blinkEm(uint8_t count);


// Glowna funkcja programu
int main()
{
  DDRD = _BV(PD4); // Ustawienie PORT D 4 (noga 8)jako wyjscie
  
  while (1) // Petla, ktora nigdy sie nie konczy
  {
    blinkEm(1); // Wywolanie funkcji mrugajacej dioda
  }
}


// Funkcja mrugajaca dioda LED ustalona ilosc razy
void blinkEm(uint8_t count)
{
  // petla ilosci mrugniec
  // dziala az zmienna count osiagnie wartosc 0
  while (count > 0)
  {
    // Wlaczenie diody led
    PORTD = _BV(PD4);
    // oczekiwanie 1 s
    _delay_ms(1000);

    // wylaczenie diody led
    PORTD = ~_BV(PD4);	
    _delay_ms(1000);
    
    // odliczanie ilosci mrugniec
    count--;
  }
}
