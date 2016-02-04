/*
 Cinthya Tang
 ECE 372
 Lab0 Part 2
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

typedef enum stateTypeEnum{ state1, state2, state3 } stateType;

volatile stateType state = state1;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    initLEDs();
    initTimer1();
    
    
    while(1){
        switch (state) {
        case state1:
            turnOnLED(1);
            break;	
        case state2:
            turnOnLED(2);	
            break;
        case state3:
            turnOnLED(3);
            break;
        default:
            break;
        }
    }
    
    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
__ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    IFS0bits.T1IF = 0;
	if (state == state1) state = state2;
    else if (state == state2) state = state3;
    else if (state == state3) state = state1;
}
