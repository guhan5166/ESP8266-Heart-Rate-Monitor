# ❤️ ESP8266 Heart Rate Monitor (HW-827 + OLED)

A compact and accurate **heart rate monitoring system** built using **ESP8266**, **HW-827 pulse heart beat sensor**, and a **128×64 SSD1306 OLED display**.
The system measures pulse signals using infrared technology and displays **real-time BPM (beats per minute)** on the OLED with noise filtering for better accuracy.

---

## 📌 Features

* Real-time heart rate (BPM) display
* Noise-filtered pulse signal for improved accuracy
* Per-minute BPM calculation using time window method
* OLED display output (clear and readable)
* Simple and low-power design
* Suitable for learning health-monitoring IoT systems

---

## 🧰 Hardware Components

* ESP8266 (NodeMCU)
* HW-827 Pulse Heart Beat Sensor
* 0.96" OLED Display (SSD1306, 128×64, I2C)
* Jumper wires

---

## 📚 Required Libraries

Install the following libraries using **Arduino Library Manager**:

* **Adafruit GFX Library**
* **Adafruit SSD1306**

---

## ⚙️ How It Works

1. The HW-827 sensor detects blood flow changes using infrared light.

2. ESP8266 reads the analog pulse signal from the sensor.

3. A moving average filter removes noise from the signal.

4. Beats are counted within a fixed time window.

5. BPM is calculated accurately using:

   ```
   BPM = (Number of beats × 60) / Time window (seconds)
   ```

6. The OLED displays the current heart rate and signal strength.

---

## 🖥️ Output Display

The OLED shows:

* Project title
* Heart rate in BPM

Example:

```
Heart Rate Monitor
      76 BPM
```

---

## 🛠️ Calibration Notes

* Place your finger gently on the sensor
* Avoid excessive pressure or movement
* Adjust the pulse detection threshold in code if needed
* Stable BPM appears after a few seconds

---

## 👤 Author

**Guhan R**
