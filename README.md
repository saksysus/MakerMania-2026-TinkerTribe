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

> An ESP32-based smart monitoring system that helps libraries and study spaces maintain a productive learning environment through noise monitoring, seat occupancy tracking, motion analysis, and intelligent study quality assessment.

---

## 📌 Project Overview

SilentGuard is a low-cost IoT solution designed for libraries, reading rooms, and study spaces. The system continuously monitors environmental conditions using sound, motion, and occupancy sensors and converts the collected data into a simple and intuitive **Study Quality Score (0–100)**.

Unlike conventional noise monitoring systems that only react after disturbances occur, SilentGuard proactively analyzes environmental trends and identifies issues before they significantly impact study quality.

The system operates locally using an ESP32, eliminating cloud dependency while providing real-time monitoring through a web dashboard.

---

## 🚀 Problem Statement

Libraries and study spaces often face challenges that reduce student productivity:

- Gradual increase in noise levels.
- Seat hoarding by students leaving bags unattended.
- Lack of real-time information about study conditions.
- Difficulty finding quiet study zones.
- Limited data for librarians to optimize study environments.

Existing solutions are often expensive, cloud-dependent, and focus only on noise measurement.

---

## 💡 Proposed Solution

SilentGuard combines multiple sensors and intelligent processing to monitor study spaces in real time.

The system uses:

- ESP32 as the main controller
- MAX4466 sound sensors for noise monitoring
- FSR sensors for seat occupancy detection
- PIR sensors for motion tracking
- OLED display for live score visualization
- RGB LED for visual alerts
- Vibration motor for silent notifications
- Local web dashboard for monitoring and analytics

The collected data is processed to generate a **Study Quality Score** based on:

- Noise Level
- Noise Trend
- Occupancy Status
- Motion Activity

---

## ✨ Features

- Real-time Study Quality Score (0–100)
- Adaptive noise monitoring
- Noise trend detection
- Seat occupancy tracking
- Seat hoarding detection
- Motion activity analysis
- OLED score display
- RGB visual indicators
- Silent vibration alerts
- ESP32 web dashboard
- Data logging and analytics
- No cloud dependency

---

## 🔍 SCAMPER Analysis

### 🔄 Substitute

- Replace manual monitoring with automated sensing.
- Replace verbal warnings with silent vibration alerts.
- Replace manual seat checking with occupancy sensors.

### 🤝 Combine

- Combine noise monitoring, occupancy detection, and motion tracking.
- Combine analytics and monitoring into one system.
- Combine visual and haptic alerts.

### 🛠️ Adapt

- Adapt smart building monitoring concepts for libraries.
- Adapt occupancy tracking systems used in modern offices.
- Adapt environmental quality scoring techniques.

### ✨ Modify

- Convert reactive monitoring into proactive monitoring.
- Introduce a Study Quality Score.
- Use silent alerts instead of loud alarms.

### 📈 Put to Another Use

The system can also be used in:

- Reading Rooms
- Co-working Spaces
- Computer Laboratories
- Examination Halls
- Study Lounges
- Training Centers

### ❌ Eliminate

- Eliminate cloud dependency.
- Eliminate subscription costs.
- Eliminate manual monitoring.
- Eliminate expensive commercial solutions.

### 🔁 Reverse / Rearrange

- Predict disturbances instead of reacting to them.
- Automatically identify problematic study zones.
- Help students locate productive study areas.

---

## ⚙️ Working Principle

1. Sensors continuously collect environmental data.
2. ESP32 processes incoming sensor readings.
3. Noise trends are analyzed using rolling averages.
4. Occupancy and motion activity are evaluated.
5. A Study Quality Score is calculated.
6. Results are displayed through:
   - OLED Display
   - RGB LED Indicator
   - Vibration Alert
   - Web Dashboard
7. Data is logged for future analysis.

---

## 🧩 Components Required

| Component | Quantity |
|------------|----------|
| ESP32 Dev Board | 1 |
| MAX4466 Sound Sensor | 2 |
| FSR Pressure Sensor | 4 |
| PIR Motion Sensor | 2 |
| OLED Display (0.96") | 1 |
| RGB LED Module | 1 |
| Vibration Motor Module | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| Resistors | As Required |
| USB Power Supply | 1 |

---

## 🏗️ System Architecture

```text
MAX4466 Sound Sensors
          │
          ▼
       ESP32
          │
 ┌────────┼────────┐
 │        │        │
 ▼        ▼        ▼
FSR      PIR    Processing
Seats   Motion
          │
          ▼
 Study Quality Score
          │
 ┌────────┼────────┬────────┐
 ▼        ▼        ▼        ▼
OLED    RGB LED  Vibration Dashboard
Display            Motor
```

---

## 📊 Study Quality Score Formula

```text
Quality Score =
(40% × Noise Score)
+ (20% × Noise Trend Score)
+ (20% × Occupancy Score)
+ (20% × Motion Score)
```

### Score Range

| Score | Status |
|---------|---------|
| 75 – 100 | Excellent |
| 50 – 74 | Moderate |
| 0 – 49 | Poor |

---

## 🎯 Inputs

- Sound Sensors
- FSR Occupancy Sensors
- PIR Motion Sensors

---

## 📺 Outputs

- OLED Display
- RGB LED Indicator
- Vibration Motor Alert
- Web Dashboard
- Analytics Reports

---

## 👥 Target Users

- Students
- Librarians
- Educational Institutions
- Reading Room Operators
- Study Space Managers

---

## 📈 Future Scope

- AI-based noise prediction
- Mobile application support
- Multi-zone monitoring
- Wireless sensor nodes
- Cloud synchronization
- Integration with library management systems
- Smart campus deployment
- Predictive analytics

---

## ✅ Advantages

- Low-cost implementation
- Easy to prototype
- Real-world problem solving
- Improves study productivity
- Supports data-driven decision making
- Expandable architecture
- No internet dependency
- Suitable for educational institutions

---

## 📎 Conclusion

SilentGuard is a practical and affordable smart monitoring solution for modern study spaces. By combining environmental sensing, occupancy tracking, trend analysis, and intelligent alerts, the system helps maintain productive learning environments while providing valuable insights for facility management.

The project demonstrates embedded systems, IoT, sensor integration, data analytics, and human-centered design, making it an ideal engineering project with strong future potential for smart campus infrastructure.

# 7. Technical Planning

## Electronics

| Component | Purpose |
| --------- | ------- |
|           |         |
|           |         |

---

## Software

| Tool | Purpose |
| ---- | ------- |
|      |         |
|      |         |

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
