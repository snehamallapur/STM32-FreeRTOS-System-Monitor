# STM32-FreeRTOS-System-Monitor

A small embedded firmware demo for STM32H5 using FreeRTOS.

## Overview

This project implements a simple task-based data pipeline:

- **DAQ Task**: reads internal temperature sensor and hardware RNG
- **Processing Task**: computes rolling average/min/max and alert state
- **Comms Task**: sends formatted telemetry over UART
- **Health Task**: reports task stack watermarks

## Goals

This project was built to practice:

- FreeRTOS task creation and scheduling
- queue-based inter-task communication
- periodic task execution with `vTaskDelayUntil`
- basic system observability in embedded firmware

## Current Status

This is an **initial version** intended as a learning/demo project.
It is functional as a prototype, but still has areas planned for improvement:

- better UART handling (interrupt/DMA)
- improved ADC temperature measurement accuracy
- queue overflow monitoring
- cleanup of generated RTOS boilerplate
- stronger error handling and fault reporting

## Target

- MCU: STM32H5 series (STM32H563ZI)
- HAL: STM32 HAL
- RTOS: FreeRTOS

## Architecture

DAQ -> Processing -> Comms  
Health runs independently and reports task stack usage.

## Future Improvements

- migrate UART TX to non-blocking mode
- add fault counters and watchdog integration
- add unit-testable processing logic separation
- improve documentation and timing analysis
