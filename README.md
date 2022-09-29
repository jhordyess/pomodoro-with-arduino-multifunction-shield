# Pomodoro timer with Arduino Multifunction Shield

Simple Pomodoro timer with Arduino Multifunction Shield.

## Features

Two main modes:

- Manual -> It starts a Pomodoro or a break with the button.
- Auto-loop -> It starts a Pomodoro or a break automatically (to reset it is necessary to pause).

Default minutes:

- A Pomodoro has 25 minutes.
- A short break has 5 minutes.
- A long break has 15 minutes.

## Buttons description

### On waiting or stop

Button| Pressed | Action
-|-|-
 1st | Short or long | Play
 2nd | Short or long | Play with auto-loop
 3rd | Short or long | Reset

### On play

Button| Pressed | Action
-|-|-
 1st | Short or long | Pause
 2nd | Short or long | Nothing
 3rd | Short or long | Nothing

### On pause

Button| Pressed | Action
-|-|--
 1st | Short | Continue
 1st | Long | Reset minutes
 2nd | Short | Add 2 minutes
 2nd | Long | Subtract 2 minutes
 3rd | Short or long | Reset

## Dev Info

- Arduino Uno R3
- Arduino Multifunction Shield (for Arduino Uno R3)
- [Multi Function Shield Library](https://registry.platformio.org/libraries/hpsaturn/MultiFuncShield)
- VSCode with [remote containers](https://code.visualstudio.com/docs/remote/containers) (Docker container with Ubuntu)
- [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/index.html#platformio-core-cli)

## My useful PlatformIO commands

```bash
# Initialize project for Arduino Uno R3
pio project init --board uno --ide vscode
# Build
pio run
# Upload
pio run -t upload
# Connect to the serial port monitor
pio device monitor
# Enable serial port permissions
sudo chmod o+rw /dev/ttyACM0
```

## TODO

- Choose the number of Pomodoros to make.
- Disable auto-loop on pause.
- Change the default minutes before playing.

## License

© 2022 [Jhordyess](https://github.com/jhordyess). Under the [MIT](https://choosealicense.com/licenses/mit/) license.

---

Made with 💪 by [Jhordyess](https://www.jhordyess.com/)
