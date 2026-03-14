Smart Network Monitoring & Embedded Alert System

A real-time network security monitor with embedded hardware alerts using Linux, C, and Arduino.

This project detects unknown devices on a local network and triggers alerts via an Arduino-based embedded system. It demonstrates hardware-software integration, embedded C/C++ development, Linux networking, and serial communication in a professional OpenWrt-style environment.

System Architecture

Workflow Overview:

Network Device
↓

Linux Network Monitor (C)
↓

Device Detection Algorithm
↓

Serial Command (USB)
↓

Arduino Embedded System

LED Alert

Buzzer Alarm

Servo Lock

Components:

Network Devices – Any device connected to the network (computers, phones, IoT).

Linux Network Monitor – A C program running in WSL/Ubuntu that continuously scans the network every 15 seconds using arp.

Device Detection Algorithm – Compares the current scan against a whitelist of known devices (known_devices.txt). Unknown devices trigger alerts.

Serial Command (USB) – Communicates detected alerts to the Arduino via a Python helper script on Windows, ensuring reliable serial communication.

Arduino Embedded System – Responds to serial commands by activating:

LED Alert – Visual notification

Buzzer Alarm – Audio alert

Servo Lock – Physical locking mechanism

Workflow

The monitor scans the local network every configurable interval and logs all devices to current_scan.txt.

Each device is checked against a whitelist. If an unknown device is detected:

The event is logged to device_log.txt.

A serial command is sent to the Arduino.

The Arduino receives the command and activates the alert hardware.

The system repeats continuously, simulating a service-style embedded daemon similar to OpenWrt network monitoring.

Features

Real-time network monitoring with automated detection of unknown devices.

Reliable hardware alerts via Arduino (LED, buzzer, servo).

OpenWrt-style project structure, including logs, scripts, and modular C code.

Cross-platform integration: Linux (WSL) + Windows (Python COM helper) + Arduino hardware.

Logging and validation for debugging and demonstration purposes.

Skills Demonstrated

Embedded C/C++ programming

Linux networking and system scripting

Hardware-software integration

Serial communication and real-time alerts

Debugging, testing, and professional project structure

Folder Structure
smart-network-monitor
│
├── build/                  # Compiled C programs
├── logs/                   # Network scans and device logs
├── scripts/                # Startup scripts
├── src/                    # C source code
├── Arduino/                # Arduino firmware
└── README.md               # Project documentation
