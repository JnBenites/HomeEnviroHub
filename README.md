# 🏠 Home Environmental Monitoring Center

This project is an initial prototype for a **home environmental monitoring system** using an Arduino board, a DHT11 temperature and humidity sensor, and two status indicator LEDs. It is designed to evolve over time, with future features such as fan control and home server integration.

## 📋 Features

- Reads **temperature** and **humidity** data from a DHT11 sensor.
- Automatically classifies environmental status into:
  - **NORMAL** (temperature < 50°C)
  - **WARNING** (50–75°C)
  - **CRITICAL** (>100°C)
- Activates indicator LEDs:
  - Orange LED (pin 3) for **WARNING**
  - Red LED (pin 4) for **CRITICAL**
- Outputs real-time data in **JSON format** via the serial port.
- Performs an **initial LED test** on startup.
- Turns off onboard LED 13 ("L") to avoid confusion.

## 🛠️ Hardware Requirements

- Arduino UNO or compatible board  
- DHT11 sensor (Temperature & Humidity)  
- 2 LEDs (orange and red)  
- Resistors (220Ω recommended)  
- Jumper wires and breadboard  

## 🔌 Wiring Diagram

| Component      | Arduino Pin |
|----------------|-------------|
| DHT11 Data     | D2          |
| Orange LED     | D3          |
| Red LED        | D4          |
| DHT11 VCC/GND  | 5V / GND    |
| LEDs           | GND (via resistors) |

## 📦 Required Libraries

Install the following libraries via the Arduino Library Manager:

1. **DHT sensor library** by Adafruit  
2. **ArduinoJson** by Benoît Blanchon  

## 🚀 Getting Started

1. Upload the code to your Arduino.
2. Open the **Serial Monitor** at **9600 baud**.
3. Observe LED behavior and JSON data output every 2 seconds.

Example JSON output:
```json
{
  "temperature": 24.5,
  "humidity": 60.3,
  "unit": "C",
  "status": "NORMAL"
}
