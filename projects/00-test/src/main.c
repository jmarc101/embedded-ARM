/**
 * Bare-metal STM32F446RE - Minimal Startup
 *
 * On a PC, the OS handles program startup, memory initialization, and cleanup.
 * On bare metal, YOU are the OS. The CPU needs three things to boot:
 *   1. A stack pointer (where to put local variables)
 *   2. An entry point (where to start executing)
 *   3. Stubs for C library functions that expect an OS
 */

/*===========================================================================
 * MAIN PROGRAM
 *===========================================================================*/

/**
 * main() - Your application entry point
 *
 * The infinite loop is critical: on bare metal, there's nowhere to "return" to.
 * If main() ever exits, the CPU would jump to garbage memory and crash.
 */
int main(void) {
    while (1) {
        // Your code here
    }
    return 0;  // Never reached, but keeps compiler happy
}

/*===========================================================================
 * STARTUP CODE
 *===========================================================================*/

/**
 * Reset_Handler() - First code executed after power-on or reset
 *
 * When you power on the board or hit the reset button, the CPU:
 *   1. Loads the stack pointer from vectors[0]
 *   2. Jumps to the address in vectors[1] (this function)
 *
 * In a full startup, this would:
 *   - Copy initialized data from flash to RAM (.data section)
 *   - Zero out uninitialized globals (.bss section)
 *   - Call SystemInit() for clock setup
 *   - Call main()
 *
 * For now, we just call main() directly.
 */
void Reset_Handler(void) {
    main();
}

/**
 * Default_Handler() - Catches unexpected interrupts
 *
 * If an interrupt fires that we haven't explicitly handled, the CPU jumps here.
 * The infinite loop prevents undefined behavior. In debug, you'd set a
 * breakpoint here to catch runaway interrupts.
 */
void Default_Handler(void) {
    while (1);
}

/*===========================================================================
 * VECTOR TABLE
 *===========================================================================*/

/**
 * Vector Table - The CPU's "phone book" for startup and interrupts
 *
 * On Cortex-M, the first 4 bytes of flash (address 0x08000000) MUST contain
 * the initial stack pointer. The next 4 bytes MUST contain the Reset_Handler
 * address. This is hardwired in the CPU — not optional.
 *
 * Memory layout at boot:
 *   0x08000000: Initial stack pointer value
 *   0x08000004: Reset_Handler address    <-- CPU jumps here on boot
 *   0x08000008: NMI_Handler address
 *   0x0800000C: HardFault_Handler address
 *   ... (more interrupt vectors)
 *
 * __attribute__((section(".isr_vector"))) tells the linker:
 *   "Put this array at the very start of flash memory"
 *
 * The linker script (provided by PlatformIO) maps .isr_vector to 0x08000000.
 */
__attribute__((section(".isr_vector")))
void (*const vectors[])(void) = {
    0,              // [0] Stack pointer - 0 is wrong, but linker provides default
    Reset_Handler,  // [1] Reset - entry point after power-on/reset
    // [2+] Other handlers omitted - would go here for interrupts
};

/*===========================================================================
 * C LIBRARY STUBS
 *===========================================================================*/

/**
 * _exit() - Called when a program "exits"
 *
 * Standard C library assumes an OS exists to return to. Functions like
 * abort() and exit() eventually call _exit(). On bare metal, there's no OS,
 * so we provide a stub that just hangs forever.
 *
 * Even if YOUR code never calls exit(), the library includes it, and the
 * linker demands a definition. This is the "tax" for using standard libc.
 *
 * (void)status suppresses "unused parameter" warning.
 */
void _exit(int status) {
    (void)status;
    while (1);
}
