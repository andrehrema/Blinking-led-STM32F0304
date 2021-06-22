#include "stm32f030x6.h"

#define BIT0 0x01
#define BIT1 0x10

int main(void)
{
    int val = 0;

    RCC->CR |= 0x1;
    //enabling clock in port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    //setting GPIOA0 in output mode
    GPIOA->MODER |= BIT0;
    // push-pull output
    GPIOA->OTYPER &= ~(BIT0);
    GPIOA->OSPEEDR &= ~BIT0;
    GPIOA->PUPDR |= BIT0;

    //setting GPIOA0 in output mode
    GPIOA->MODER |= 0x10;
    // push-pull output
    GPIOA->OTYPER &= ~(0x4);
    GPIOA->OSPEEDR |= 0x10;

    //enabling pull-down
    //GPIOA->PUPDR &= ~(BIT0+BIT1);
    //GPIOA->PUPDR |= BIT1;

    //GPIOA->BSRR |= BIT0;

    while(1)
    {
        if(val == 1000000)
        {
            GPIOA->ODR ^= BIT0;
            GPIOA->ODR |= 0x4;
            val=0;
        }
        
        val++;
    }

}