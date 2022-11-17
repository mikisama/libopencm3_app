#include <libopencm3/stm32/rcc.h>

int main(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);

    for (;;)
    {
        asm("nop");
    }
}
