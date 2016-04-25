#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

void RCC_Configuration_Demo1()
{
	// RCC Configuration
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
}

void GPIO_Configuration_Demo1()
{
	// GPIO Configuration
	// LED3 (Green): GPIO_Pin_13, LED4 (Red): GPIO_Pin_14
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void demo()
{
  char In;
  // A AND G 
  RCC->AHB1ENR |= 0x40 + 0x01;
  GPIOG->MODER |= 0x4000000;

  while(1){
    In = GPIOA->IDR & 0x01;
    if (In & 0x01)
      GPIOG->ODR |= 0x2000;
    else
      GPIOG->ODR &= ~0x2000;     
  }

}
