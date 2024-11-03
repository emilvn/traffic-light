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

void setup() {
  // set ports as output ports
  MY_PORT_DDR = MY_PORT_DDR | GREEN_1;
  MY_PORT_DDR = MY_PORT_DDR | GREEN_2;
  MY_PORT_DDR = MY_PORT_DDR | YELLOW_1;
  MY_PORT_DDR = MY_PORT_DDR | YELLOW_2;
  MY_PORT_DDR = MY_PORT_DDR | RED_1;
  MY_PORT_DDR = MY_PORT_DDR | RED_2;
}

void pause(long cycles){
  volatile long pause = 0;
  for(pause = 0; pause < cycles; pause++){
    pause = pause;
  }
}

// the loop function runs over and over again forever
void loop() {
  RED_1_ON;
  GREEN_2_ON;
  pause(LONG_PAUSE);
  GREEN_2_OFF;
  YELLOW_2_ON;
  pause(SHORT_PAUSE);
  YELLOW_2_OFF;
  RED_2_ON;
  pause(SHORT_PAUSE);
  YELLOW_1_ON;
  pause(SHORT_PAUSE);
  RED_1_OFF;
  YELLOW_1_OFF;
  GREEN_1_ON;
  pause(SHORT_PAUSE);
  
  RED_2_ON;
  GREEN_1_ON;
  pause(LONG_PAUSE);
  GREEN_1_OFF;
  YELLOW_1_ON;
  pause(SHORT_PAUSE);
  YELLOW_1_OFF;
  RED_1_ON;
  pause(SHORT_PAUSE);
  YELLOW_2_ON;
  pause(SHORT_PAUSE);
  RED_2_OFF;
  YELLOW_2_OFF;
  GREEN_2_ON;
  pause(SHORT_PAUSE);
}