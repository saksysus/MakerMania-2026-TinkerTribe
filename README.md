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


# 📚 SilentGuard

### Smart Study Environment Monitoring System

> An ESP32-based smart monitoring system that helps libraries and study spaces maintain a productive learning environment through real-time noise monitoring, intelligent warnings, and silent vibration alerts.

---

## 📌 Project Overview

SilentGuard is a low-cost IoT solution designed for libraries, reading rooms, and study spaces. The system continuously monitors noise levels and converts the data into a simple **Study Quality Score (0–100)** with progressive student warnings.

Unlike conventional noise monitoring systems that only react after disturbances occur, SilentGuard proactively alerts noisy students using vibration alerts mounted on their study tables. The system provides fair enforcement through a 3-strike warning mechanism while encouraging students to self-correct their behavior.

The system operates locally using an ESP32, eliminating cloud dependency while providing real-time monitoring through an OLED display, RGB LED indicators, and vibration alerts.

---

## 🚧 Prototype Scope (Version 1)

The current prototype is implemented as a **single-table monitoring system**.

Features implemented in the prototype:

* Real-time noise monitoring
* Study Quality Score calculation
* OLED display feedback
* RGB LED status indication
* Vibration-based warning system
* 3-strike warning mechanism

Advanced features such as multi-table monitoring, centralized dashboards, analytics, and manager notifications are included as future scope and scalability plans.

---

## 🚀 Problem Statement

Libraries and study spaces often face challenges that reduce student productivity:

* Gradual increase in noise levels without immediate feedback.
* Lack of real-time information about study conditions.
* Difficulty maintaining quiet study environments.
* Dependence on manual monitoring by staff.
* No fair and consistent warning mechanism.
* Existing solutions are often expensive and cloud-dependent.

---

## 💡 Proposed Solution

SilentGuard combines noise sensing with intelligent local feedback to maintain productive study environments.

The system uses:

* ESP32 as the main controller
* INMP441 Digital I2S Microphone for noise monitoring
* OLED Display for showing noise level and warning count
* RGB LED for visual status indication
* Vibration Motor for silent alerts

The collected noise data is processed to generate:

* Study Quality Score (0–100)
* Real-time noise monitoring
* Progressive warning escalation
* Silent vibration feedback
* Student self-correction opportunities

---

## ✨ Features

* Real-time Noise Monitoring
* Study Quality Score (0–100)
* Adaptive Noise Thresholds
* Progressive 3-Strike Warning System
* Silent Vibration Alerts
* OLED Display Feedback
* RGB LED Status Indicators
* Local Processing (No Cloud Required)
* Automatic Daily Warning Reset
* Low-Cost Deployment

---

## 🔍 SCAMPER Analysis

### 🔄 Substitute

* Replace manual monitoring with automated sensing.
* Replace verbal warnings with silent vibration alerts.
* Replace subjective enforcement with measurable thresholds.

### 🤝 Combine

* Combine noise monitoring and warning systems.
* Combine OLED display with RGB LED indicators.
* Combine quality scoring and enforcement logic.

### 🛠️ Adapt

* Adapt smart building monitoring concepts for libraries.
* Adapt haptic feedback systems from smartphones.
* Adapt progressive warning systems used in behavioral management.

### ✨ Modify

* Convert reactive monitoring into proactive intervention.
* Introduce fair warning escalation.
* Use silent vibration feedback instead of public warnings.

### 📈 Put to Another Use

The system can also be used in:

* Reading Rooms
* Examination Halls
* Computer Laboratories
* Co-working Spaces
* Study Lounges
* Corporate Meeting Rooms
* Training Centers

### ❌ Eliminate

* Cloud dependency
* Subscription costs
* Manual monitoring
* Expensive commercial solutions
* Ambiguous enforcement

### 🔁 Reverse / Rearrange

* Alert students before staff intervention.
* Encourage self-correction first.
* Use silent feedback instead of audible alarms.

---

## ⚙️ Working Principle

```text
1. INMP441 Microphone captures ambient sound
         ↓
2. ESP32 continuously samples sound levels
         ↓
3. Rolling average noise calculation
         ↓
4. Study Quality Score generation
         ↓
5. If noise exceeds threshold:
   ├─ OLED Display shows warning
   ├─ RGB LED turns RED
   └─ Vibration Motor activates
         ↓
6. Warning counter increases
         ↓
7. Three-strike warning mechanism
         ↓
8. Daily automatic reset
```

---

## 🧩 Components Required

| Component              | Quantity    | Purpose           |
| ---------------------- | ----------- | ----------------- |
| ESP32 Dev Board        | 1           | Main controller   |
| INMP441 Microphone     | 1           | Noise monitoring  |
| OLED Display (SSD1306) | 1           | Student feedback  |
| RGB LED Module         | 1           | Visual indicators |
| Coin Vibration Motor   | 1           | Silent alerts     |
| Breadboard             | 1           | Prototyping       |
| Jumper Wires           | As required | Connections       |
| Resistors              | As required | Current limiting  |
| Capacitors             | As required | Decoupling        |
| USB Power Supply       | 1           | Power source      |

### Estimated Prototype Cost

**₹800 – ₹1,000**

---

## 🏗️ System Architecture

### Prototype Architecture

```text
INMP441 Microphone
          │
          ▼
       ESP32
          │
 ┌────────┼────────┐
 │        │        │
 ▼        ▼        ▼
OLED    RGB LED  Vibration
Display           Motor
```

### Future Multi-Table Architecture

```text
Table 1 ─┐
Table 2 ─┼─→ Central Monitoring System
Table 3 ─┤
Table N ─┘
```

---

## 📊 Study Quality Score Formula

```text
Quality Score =
(80% × Current Noise Score)
+
(20% × Noise Trend Score)
```

Where:

```text
Current Noise Score = 100 - Noise Level %

Noise Trend Score = Moving Average of Recent Readings
```

### Score Range

| Score  | Status       |
| ------ | ------------ |
| 75–100 | Excellent 🟢 |
| 50–74  | Moderate 🟡  |
| 0–49   | Poor 🔴      |

---

## 🚨 Warning System

### Warning 1

* Single vibration pulse
* OLED displays WARNING 1/3

### Warning 2

* Double vibration pulse
* OLED displays WARNING 2/3

### Warning 3

* Continuous vibration for 3 seconds
* OLED displays WARNING 3/3

### Daily Reset

Warning counts reset automatically every day.

---

## 🎯 Inputs

* INMP441 Digital Microphone

---

## 📺 Outputs

* OLED Display
* RGB LED
* Vibration Motor

---

## 👥 Target Users

### Primary Users

* Students
* Libraries
* Reading Rooms
* Educational Institutions

### Secondary Users

* Study Space Operators
* Co-working Spaces
* Training Centers

---

## 📈 Future Scope

* Multi-table monitoring
* Centralized dashboard
* Mobile notifications
* Noise analytics and heatmaps
* Student identification integration
* Historical data tracking
* AI-based disturbance prediction
* Library management integration

---

## ✅ Advantages

* Low Cost
* Fair Warning System
* Non-Intrusive Alerts
* Easy Installation
* Scalable Design
* No Cloud Dependency
* Real-Time Feedback
* Encourages Self-Regulation
* Suitable for Educational Institutions

---

## 🛠️ Technology Stack

### Hardware

* ESP32
* INMP441
* SSD1306 OLED Display
* RGB LED
* Coin Vibration Motor

### Software

* Arduino IDE
* ESP32 Core
* Adafruit SSD1306 Library
* Adafruit GFX Library

---

## 📂 Repository Structure

```text
SilentGuard/
│
├── firmware/
│   ├── SilentGuard.ino
│   ├── sensors.h
│   ├── scoring.h
│   ├── warnings.h
│   ├── display.h
│   └── config.h
│
├── docs/
│   ├── SETUP.md
│   ├── CALIBRATION.md
│   ├── PROJECT_REPORT.md
│   └── FUTURE_SCOPE.md
│
└── README.md
```

---

## 📎 Conclusion

SilentGuard is a practical and affordable embedded system designed to improve study environments through intelligent noise monitoring and silent feedback mechanisms. By combining real-time sensing, vibration-based alerts, and progressive warning logic, the system encourages self-regulation while maintaining a productive and distraction-free atmosphere.

The project demonstrates embedded systems design, IoT integration, human-centered feedback systems, and real-world problem solving, making it an effective engineering solution with strong deployment potential.

### Project Tagline

**"SilentGuard transforms libraries into self-regulating study environments through real-time noise monitoring, silent haptic feedback, and intelligent warning escalation."**

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
