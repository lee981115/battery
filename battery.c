#include<mega8.h>
#include <delay.h>
void main(void)
{
    initcpu();
    while(1){

    }
}
/***********************
    initial Cpu
***********************/
void initcpu(){
    /***********************
        IO PORT initial
    ***********************/
    DDRD=0x03;
    DDRB=0x06;
    DDRC=0x00;
    PORTD=0x00;
    PORTB=0x00;
    PORTC=0x00;
    /***********************
        Timer initial
        4.8kHz PWM OCR 1,2
    ***********************/
    TCCR1A=0x00;
    TCCR1B=0x0B;
    TIMSK=0x18;
    OCR1A=0;
    OCR1B=0;
    /***********************
        ADC initial
        
    ***********************/
    ADMUX=0x00;
    ADCSR=0x87;

}
void setPwmboostConverter(unsigned char val){
    if(val == 0){
        TCCR1A&=0xCF;
        OCR1A=0;
    }
    else OCR1A=val;
}
void setpwmBuckConverter(unsigned char val){
    if(val == 0){
        TCCR1A&=0x3F;
        OCR1B=0;
    }
    else OCR1B=val;
}
unsigned short getAdcValueBattery(){
    AMDUX=0x00;

    return(ADCW);
}
unsigned short getAdcValueOutput(){
    ADMUx=0x01;

    return(ADCW);
}