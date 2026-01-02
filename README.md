# embedded-arm

Bare-metal ARM development on STM32.

## Hardware

**Board:** STM32 Nucleo-F446RE  
**MCU:** STM32F446RET6

| Spec | Value |
|------|-------|
| Core | ARM Cortex-M4 + FPU |
| Clock | 180 MHz |
| Flash | 512 KB |
| SRAM | 128 KB (+4 KB backup) |
| Timers | 17 |
| ADCs | 3x 12-bit |
| Comm | USB OTG, I2C, SPI, USART, CAN |

## Documentation

- [Datasheet (STM32F446xC/E)](https://www.st.com/resource/en/datasheet/stm32f446re.pdf)
- [Reference Manual (RM0390)](https://www.st.com/resource/en/reference_manual/rm0390-stm32f446xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) — 1300+ pages, covers all peripherals
- [Cortex-M4 Programming Manual (PM0214)](https://www.st.com/resource/en/programming_manual/pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)
- [Nucleo-64 User Manual (UM1724)](https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)

## Setup

```bash
# Install PlatformIO
curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
echo 'export PATH="$HOME/.platformio/penv/bin:$PATH"' >> ~/.bashrc && source ~/.bashrc

# Build & upload
git clone https://github.com/jmarc101/embedded-ARM.git
pio run -t upload

# Serial monitor
pio device monitor
```

**Linux permission fix:** `sudo usermod -a -G dialout $USER` (then log out/in)
