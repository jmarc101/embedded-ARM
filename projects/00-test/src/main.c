/**
 * STM32F446RE LED Blink - CMSIS Framework
 *
 * CMSIS provides:
 *  - stm32f4xx.h: Hardware register definitions
 *  - Startup code: Sets up stack, initializes .data/.bss, calls main()
 *  - Linker script: Memory layout for flash/RAM
 *
 * You just need to write main() and configure peripherals!
 */

#include "stm32f4xx.h"

/**
 * Simple delay loop - burns CPU cycles
 * At 16MHz default clock, this gives roughly 500ms
 */
void delay(volatile uint32_t count) {
    while (count--);
}

/**
 * main() - Application entry point
 */
int main(void) {
    int counter = 0;

    // 1. Enable GPIOA clock
    //    RCC = Reset and Clock Control
    //    AHB1ENR = AHB1 peripheral clock enable register
    //    GPIOAEN = bit 0, enables GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    
    // 2. Configure PA5 as output
    //    MODER = Mode register (2 bits per pin)
    //    MODER5[1:0] = 01 means "General purpose output mode"
    //    
    //    Bit manipulation breakdown:
    //    GPIO_MODER_MODER5 is bits [11:10] = 0b11 (mask for both bits)
    //    We clear both bits first, then set bit 10 only
    GPIOA->MODER &= ~GPIO_MODER_MODER5;      // Clear bits [11:10]
    GPIOA->MODER |= GPIO_MODER_MODER5_0;     // Set bit 10 (01 = output)
    
    // 3. Blink LED forever w
    while (1) {
        int second_in_ms = 1000000;
        counter++;

        for (int i = 0; i<=counter; i++){
            // Calculate delay time
            // Decrease delay time with each iteration but more toggles
            int loop_delay = second_in_ms - counter * 100000;

            // ODR = Output Data Register
            // OD5 = Output data bit 5 (corresponds to PA5)
            GPIOA->ODR ^= GPIO_ODR_OD5;      // Toggle PA5
            delay(loop_delay);               // Delay

        }

        if (counter == 9){
            counter = 0;
        }
    }
}