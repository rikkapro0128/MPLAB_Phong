
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
    ANSEL = ANSELH = 0;
    TRISD = 0;
    PORTD = 0xff;
    unsigned int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0;
    unsigned int l1 = 1, l2 = 1, l3 = 1, l4 = 1, l5 = 1, l6 = 1, l7 = 1, l8 = 1;
    unsigned int temp = 0;
    while(temp <= 10000) {
        if(temp == (5000*l1)) {
            RD0 = RD7 = s1; // RD0 and RD7
            l1 += 1;
            s1 = !s1;
        }
        if(temp == (556*l2)) {
            RD1 = RD5 = s2; // RD1 and RD5
            l2 += 1;
            s2 = !s2;
        }
        if(temp == (1250*l3)) {
            RD2 = s3; // RD2
            l3 += 1;
            s3 = !s3;
        }
        if(temp == (1667*l4)) {
            RD3 = s4; // RD3
            l4 += 1;
            s4 = !s4;
        }
        if(temp == (1000*l5)) {
            RD4 = s5; // RD4
            l5 += 1;
            s5 = !s5;
        }
        if(temp == (2500*l6)) {
            RD6 = s6; // RD6
            l6 += 1;
            s6 = !s6;
        }
        __delay_ms(1);
        temp += 1;
    }
    PORTD = 0;
    while(1);
}
