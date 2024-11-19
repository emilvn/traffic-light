#ifndef EXAMPLE_H
#define EXAMPLE_H

#define bit(pos) (1 << pos)
#define EW_DIR 1
#define NS_DIR 0
#define PORT_D *(unsigned char*)0x2B
#define PORT_D_DDR *(unsigned char*)0x2A
#define PORT_B *(unsigned char*)0x25
#define PIN_B *(unsigned char*)0x23
#define PORT_B_DDR *(unsigned char*)0x24
#define PORT_C *(unsigned char*)0x28
#define PORT_C_DDR *(unsigned char*)0x27
#define LONG_PAUSE 50000000
#define SHORT_PAUSE 500000
#define NS_GREEN (bit(2))
#define EW_GREEN (bit(5))
#define NS_YELLOW (bit(3))
#define EW_YELLOW (bit(6))
#define NS_RED (bit(4))
#define EW_RED (bit(7))
#define NS_BUTTON (bit(2))
#define EW_BUTTON (bit(3))
#define NS_BUTTON_LED (bit(1))
#define EW_BUTTON_LED (bit(0))
#define NS_GREEN_ON PORT_D = PORT_D | NS_GREEN
#define EW_GREEN_ON PORT_D = PORT_D | EW_GREEN
#define NS_YELLOW_ON PORT_D = PORT_D | NS_YELLOW
#define EW_YELLOW_ON PORT_D = PORT_D | EW_YELLOW
#define NS_RED_ON PORT_D = PORT_D | NS_RED
#define EW_RED_ON PORT_D = PORT_D | EW_RED
#define NS_BUTTON_LED_ON PORT_B = PORT_B | NS_BUTTON_LED
#define EW_BUTTON_LED_ON PORT_B = PORT_B | EW_BUTTON_LED
#define NS_BUTTON_LED_OFF PORT_B = PORT_B & ~NS_BUTTON_LED
#define EW_BUTTON_LED_OFF PORT_B = PORT_B & ~EW_BUTTON_LED
#define NS_GREEN_OFF PORT_D = PORT_D & ~NS_GREEN
#define EW_GREEN_OFF PORT_D = PORT_D & ~EW_GREEN
#define NS_YELLOW_OFF PORT_D = PORT_D & ~NS_YELLOW
#define EW_YELLOW_OFF PORT_D = PORT_D & ~EW_YELLOW
#define NS_RED_OFF PORT_D = PORT_D & ~NS_RED
#define EW_RED_OFF PORT_D = PORT_D & ~EW_RED
#define SETUP()                                                                  \
    PORT_D_DDR |= NS_GREEN | EW_GREEN | NS_YELLOW | EW_YELLOW | NS_RED | EW_RED; \
    PORT_B_DDR |= NS_BUTTON_LED | EW_BUTTON_LED;                                 \
    PORT_B_DDR &= ~(NS_BUTTON | EW_BUTTON);                                      \
    NS_RED_ON;                                                                   \
    EW_GREEN_ON;
#endif