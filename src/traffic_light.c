#include "traffic_light.h"

void pause(long int amount) {                                                                         
  volatile long pause = 0;                                                   
  for (pause = 0; pause < amount; pause++){                                                                          
    if (PIN_B & NS_BUTTON && !(PORT_D & NS_GREEN) && amount == LONG_PAUSE){                                                                      
      NS_BUTTON_LED_ON;                                                  
      volatile long amount2 = SHORT_PAUSE;                               
      volatile long pause2 = 0;                                          
      for (pause2 = 0; pause2 < amount2; pause2++)                       
      {                                                                  
          pause2 = pause2;                                               
      }                                                                  
      break;                                                             
    } else if (PORT_D & NS_GREEN){                                                                      
      NS_BUTTON_LED_OFF;                                                 
    }                                                                      
    if (PIN_B & EW_BUTTON && !(PORT_D & EW_GREEN) && amount == LONG_PAUSE){                                                                      
      EW_BUTTON_LED_ON;                                                  
      volatile long amount2 = SHORT_PAUSE;                               
      volatile long pause2 = 0;                                          
      for (pause2 = 0; pause2 < amount2; pause2++)                       
      {                                                                  
          pause2 = pause2;                                               
      }                                                                  
      break;                                                             
    } else if (PORT_D & EW_GREEN){                                                                      
      EW_BUTTON_LED_OFF;                                                 
    }                                                                      
    pause = pause;                                                         
  }                                                                          
}

void change_to_red(int dir) {
  if(dir == EW_DIR){
    EW_GREEN_OFF;          
    EW_YELLOW_ON;          
    pause(SHORT_PAUSE);    
    EW_YELLOW_OFF;         
    EW_RED_ON;
  } else {
    NS_GREEN_OFF;          
    NS_YELLOW_ON;          
    pause(SHORT_PAUSE);    
    NS_YELLOW_OFF;         
    NS_RED_ON;
  }
}

void change_to_green(int dir) {
  if(dir == EW_DIR){
    EW_YELLOW_ON;            
    pause(SHORT_PAUSE);      
    EW_RED_OFF;              
    EW_YELLOW_OFF;           
    EW_GREEN_ON;
  } else {
    NS_YELLOW_ON;            
    pause(SHORT_PAUSE);      
    NS_RED_OFF;              
    NS_YELLOW_OFF;           
    NS_GREEN_ON;
  }
}

int main(){
  SETUP();
  while (1) {
    pause(LONG_PAUSE);
    
    change_to_red(EW_DIR);
    
    pause(SHORT_PAUSE);
    
    change_to_green(NS_DIR);

    pause(LONG_PAUSE);

    change_to_red(NS_DIR);
    
    pause(SHORT_PAUSE);
    
    change_to_green(EW_DIR);
  }
  return 0;
}