# cubetto-platformio

PlatformIO firmware for the Cubetto robot (ATSAMD21 board revision) — because Arduino IDE and a zip file shouldn't be the only option.

## Hardware Compatibility

This firmware targets Cubetto robot boards running the **ATSAMD21G18A** microcontroller with an **nRF8001D** BLE co-processor. Check your robot PCB — if it says `ATSAMD21` under the microscope you're in the right place.

This does **not** target older Leonardo-era boards or the FR8016HA Chinese BLE SoC revision.

## Requirements

- VS Code + PlatformIO extension
- USB data cable (not charge-only — ask me how I know)

## Usage
```bash
git clone https://github.com/bay41/cubetto-platformio
cd cubetto-platformio
```

Open in VS Code with the PlatformIO extension installed. PlatformIO auto-detects the project. Connect the Cubetto robot PCB via USB and flash.

## Calibration

Turn and forward steps are tunable in `lib/CubettoLibrary/CubettoLibrary.h`:
```cpp
#define STEPPER_TURN_STEPS_LEFT    1085
#define STEPPER_TURN_STEPS_RIGHT   1085
#define STEPPER_FORWARD_STEPS      2551
```

Your unit may vary. 1085 was the sweet spot for this unit. Adjust until turns are 90°.

## Contributing

PRs welcome.