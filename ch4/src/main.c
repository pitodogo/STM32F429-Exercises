#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_adc.h"
extern void demo(void);

int main()
{
	demo();
    while(1)
    {}
}

