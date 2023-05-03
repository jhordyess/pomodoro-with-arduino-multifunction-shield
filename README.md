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
 
## Requirements

### Hardware

To build this device, the following items are required:

- Arduino microcontroller (Arduino UNO R3 was used)
- Arduino Multifunction Shield (for Arduino Uno R3)

### Software

This project requires the following libraries to run:

- [Multi Function Shield Library by Hpsaturn](https://registry.platformio.org/libraries/hpsaturn/MultiFuncShield)

### Developer Notes

- Developed using [Visual Studio Code with development containers](https://code.visualstudio.com/docs/devcontainers/containers)(optional). With custom [devcontainer](https://gist.github.com/jhordyess/07f126d2017bb99bcfca9cffc62162bc) configuration file.
- Developed using the [PlatformIO extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide).
- If you are running in Linux, you could also need the correct permission ```sudo chmod o+rw /dev/ttyACM0```.

## To-Do

- Choose the number of Pomodoros to make.
- Disable auto-loop on pause.
- Change the default minutes before playing.

## License

© 2022 [Jhordyess](https://github.com/jhordyess). Under the [MIT](https://choosealicense.com/licenses/mit/) license.

---

Made with 💪 by [Jhordyess](https://www.jhordyess.com/)
