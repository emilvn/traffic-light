#include "example.h"

int main(){
  SETUP();
  while (1) {
    RED_1_ON;
    GREEN_2_ON;
    PAUSE(LONG_PAUSE);
    GREEN_2_OFF;
    YELLOW_2_ON;
    PAUSE(SHORT_PAUSE);
    YELLOW_2_OFF;
    RED_2_ON;
    PAUSE(SHORT_PAUSE);
    YELLOW_1_ON;
    PAUSE(SHORT_PAUSE);
    RED_1_OFF;
    YELLOW_1_OFF;
    GREEN_1_ON;
    PAUSE(SHORT_PAUSE);
    
    RED_2_ON;
    GREEN_1_ON;
    PAUSE(LONG_PAUSE);
    GREEN_1_OFF;
    YELLOW_1_ON;
    PAUSE(SHORT_PAUSE);
    YELLOW_1_OFF;
    RED_1_ON;
    PAUSE(SHORT_PAUSE);
    YELLOW_2_ON;
    PAUSE(SHORT_PAUSE);
    RED_2_OFF;
    YELLOW_2_OFF;
    GREEN_2_ON;
    PAUSE(SHORT_PAUSE);
  }
  return 0;
}