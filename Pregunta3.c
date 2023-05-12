#include <stdio.h>
#include <stdint.h>

int main(void) 
{
    // Creando los punteros hacia los registros RCC_AHB1ENR, RCC_APB1ENR y RCC_APB2ENR
     uint32_t *RCC_AHB1ENR_PUNTERO = (uint32_t *) (0x40023830);
     uint32_t *RCC_APB1ENR_PUNTERO = (uint32_t *) (0x40023840);
     uint32_t *RCC_APB2ENR_PUNTERO = (uint32_t *) (0x40023844);

    // Colocando los siguientes bits en alta GPIOG_EN y GPIOF_EN de RCC_AHB1ENR
    *RCC_AHB1ENR_PUNTERO |= ((1 << 6) | (1 << 5));

    // Colocando los siguientes bits en alta UART5_EN y UART4_EN de RCC_APB1ENR
    *RCC_APB1ENR_PUNTERO |= ((1 << 20) | (1 << 19));

    // Colocando los siguientes bits en alta ADC1_EN y TIM10_EN de RCC_APB2ENR
    *RCC_APB2ENR_PUNTERO |= ((1 << 8) | (1 << 17));

    // Colocando los siguientes bits en baja GPIOA_EN y GPIOB_EN de RCC_AHB1ENR
    *RCC_AHB1ENR_PUNTERO &= ~((1 << 0) | (1 << 1));

    // Colocando los siguientes bits en baja TIM6_EN, TIM5_EN y TIM3_EN de RCC_APB1ENR
    *RCC_APB1ENR_PUNTERO &= ~((1 << 4) | (1 << 3) | (1 << 1));

    // Colocando los siguientes bits en baja TIM11_EN y TIM10_EN de RCC_APB2ENR
    *RCC_APB2ENR_PUNTERO &= ~((1 << 18) | (1 << 17));

    

    return 0;
}