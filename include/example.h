#ifndef EXAMPLE_H
#define EXAMPLE_H

#define MY_PORT *(unsigned char*)0x2B
#define MY_PORT_DDR *(unsigned char*)0x2A
#define LONG_PAUSE 1000000
#define SHORT_PAUSE 200000
#define GREEN_1 (1 << 2)
#define GREEN_2 (1 << 5)
#define YELLOW_1 (1 << 3)
#define YELLOW_2 (1 << 6)
#define RED_1 (1 << 4)
#define RED_2 (1 << 7)
#define GREEN_1_ON MY_PORT = MY_PORT | GREEN_1
#define GREEN_2_ON MY_PORT = MY_PORT | GREEN_2
#define YELLOW_1_ON MY_PORT = MY_PORT | YELLOW_1
#define YELLOW_2_ON MY_PORT = MY_PORT | YELLOW_2
#define RED_1_ON MY_PORT = MY_PORT | RED_1
#define RED_2_ON MY_PORT = MY_PORT | RED_2
#define GREEN_1_OFF MY_PORT = MY_PORT & ~GREEN_1
#define GREEN_2_OFF MY_PORT = MY_PORT & ~GREEN_2
#define YELLOW_1_OFF MY_PORT = MY_PORT & ~YELLOW_1
#define YELLOW_2_OFF MY_PORT = MY_PORT & ~YELLOW_2
#define RED_1_OFF MY_PORT = MY_PORT & ~RED_1
#define RED_2_OFF MY_PORT = MY_PORT & ~RED_2
#define SETUP() (MY_PORT_DDR |= GREEN_1 | GREEN_2 | YELLOW_1 | YELLOW_2 | RED_1 | RED_2)
#define PAUSE(amount) \
    do { \
        volatile long pause = 0; \
        for (pause = 0; pause < amount; pause++) { \
            pause = pause; \
        } \
    } while (0)

#endif