//John Emile

#include "../headers/RGB.h"

void RGB_init(void){
    SYSCTL_RCGCGPIO_R |= 0x20;
    while ((SYSCTL_PRGPIO_R & 0x20) ==0)
    {
    }
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R |= 0x0E;
    GPIO_PORTF_AMSEL_R &= ~(0x0E);
    GPIO_PORTF_DEN_R |= 0x0E;
    GPIO_PORTF_AFSEL_R &= ~(0x0E);
    GPIO_PORTF_PCTL_R &= 0xFFFF000F;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DATA_R &= ~(0x0E);
}

void setLed(char data){
    GPIO_PORTF_DATA_R&=~0x0E;
    GPIO_PORTF_DATA_R|=data;

}
