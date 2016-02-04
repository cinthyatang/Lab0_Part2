/* 
 * File:   timer.c
 * Author: Cinthya Tang
 *
 * Created on February 2, 2016, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;// clear TMR1
    PR1 = 39062;// Initialize PR1
    T1CONbits.TCKPS = 3; // Initialize pre-scalar
    T1CONbits.TCS = 0; // Setting the oscillator
    IEC0bits.T1IE = 1;// Enable the interrupt
    IFS0bits.T1IF = 0;// Put the flag down
    IPC1bits.T1IP = 7;// Configure the Interrupt Priority
    T1CONbits.TON = 1;// Turn the timer on
}