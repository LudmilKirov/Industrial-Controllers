/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#define TPER 3300
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
//TRISBbits.TRISB13=0;//napravo portb pin13 izhod
INITPWM();
INITADC();
}

void INITADC(){
   
    AD1CON1bits.AD12B=1;
    AD1CON1bits.SSRC=3;
    AD1CON1bits.ASAM=1;
    
 
    AD1CON2bits.SMPI=0xF;
    AD1CON3bits.ADCS=6;
    IEC0bits.AD1IE=1;
     AD1CON1bits.ADON=1;
    
}
void INITPWM(){
    P1TCONbits.PTCKPS=3; //divide by 64 
    P1TPERbits.PTPER=TPER;//zadavash chestota
    //P1DC1=1999;
    //P1DC2=1999;
    //P1DC3=1999;
    
    P1DTCON1bits.DTBPS=0;//da rabotish s tcy
    P1DTCON1bits.DTB=19;//da stane 500ns
    P1DTCON1bits.DTAPS=0;
    P1DTCON1bits.DTA=23;//da rabotish s 600ns
     P1DTCON2bits.DTS2A=0;
    P1DTCON2bits.DTS2I=0;
    P1DTCON2bits.DTS1A=1;
    P1DTCON2bits.DTS1I=1;
    PWM1CON1bits.PEN2H=1;
    P1TPER=TPER;
    P1TMR=0x000;
    P1TCONbits.PTMOD=3;
    IEC3bits.PWM1IE=1;
    P1TCONbits.PTEN=1;
}
