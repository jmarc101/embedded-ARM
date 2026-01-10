# embedded-arm

Bare-metal ARM development. Using STM32 microcontrollers with PlatformIO for ease of development.

Reference course - the [Quantum Leaps](https://www.state-machine.com/quickstart/) course.

## Hardware

**Board:** STM32 Nucleo-F446RE
**MCU:** STM32F446RET6

| Spec | Value |
|------|-------|
| Core | ARM Cortex-M4 + FPU + DSP |
| Clock | 180 MHz (max) |
| Flash | 512 KB |
| SRAM | 128 KB + 4 KB backup |
| Voltage | 1.7V - 3.6V |

### Peripherals

| Type | Count |
|------|-------|
| Timers | 17 |
| ADC | 3x 12-bit |
| DAC | 2x 12-bit |
| GPIO | 50 pins |
| USART/UART | 6 |
| SPI / I2C | 4 / 3 |
| USB | OTG FS + HS |
| CAN | 2 |
| DMA | 16 streams |

### Board Features

| Feature | Details |
|---------|---------|
| Debugger | ST-LINK/V2-1 (on-board) |
| User LED | LD2 on **PA5** |
| User Button | B1 on **PC13** (active low) |
| Headers | Arduino + ST Morpho |
| Power | USB or 7-12V external |

### Memory Map

| Region | Address | Size |
|--------|---------|------|
| Flash | 0x0800_0000 | 512 KB |
| SRAM | 0x2000_0000 | 128 KB |
| Peripherals | 0x4000_0000 | — |
| Cortex-M4 | 0xE000_0000 | — |

## Docs

- [Datasheet](https://www.st.com/resource/en/datasheet/stm32f446re.pdf) — pinout, electrical specs
- [Reference Manual (RM0390)](https://www.st.com/resource/en/reference_manual/rm0390-stm32f446xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) — the bible for registers
- [Cortex-M4 Programming Manual (PM0214)](https://www.st.com/resource/en/programming_manual/pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf) — NVIC, SysTick, instructions
- [Nucleo-64 User Manual (UM1724)](https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf) — board schematic, jumpers

## Structure

```
embedded-arm/
├── projects/
│   ├── 00-test/
│   │   ├── src/
│   │   │   └── main.c
│   │   └── platformio.ini
│   ├── 01-blinky/
│   └── ...
├── common/
└── docs/
```

Each project is a standalone PlatformIO project.

## Setup

```bash
# Install PlatformIO
curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
echo 'export PATH="$HOME/.platformio/penv/bin:$PATH"' >> ~/.bashrc && source ~/.bashrc

# Build & upload
git clone https://github.com/jmarc101/embedded-ARM.git
pio run -t upload

## Usage

**Build & upload:**
```bash
cd projects/01-blinky
pio run -t upload
```

**Serial monitor:**
```bash
pio device monitor
```

**Create new project:**
```bash
cd projects
mkdir 03-new-project && cd 03-new-project
pio project init --board nucleo_f446re --project-option "framework=cmsis"
```

## Projects

| # | Name | Description |
|---|------|-------------|
| 00 | test | Minimal startup code |
