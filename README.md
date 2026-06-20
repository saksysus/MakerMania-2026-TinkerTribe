# MAKERMANIA 2026 - TinkerTribe🐥
## Innovation Project Workbook

> Program Duration: 1 June 2026 – 4 July 2026
>
> Location: MBF Tinkerers' Lab 007
>
> Team Size: 3–5 Students
>
> Goal: Identify a real-world problem and develop an innovative, patentable, and implementable solution.

---

# 1. Team Identity

## 1.1 Team Name and Photo

---
<img width="1280" height="960" alt="team photo" src="https://github.com/user-attachments/assets/e44f3eb5-97ed-46d4-a207-95989e68f53b" />

## 1.2 Team Members

| Name | Role | Department | Year | Skills |
|------|------|------------|------|--------|
| Aayushi Choudhary |   |  EXTC   |   2nd   |        |
|Sakshi Gupta      |      | AURO  |   2nd   |        |
| Yash Patwardhan  |      |  ECS  |  1st    |        |
---

## Phantom Lock

 Phantom Lock is a lock that creates the illusion of security while lacking the very mechanism required to lock.
[![Watch the Demo](https://img.youtube.com/vi/78bA5DxY1MM/maxresdefault.jpg)](https://youtube.com/shorts/78bA5DxY1MM)



# 📚 SilentGuard
### Smart Study Environment Monitoring System

> An ESP32-based smart monitoring system that helps libraries and study spaces maintain a productive learning environment through real-time noise monitoring, intelligent warnings, and enforcement with vibration alerts.

---

## 📌 Project Overview

SilentGuard is a low-cost IoT solution designed for libraries, reading rooms, and study spaces. The system continuously monitors noise levels and converts the data into a simple **Study Quality Score (0–100)** with progressive student warnings and library manager dashboard alerts.

Unlike conventional noise monitoring systems that only react after disturbances occur, SilentGuard proactively alerts noisy students with vibration alerts on their study tables while simultaneously notifying the library manager via a web dashboard. The 3-strike warning system provides fair enforcement with clear escalation paths.

The system operates locally using an ESP32, eliminating cloud dependency while providing real-time monitoring through an OLED display (at table) and web dashboard (for manager).

---

## 🚀 Problem Statement

Libraries and study spaces often face challenges that reduce student productivity:

- **Gradual increase in noise levels** without immediate feedback to noisy students.
- **Lack of real-time information** about current study conditions.
- **Difficulty for librarians** to identify which table/zone is causing disturbance.
- **No fair enforcement mechanism** for repeat offenders.
- **Limited data** for optimizing study environment policies.

Existing solutions are often expensive, cloud-dependent, and focus only on passive monitoring without enforcement.

---

## 💡 Proposed Solution

SilentGuard combines noise sensing with intelligent alert systems to maintain productive study environments.

The system uses:

- **ESP32** as the main controller (WiFi-enabled)
- **MAX4466 sound sensor** for real-time noise monitoring
- **OLED display** for showing noise level + warning count at the study table
- **RGB LED** for visual status indicators (Green/Yellow/Red)
- **Vibration motor** mounted under the table for silent student alerts
- **Local web dashboard** for library manager to see all table status, warning counts, and enforcement actions

The collected noise data is processed to generate:

- **Study Quality Score** (0–100) based on current noise + noise trend
- **Real-time alerts** to students (vibration) when noise exceeds threshold
- **Manager notifications** with warning progression (1/2/3 strikes)
- **Enforcement tracking** for repeat violators

---

## ✨ Features

- **Real-time Noise Monitoring** (dB level display on OLED)
- **Study Quality Score** (0–100) based on noise level + trend
- **Adaptive Thresholds** (configurable noise limit per location)
- **Progressive Warning System** (3 strikes → ejection)
- **Vibration Motor Alerts** (silent feedback on study table)
- **Student OLED Display** (shows noise level + warning count)
- **RGB Visual Indicators** (Green = Good, Yellow = Moderate, Red = Poor)
- **Manager Web Dashboard** (real-time monitoring all tables/zones)
- **Warning History** (timestamp, dB level, duration per violation)
- **Reset Management** (daily resets, manual reset option)
- **No cloud dependency** (local WiFi only)

---

## 🔍 SCAMPER Analysis

### 🔄 Substitute

- Replace manual monitoring with automated real-time sensing.
- Replace verbal warnings with silent vibration alerts (non-disruptive).
- Replace subjective enforcement with data-driven, fair warnings.

### 🤝 Combine

- Combine noise monitoring, local alerts, and manager notifications.
- Combine OLED display with RGB LED for multi-modal feedback.
- Combine analytics dashboard with enforcement management.

### 🛠️ Adapt

- Adapt smart building monitoring concepts for libraries.
- Adapt escalation logic from gaming/behavior systems (3-strike enforcement).
- Adapt haptic feedback technology from mobile devices.

### ✨ Modify

- Convert reactive monitoring into **proactive student alerts**.
- Introduce **fair warning escalation** (instead of immediate ejection).
- Use **silent vibration alerts** instead of loud alarms or manager shaming.

### 📈 Put to Another Use

The system can also be used in:

- Reading Rooms & Quiet Zones
- Co-working Spaces
- Computer Laboratories
- Examination Halls
- Study Lounges
- Corporate Meeting Rooms
- Training Centers

### ❌ Eliminate

- Eliminate cloud dependency (local processing only).
- Eliminate subscription costs.
- Eliminate manual monitoring.
- Eliminate expensive commercial solutions.
- Eliminate ambiguity in enforcement (clear warning system).

### 🔁 Reverse / Rearrange

- Alert students **first** → Manager **second** (vs. only manager-led enforcement).
- Use **vibration feedback** instead of auditory warnings.
- Enable students to **self-correct** after first warning (empowering them).

---

## ⚙️ Working Principle

```
1. MAX4466 Microphone (at/near study table)
         ↓
2. Continuous noise level sampling (200ms cycle)
         ↓
3. ESP32 processing: rolling average filters + quality score calculation
         ↓
4. If noise ≥ 60dB for >30 seconds → Trigger warning sequence
         ↓
5. Multi-channel feedback:
   ├─ OLED Display: Shows dB level + "⚠️ WARNING 1/3"
   ├─ RGB LED: Turns RED
   ├─ Vibration Motor: 1-second buzz on table (1st warning)
   └─ Web Dashboard: Manager notified of alert
         ↓
6. (If noise continues after 5-10 min)
   └─ 2nd & 3rd warnings with escalating vibration intensity
         ↓
7. After 3rd warning → Manager intervenes (student ejected)
         ↓
8. Warning counter resets daily at 8 AM (fair second chance)
```

---

## 🧩 Components Required (Per Table)

| Component | Quantity | Purpose |
|-----------|----------|---------|
| ESP32 Dev Board | 1 | Main controller, WiFi connectivity |
| MAX4466 Sound Sensor | 1 | Noise monitoring (1 per table) |
| OLED Display (0.96") | 1 | Student-facing: noise level + warning count |
| RGB LED Module | 1 | Visual status indicator |
| Vibration Motor Module | 1 | Silent alert on study table |
| Breadboard | 1 | Prototyping |
| Jumper Wires | As needed | Connections |
| Resistors (10kΩ, 4.7kΩ) | As needed | Pull-downs, current limiting |
| Capacitors (100nF, 10µF) | As needed | Decoupling |
| USB Power Supply (5V/2A) | 1 | Main power |

**Total per table: ~₹1,740 (one-time prototype cost)**

---

## 🏗️ System Architecture

### Single-Table Setup (Phase 1)

```
Study Table
    │
    ├─ MAX4466 Microphone (captures noise)
    │       ↓
    │   ESP32 Controller
    │       ↓
    │   ┌───┴────────────────────┐
    │   │                        │
    ▼   ▼                        ▼
┌─────────────────┐      ┌──────────────────┐
│ At Study Table  │      │ Library Manager  │
├─────────────────┤      ├──────────────────┤
│ • OLED Display  │  ─→  │ • Web Dashboard  │
│   (noise dB +   │  ←─  │   (all tables)   │
│    ⚠️ warning)  │      │ • Warning counts │
│                 │      │ • Alert status   │
│ • RGB LED       │      │ • Reset button   │
│   (color status)│      │                  │
│                 │      │                  │
│ • Vibration     │      │                  │
│   Motor (buzz)  │      │                  │
└─────────────────┘      └──────────────────┘
```

### Multi-Table Setup (Phase 2+)

```
Table 1: MAX4466 → ESP32-1 ─┐
Table 2: MAX4466 → ESP32-2 ─┼─→ WiFi ─→ Manager Dashboard
Table 3: MAX4466 → ESP32-3 ─┤    (shows all tables
   ...                      └─    with warning counts)
```

---

## 📊 Study Quality Score Formula

**Simplified formula focused on noise:**

```
Quality Score = (80% × Current Noise Score) + (20% × Noise Trend Score)

Where:
  Current Noise Score = 100 - (dB reading / 100) × 100
  Noise Trend Score = moving average of last 5 readings
  
Score Range:
  75–100 = Excellent (🟢 Green LED)
  50–74  = Moderate (🟡 Yellow LED)
  0–49   = Poor (🔴 Red LED) → Triggers warning
```

**Threshold for Warnings:**
- Quality Score ≤ 49 (Noise ≥ 60dB) for >30 seconds
- 1st Warning: Single vibration pulse (1 second)
- 2nd Warning: Double vibration pulse (2 seconds, 2× pattern)
- 3rd Warning: Continuous vibration (3 seconds) + Ejection flag

---

## 🎯 Inputs

- **MAX4466 Noise Sensor** (mounted at/near study table)

---

## 📺 Outputs

- **OLED Display** (at student's table: noise dB + warning count)
- **RGB LED** (visual status: Green/Yellow/Red)
- **Vibration Motor** (silent alert on table surface)
- **Web Dashboard** (manager view: all tables, warning progression, enforcement)
- **Data Logging** (warning history with timestamps)

---

## 👥 Target Users

**Primary:**
- **Students** (receive vibration alerts, see their noise level)
- **Librarians/Managers** (monitor dashboard, enforce rules)
- **Library Administration** (track enforcement data, optimize policies)

**Secondary:**
- Educational Institutions
- Reading Room Operators
- Study Space Managers

---

## 📈 Future Scope

- **Mobile app** for manager notifications (push alerts when WARNING 3 triggered)
- **Multi-zone expansion** (10–20 tables with single centralized manager dashboard)
- **Student ID integration** (track repeat offenders across weeks/months)
- **Advanced analytics** (peak noise hours, problem areas heatmap)
- **AI prediction** (predict disturbances before they escalate)
- **Library management integration** (auto-log violations in student systems)

---

## ✅ Advantages

- **Low-cost** implementation (₹1,740/table, scalable)
- **Fair enforcement** (clear 3-strike system, not arbitrary)
- **Student-centric** (vibration alert gives chance to self-correct)
- **Manager empowerment** (dashboard data, not guesswork)
- **Privacy-preserving** (noise level only, no recording/video)
- **Expandable** (easy to add more tables/zones)
- **No internet dependency** (local WiFi only)
- **Suitable for colleges** (real-world problem solving, doable in 3 weeks)

---

## 📎 Conclusion

SilentGuard is a practical and affordable smart monitoring solution that addresses the real problem of noise disruption in libraries. By combining noise monitoring, progressive warnings, vibration alerts, and manager dashboards, the system helps maintain productive learning environments while providing fair, data-driven enforcement.

The 3-strike warning system empowers students to self-correct their behavior while giving managers clear data to make decisions. The project demonstrates embedded systems design, IoT integration, UX/alert design, and human-centered enforcement systems — making it an ideal engineering project with strong real-world deployment potential.

---

# 7. TECHNICAL PLANNING

## 7.1 Electronics

Core microcontroller, noise sensor, and alert hardware.

| Component | Purpose | Specifications | Qty | Supplier | Price (₹) |
|-----------|---------|-----------------|-----|----------|-----------|
| ESP32-WROOM-32 Dev Board | Central controller, WiFi connectivity | Dual core, 4MB Flash, WiFi | 1 | LCSC: C529222 | ₹450 |
| MAX4466 Sound Sensor Module | Noise level detection | Mic bias, 63dB gain, op-amp output | 1 | Robocraze | ₹380 |
| SSD1306 OLED 128×64 Display | Real-time noise display + warning counter | I2C interface, 0.96" | 1 | LCSC: C192994 | ₹280 |
| RGB LED Module | Visual status indicator (Green/Yellow/Red) | Common cathode, PWM control | 1 | Robocraze | ₹60 |
| Vibration Motor Module | Silent alert on study table | DC 3.3V, <100mA | 1 | LCSC: C506039 | ₹50 |
| 10kΩ Resistors | Pull-down for ADC pin | Standard carbon film | 1 Pack | Generic | ₹80 |
| 100nF Capacitors | Decoupling | Standard ceramic | 1 Pack | Generic | ₹90 |
| Breadboard + Jumper Wires | Prototyping | Standard breadboard + wire kit | 1 Set | Generic | ₹150 |
| USB-C Power Supply (5V/2A) | Main power source | 5V, ≥2A rated | 1 | Generic | ₹200 |
| **TOTAL** | | | | | **₹1,740** |

---

## 7.2 Software Tools & Libraries

| Tool / Library | Purpose | Version | Notes |
|----------------|---------|---------|-------|
| Arduino IDE | ESP32 firmware development | 2.3+ | Free, official Espressif support |
| ESP32 Boards Package | Core microcontroller support | 3.0+ | Install via Boards Manager |
| Adafruit_SSD1306 | OLED display control | 2.1.0+ | I2C driver for display |
| Adafruit_GFX | Graphics library for fonts/rendering | 1.11.0+ | Dependency for Adafruit_SSD1306 |
| AsyncWebServer | Lightweight HTTP server for dashboard | 1.2.3+ | Non-blocking, WebSocket-ready |
| SPIFFS / LittleFS | Local filesystem for HTML/CSS storage | Built-in | Store dashboard files on ESP32 |
| ArduinoJson | JSON serialization for API responses | 6.18.0+ | For sensor data API endpoints |
| VS Code + PlatformIO | Advanced IDE with debugging (optional) | Latest | Better than Arduino IDE for larger projects |

---

## 7.3 GPIO Pin Assignments

| Peripheral | GPIO Pin | Mode | Function | Voltage | Notes |
|------------|----------|------|----------|---------|-------|
| MAX4466 Microphone | GPIO34 | ADC1_CH6 (Analog Input) | Noise level (0–3.3V) | 0–3.3V | INPUT_ONLY, use 10kΩ pull-down |
| OLED Display (SDA) | GPIO21 | I2C Data | I2C communication | 3.3V | Address: 0x3C |
| OLED Display (SCL) | GPIO22 | I2C Clock | I2C communication | 3.3V | Address: 0x3C |
| RGB LED - Red | GPIO12 | PWM Output | Red channel | 3.3V | Indicates poor noise (RED status) |
| RGB LED - Green | GPIO13 | PWM Output | Green channel | 3.3V | Indicates good noise (GREEN status) |
| RGB LED - Blue | GPIO14 | PWM Output | Blue channel | 3.3V | Indicates excellent noise (BLUE status) |
| Vibration Motor | GPIO27 | PWM Output | Motor control (vibration pattern) | 3.3V | 1st: 1s pulse, 2nd: 2s×2 pulse, 3rd: 3s continuous |

---

## 7.4 Bill of Materials Summary

**Estimated Cost: ₹1,740 per table**

| Category | Items | Cost |
|----------|-------|------|
| Main Controller | ESP32 | ₹450 |
| Sensors | MAX4466 microphone | ₹380 |
| Display & Feedback | OLED, RGB LED, Vibration motor | ₹390 |
| Passive Components | Resistors, capacitors | ₹170 |
| Accessories | Breadboard, wires, power supply | ₹350 |
| **TOTAL** | | **₹1,740** |

**Suppliers**: LCSC India, Robocraze, Logic Instruments  
**Bulk Pricing**: 5+ tables = 10–15% discount possible

---

## 7.5 Three-Week Build Timeline

### **Week 1: Hardware Setup & Sensor Calibration**

**Milestones:** Breadboard assembly, firmware scaffold, noise baseline calibration

| Task | Owner | Details |
|------|-------|---------|
| Assemble breadboard circuit | Yash | Connect MAX4466 → GPIO34, Vibration motor → GPIO27, OLED → GPIO21/22, RGB LED → GPIO12/13/14 |
| Test MAX4466 individually | Yash | Output raw ADC values to serial monitor |
| Calibrate noise baseline | Sakshi + Yash | Measure dB levels in silent library, establish 50dB floor threshold |
| Set up Arduino IDE + ESP32 | Sakshi | Install board support, verify board detection |
| Test OLED I2C communication | Yash | Run I2C Scanner, verify address 0x3C |
| Verify RGB LED & vibration motor | Yash | Test basic GPIO control of all outputs |

**Output**: Working breadboard with all components responding to serial commands

---

### **Week 2: Firmware Development + Manager Dashboard**

**Milestones:** Warning logic, display output, web interface

| Task | Owner | Details |
|------|-------|---------|
| Implement noise reading loop | Sakshi | 200ms sampling cycle, rolling average filters (5-second window) |
| Code warning trigger logic | Sakshi | If noise ≥60dB for >30s → increment warning counter (max 3) |
| Implement Study Quality Score formula | Sakshi | Score = 80% current noise + 20% noise trend |
| OLED display firmware | Sakshi | Display format: Line1="Noise: 65 dB", Line2="Quality: 35/100", Line3="⚠️ WARNING 1/3" |
| RGB LED color transitions | Sakshi | Green (score 75+) → Yellow (50-74) → Red (0-49) |
| Vibration motor control | Sakshi | 1st warning: 1s buzz, 2nd: 2s×2 pulse, 3rd: 3s continuous |
| Set up AsyncWebServer | Aayushi | Create web server on port 80 |
| Design manager dashboard UI | Aayushi | Real-time noise gauge, warning counter, alert status, reset button |
| Create JSON API endpoints | Sakshi + Aayushi | `/api/status` (current data), `/api/history` (warnings), `/api/reset` (manual reset) |
| SPIFFS integration | Aayushi | Store HTML/CSS/JS files on ESP32, enable file serving |

**Output**: Fully functional firmware with local OLED display + web dashboard

---

### **Week 3: Integration Testing & Documentation**

**Milestones:** Full system validation, refinement, production-ready code

| Task | Owner | Details |
|------|-------|---------|
| Simulate noise violations | All | Clap, phone speaker, loud talking to trigger warnings 1→2→3 |
| Verify warning progression | Sakshi | Confirm counter increments, vibration escalates, OLED updates |
| Test web dashboard sync | Aayushi | Verify manager sees real-time updates from hardware |
| Fine-tune noise thresholds | Sakshi + Yash | Adjust 60dB trigger based on actual library acoustics |
| Optimize power consumption | Sakshi + Yash | Measure current draw, estimate runtime on USB power |
| Documentation | All | Setup guide, manager manual, troubleshooting, GitHub README |
| Final GitHub commit | Sakshi | Clean code, inline comments, version 1.0 release |

**Output**: Production-ready system, documented, tested, ready for library deployment

---

## 7.6 Hardware Placement & Installation Guide

### Microphone Placement

```
Study Table (Top View)
┌──────────────────┐
│ Student      📍  │ ← Microphone: 30–50cm from
│ Position     Mic │    student's mouth (captures talking)
│              │   │
│                  │
└──────────────────┘

Optimal: Mounted on table edge or wall ~50cm above desk
```

### Vibration Motor Placement

```
Study Table (Side View)
┌──────────────────┐
│                  │
│             📳   │ ← Vibration motor: mounted under
│  Vibrator ← ╱    │    table surface (on leg or frame)
│  (mounted        │    Student feels vibration clearly
│  underneath)     │
│                  │
└──────────────────┘

Installation: Double-sided tape or velcro on wooden desk leg
```

---

## 7.7 Critical Design Notes

### Hardware Considerations

- **ADC Pin (GPIO34)**: INPUT_ONLY, must use 10kΩ pull-down for stable readings
- **MAX4466 Calibration**: Requires ~50dB dead-band filtering; calibrate in silent conditions
- **Vibration Motor**: 3.3V DC, ~100mA peak — within ESP32 GPIO current limits (no transistor needed)
- **I2C Address**: Verify OLED is 0x3C using I2C Scanner sketch before deployment
- **Power Budget**: ~80mA average draw; 5V/2A supply sufficient for continuous operation

### Firmware Considerations

- **Warning Counter**: Stored in SPIFFS (survives power loss)
- **Daily Reset**: Automatic reset at 8:00 AM (configurable in code)
- **Noise Detection**: Requires 30+ seconds of sustained noise ≥60dB to trigger (prevents false positives from single loud events)
- **Firmware Size**: ~550KB (leaves 850KB headroom for future features)
- **WiFi Network**: Set SSID/password in code or implement soft-AP for manual WiFi setup

### Library Manager Workflow

1. Manager opens web dashboard (192.168.x.x:80) on tablet/laptop
2. Dashboard shows real-time noise level + warning count for table
3. When WARNING 3 is triggered → Dashboard shows "TAKE ACTION" alert
4. Manager goes to table, speaks to student, requests departure
5. After student leaves → Manager clicks "Reset" button on dashboard
6. Warning counter cleared, table ready for next student

---

## 7.8 Success Metrics

- ✅ MAX4466 reading stable noise data within 2 minutes of power-on
- ✅ Noise level updates every 200ms on OLED without lag
- ✅ Manager dashboard accessible from any device on WiFi network
- ✅ RGB LED transitions smoothly (Green → Yellow → Red)
- ✅ Vibration motor triggers within 500ms of RED threshold (60dB)
- ✅ Warning counter increments correctly on each violation
- ✅ OLED clearly displays warning count with emoji (⚠️/⚠️⚠️/⚠️⚠️⚠️)
- ✅ Manager dashboard syncs in real-time (<1 second latency)
- ✅ System operates continuously for ≥12 hours on USB power
- ✅ Firmware compiles under 600KB (adequate headroom)

---

## 7.9 Scalability Roadmap

| Phase | Tables | Hardware | Manager View | Cost |
|-------|--------|----------|--------------|------|
| **Phase 1 (Now)** | 1 | 1 ESP32 + 1 MAX4466 + 1 vibration motor | Single table dashboard | ₹1,740 |
| **Phase 2** | 4–6 | 6× (sensors + motors) + 1 central ESP32 coordinator | All 6 tables on single dashboard | ₹10,000–12,000 |
| **Phase 3** | 10–20 | Mesh network (WiFi/ESP-NOW) + central hub | Large dashboard with heatmaps + analytics | ₹20,000–30,000 |

---

## 7.10 Repository Structure

```
SilentGuard/
├── firmware/
│   ├── SilentGuard.ino           # Main sketch
│   ├── sensors.h                 # Noise reading functions
│   ├── scoring.h                 # Quality score calculation
│   ├── warnings.h                # Warning logic & counters
│   ├── display.h                 # OLED display functions
│   └── config.h                  # GPIO pins & thresholds
├── web_dashboard/
│   ├── index.html                # Manager dashboard UI
│   ├── style.css                 # Styling
│   ├── script.js                 # Real-time data fetch
│   └── api.js                    # JSON API handling
├── docs/
│   ├── SETUP.md                  # Hardware assembly guide
│   ├── CALIBRATION.md            # Noise baseline setup
│   ├── MANAGER_GUIDE.md          # Dashboard usage
│   └── TECHNICAL_PLANNING.md     # This document
└── README.md                     # Project overview & quick start
```

---

**Document Version**: 2.0 (Noise + Warning Enforcement)  
**Last Updated**: June 2026  
**Prepared for**: TinkerTribe (Sakshi, Yash, Aayushi)  
**Status**: Ready for 3-Week Prototype Build

---

## Mechanical / CAD

Describe fabricated components.

---

# 8. Prototype Development

## Version 1

Description:

Lessons Learned:

---

## Version 2

Description:

Lessons Learned:

---

## Final Prototype

Description:

---

# 9. Testing & Validation

## Testing Plan

| Test | Success Criteria |
| ---- | ---------------- |
|      |                  |
|      |                  |

---

## User Feedback

| User | Feedback | Action Taken |
| ---- | -------- | ------------ |
|      |          |              |

---

# 10. Innovation Assessment

## Existing Solutions

List competing products.

---

## What Makes This Different?

---

## Innovation Score

| Parameter       | Score |
| --------------- | ----- |
| Novelty         |       |
| Technical Depth |       |
| Feasibility     |       |
| Impact          |       |
| Scalability     |       |

---

# 11. Intellectual Property

## Prior Art Search

Patents / Products Found:

---

## Novel Features

1.

2.

3.

---

## Provisional Patent Draft

### Title

### Abstract

### Problem

### Solution

### Claims

---

# 12. Business & Deployment

## Target Users

---

## Estimated Cost

---

## Market Opportunity

---

## Sustainability Considerations

---

# 13. Final Demonstration

## Prototype Images

Insert photos.

---

## Demonstration Video Link

---

## GitHub Repository

---

## Presentation Link

---

# 14. Reflection

## What Worked Well?

---

## What Failed?

---

## Key Learnings

---

## Next Steps

* Patent Filing
* Startup Exploration
* Product Development
* Research Publication
* Competition Submission

---

# 15. Final Deliverables Checklist

* Problem Discovery Complete
* User Interviews Complete
* Persona Created
* Problem Statement Finalized
* System Design Complete
* Prototype Demonstrated
* Testing Completed
* Patent Draft Prepared
* Presentation Submitted
* GitHub Repository Updated

---

# MAKERMANIA FINAL PITCH

Each team will present:

1. Problem
2. User Research
3. Insights
4. Solution
5. Prototype Demo
6. Innovation & Patentability
7. Future Roadmap

Presentation Time: 5 Minutes

Q&A: 3 Minutes
