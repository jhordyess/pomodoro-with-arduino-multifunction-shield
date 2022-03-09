#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

enum class TimerState {
  PLAY,
  PAUSE,
  STOP,
};

enum class PomodoroTimerState {
  POMODORO,
  BREAK,
};

const char pomodoroMins = 25;
const char breakMins = 5;
const char longBreakMins = 15;

TimerState Tstate;
PomodoroTimerState PTstate;

bool autoLoop;
char nPomodoros;

byte deciSeconds;
char seconds;
char minutes;

void reset() {
  Tstate = TimerState::STOP;
  PTstate = PomodoroTimerState::BREAK;
  autoLoop = false;
  nPomodoros, deciSeconds, minutes, seconds = 0;
}

void setMin(char newVal) {
  if (minutes != newVal)
    minutes = newVal;
}

void flipPomodoroState() {
  switch (PTstate) {
  case PomodoroTimerState::BREAK:
    PTstate = PomodoroTimerState::POMODORO;
    break;
  case PomodoroTimerState::POMODORO:
    PTstate = PomodoroTimerState::BREAK;
    break;
  }
}

void printTime() {
  MFS.write(minutes * 100 + seconds);
}

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
  reset();
  printTime();
}

void loop() {

  byte btn = MFS.getButton();

  switch (Tstate) {
  case TimerState::STOP:
    switch (PTstate) {
    case PomodoroTimerState::BREAK:
      setMin(pomodoroMins);
      break;

    case PomodoroTimerState::POMODORO:
      if (nPomodoros % 4 == 0)
        setMin(longBreakMins);
      else
        setMin(breakMins);
      break;
    }

    printTime();

    if (autoLoop) {
      Tstate = TimerState::PLAY;
      flipPomodoroState();
    } else {
      if ((btn == BUTTON_1_SHORT_RELEASE || btn == BUTTON_1_LONG_PRESSED) && (minutes + seconds) > 0) {
        // Start
        Tstate = TimerState::PLAY;
        flipPomodoroState();
      } else if (btn == BUTTON_2_PRESSED || btn == BUTTON_2_LONG_PRESSED) {
        // Start auto-loop
        autoLoop = true;
        Tstate = TimerState::PLAY;
        flipPomodoroState();
      } else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED) {
        // Reset
        reset();
        printTime();
      }
    }
    break;

  case TimerState::PAUSE:
    if (btn == BUTTON_1_SHORT_RELEASE && (minutes + seconds) > 0) {
      // Start
      Tstate = TimerState::PLAY;
    } else if (btn == BUTTON_1_LONG_PRESSED) {
      // Reset minutes
      switch (PTstate) {
      case PomodoroTimerState::POMODORO:
        minutes = pomodoroMins;
        break;

      case PomodoroTimerState::BREAK:
        if (nPomodoros % 4 == 0)
          minutes = longBreakMins;
        else
          minutes = breakMins;
        break;
      }
      deciSeconds, seconds = 0;
    } else if (btn == BUTTON_2_PRESSED) {
      // Add 5 minutes
      minutes++;
      if (minutes >= 60)
        minutes = 0;
    } else if (btn == BUTTON_2_LONG_PRESSED) {
      // Subtract 5 minutes
      minutes--;
      if (minutes <= 0)
        minutes = 60;
    } else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED) {
      // Reset
      reset();
    }
    printTime();
    break;

  case TimerState::PLAY:
    if (btn == BUTTON_1_SHORT_RELEASE || btn == BUTTON_1_LONG_RELEASE) {
      // Pause
      Tstate = TimerState::PAUSE;
    } else {
      deciSeconds++;

      if (deciSeconds == 10) {
        deciSeconds = 0;
        seconds--;

        if (seconds < 0 && minutes > 0) {
          seconds = 59;
          minutes--;
        }

        if (minutes == 0 && seconds == 0) {
          // Alarm
          MFS.beep(50, 50, 3);
          Tstate = TimerState::STOP;

          if (PTstate == PomodoroTimerState::POMODORO)
            nPomodoros++;
        }

        printTime();
      }

      delay(100);
    }
    break;
  }
}
