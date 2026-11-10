# Giga Morse Engine

A robust, menu-driven Morse code translator and visual signal engine built for the **Arduino Giga R1 WiFi** (dual-core STM32H7). 

This project implements a structured state machine for menu navigation, dynamic parameter configuration, tokenized character-to-Morse translation, and graceful handling of unsupported input characters.


## Features

- **Interactive Serial Interface:** Clean text-based menu for selecting modes and adjusting runtime settings.
- **Visual Feedback & Confirmation:** Multi-state LED signaling including startup, mode selection confirmation flashes, and active output transmission.
- **Morse Code Translation Engine:** Translates alphanumeric text streams into standardized timing patterns (dots, dashes, inter-element, and inter-character delays).
- **Dedicated Emergency Modes:** Includes standalone SOS emergency signaling routines.
- **Fault-Tolerant Input Parsing:** Custom logic for handling, logging, and gracefully skipping unrecognized symbols without system lockups or memory corruption.


## Hardware Target

- **Microcontroller:** Arduino Giga R1 WiFi (STM32H747XI dual ARM Cortex-M7/M4)
- **Signal Output:** Onboard system LED (`LED_BUILTIN`) / RGB GPIO pins
- **Control Interface:** USB Serial (9600 baud)


## Project Roadmap

This repository tracks the evolution of this system from initial prototype to production-grade embedded architecture.

    [x] v1.0.0 — Initial working release (Synchronous LED driver, Serial menu, input dictionary parsing, error handling).

    [ ] v1.1.0 — Extract Hardware Abstraction Layer (HAL) to completely decouple application logic from Arduino framework headers.

    [ ] v1.2.0 — Refactor signaling driver into a non-blocking, timer/interrupt-driven state machine with ring-buffered message queues.

    [ ] v2.0.0 — Port application core to STM32CubeIDE / CMSIS bare-metal register control.


## License

Distributed under the MIT License. See LICENSE for more information.
