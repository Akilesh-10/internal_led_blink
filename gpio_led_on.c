#include <stdint.h>
#include "RCC_Driver.h"
#include "GPIO_Driver.h"

int main(void){

    /* Enable GPIOD clock */
    RCC->AHB1ENR |= (1 << 3);

    /* Set PD12 as output */
    GPIOD->MODER &= ~(0x3 << (2 * 12));
    GPIOD->MODER |=  (0x1 << (2 * 12));

    while(1)
    {
        GPIOD->ODR |= (1 << 12); // LED ON
    }
}