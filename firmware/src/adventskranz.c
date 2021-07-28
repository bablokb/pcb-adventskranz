// --------------------------------------------------------------------------
// Firmware für Adventskranzschaltung
//
// Author: Bernhard Bablok
//
// https://github.com/bablokb/pcb-adventskranz
//
// --------------------------------------------------------------------------

#include <stdint.h>
#include "picconfig.h"
#include "delay.h"

CONFIG_WORDS;

////////////////////////////////////////////////////////////////////////
// Intialize registers

static void init(void) {
  // configure registers
  __asm__ ("CLRWDT");                  // clear WDT even if WDT is disabled
  ANSELA  = 0;                         // no analog input
  CM1CON0 = 0x07;                      // disable comparator for GP0-GP2

  TRISA = 0;
  bitset(TRISA,PIN_BTN);               // all GPIOs are output except: button
  bitset(WPUA,PIN_BTN);                // pullup for button
  NOT_GPPU  = 0;                       // enable pullups
  PORTA     = 0;                       // turn off LEDs

  INTCON = 0;                          // clear interrupt flag bits
  INTEDG = 0;                          // ext. interrupt on falling edge
  INTE   = 1;                          // enable external interrupt
  GIE    = 0;                          // global interrupt enable
}

////////////////////////////////////////////////////////////////////////
// Interrupt service routine

static void isr(void) __interrupt 0 {
  if (INTE && INTF) {
    GIE  = 0;                // disable interrupts
    INTF = 0;                // clear GP2/INT interrupt flag
  }
}

////////////////////////////////////////////////////////////////////////
// main program 
//   - calibrate internal clock
//   - initialize registers
//   - go to sleep

uint8_t leds[] = {PIN_LED_D1, PIN_LED_D2, PIN_LED_D3, PIN_LED_D4};
uint8_t counter = 0;

void main(void) {
  INIT_SPECIAL;
  init();
  while (1) {
    delay_ms(250);
    GIE = 1;
    __asm__("SLEEP");
    counter   = (counter+1) % 5;
    PORTA = 0;
    for (int i=0; i<counter;++i) {
      bitset(PORTA,leds[i]);
    }
  }
}
