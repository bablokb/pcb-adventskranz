# --------------------------------------------------------------------------
# Firmware für Adventskranz-Schaltung
#
# Author: Bernhard Bablok
#
# https://github.com/bablokb/pcb-adventskranz
# 
# --------------------------------------------------------------------------

PROJECT=adventskranz
ARCH=pic14
MODEL=12f675
EXTRA_ASM=delay.asm

PIN_LED_D1 = 0
PIN_LED_D2 = 4
PIN_LED_D3 = 1
PIN_LED_D4 = 5
PIN_BTN    = 2

SDCC_ARGS=-DPIN_LED_D1=$(PIN_LED_D1) \
          -DPIN_LED_D2=$(PIN_LED_D2) \
          -DPIN_LED_D3=$(PIN_LED_D3) \
          -DPIN_LED_D4=$(PIN_LED_D4) \
          -DPIN_BTN=$(PIN_BTN)

include ptc_rules.inc

# --------------------------------------------------------------------------
