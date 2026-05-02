# esp32-sensors

## ⚙️ Setup V1 (Base System)

🔗 Pinout Reference

-> [esp32 OLED Pinout: https://www.espboards.dev/esp32/esp32-wroom-32d-oled/](Link for ESP32 pinout)

### 🧩 Components

- ESP32 ESP-WROOM from diymore (Dev Board)
- 0.96" OLED (I2C, SSD1306)
- 2x Yellow LEDs (rail indicator)
- 220Ω resistors (for LEDs)
- 2x 100µF capacitors (power stabilization)

---

## 🔌 Wiring Overview

### OLED (I2C)

- VCC → 3.3V
- GND → GND

---

### Power Rails

- Breadboard top + bottom rails powered
- Each rail has:
  - 1x LED (visual power indicator)
  - 1x 100µF capacitor (bulk stabilization)

---

## 💡 Design Decisions

### LEDs on rails

Used as **visual power indicators**:

- confirms power distribution (3.3V with approx. 5.5-7mA)
- useful for debugging and video clarity

⚠️ Note:
LED ≠ stable voltage indicator (only presence of voltage)

---

### 100µF Capacitors

Used for:

- buffering voltage drops
- stabilizing ESP32 + OLED during load spikes

⚠️ No small decoupling capacitors yet (planned for future versions)

---

## 🖥️ Software State

- OLED working (Adafruit SSD1306)
- text rendering via `snprintf`
- modular structure started:
  - `display_init()`
  - `build_text()`
  - `display_print_text()`

---

## 🚧 Limitations (V1)

- no real sensors connected yet

---

## 🚀 Next Steps

- integrate real sensors
