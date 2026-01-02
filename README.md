# embedded-arm

Bare-metal ARM development following embedded systems fundamentals.

**Board:** STM32 Nucleo F446RE

## Setup

### 1. Install PlatformIO CLI

https://docs.platformio.org/en/stable/core/installation/methods/installer-script.html

```bash
# Install
curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py

# Add to PATH
echo 'export PATH="$HOME/.platformio/penv/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

### 2. Clone and build

```bash
git clone git@github.com:jmarc101/embedded-ARM.git
cd embedded-ARM
pio run
```

### 3. Upload

```bash
pio run -t upload
```

### 4. Monitor serial (optional)

```bash
pio device monitor
```

## Linux permissions (if upload fails)

```bash
sudo usermod -a -G dialout $USER
# Log out and back in
```
