#include "stm32f4xx.h"

void SysTick_Handler(){
//    GPIO_ToggleBits(GPIOC,GPIO_Pin_13);
}

void delay(volatile uint32_t s)
{
    for(; s>0; s--);
}

extern "C" int main() {

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC, ENABLE);

//    SysTick_Config(250000);

    GPIO_InitTypeDef gpio_out = {
            .GPIO_Pin = GPIO_Pin_12,
            .GPIO_Mode = GPIO_Mode_OUT,
            .GPIO_Speed = GPIO_High_Speed,
            .GPIO_OType = GPIO_OType_PP,
            .GPIO_PuPd = GPIO_PuPd_NOPULL
    };

//    GPIO_Init(GPIOA, &gpio_out);
    GPIO_Init(GPIOB, &gpio_out);
    gpio_out.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC, &gpio_out);

    GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);

    while (1) {
        GPIO_ToggleBits(GPIOC,GPIO_Pin_13);
        delay(10000000);
    }

    return 0;
}
