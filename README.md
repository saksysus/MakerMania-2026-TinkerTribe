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
**Team Name:** TinkerTribe 🐥
---
<img width="1280" height="960" alt="team photo" src="https://github.com/user-attachments/assets/e44f3eb5-97ed-46d4-a207-95989e68f53b" />

---

## 1.2 Team Members

| Name | Role | Department | Year | Skills |
|------|------|------------|------|--------|
| Aayushi Choudhary | Hardware Design & Testing | EXTC | 2nd |Embedded Systems, Electronics, testing |
| Sakshi Gupta | IoT & Documentation Lead | AURO | 2nd | IoT, Documentation, Web Development |
| Yash Patwardhan | Hardware Integration & Fabrication | ECS | 1st | Programming, 3D designing, Hardware Integration |

---

# 📚 SilentGuard

# Smart Study Environment Monitoring System

An ESP32-based smart monitoring system that helps libraries and study spaces maintain a productive learning environment through real-time noise monitoring, intelligent warnings, and silent vibration alerts.

---

# 📌 Project Overview

SilentGuard is a low-cost IoT solution designed for libraries, reading rooms, and study spaces. The system continuously monitors noise levels and converts the collected data into a simple **Study Quality Score (0–100)** while providing progressive warnings to students.

Unlike conventional noise monitoring systems that only react after disturbances occur, SilentGuard proactively alerts noisy students using vibration alerts mounted on their study tables. The system provides fair enforcement through a **3-strike warning mechanism** while encouraging students to self-correct their behaviour.

Each monitoring unit consists of an ESP32 connected to an **INMP441 digital microphone**, RGB LED, and vibration motor. Every ESP32 (slave device) connects to the same local Wi-Fi network and sends live data to a **web-based dashboard**, which acts as the **master monitoring system** for librarians.

The dashboard allows librarians to monitor multiple study tables simultaneously without requiring cloud connectivity, making the system affordable, scalable, and privacy-friendly.

---

# 🚧 Prototype Scope (Version 1)

The current prototype is implemented as a **single-table monitoring system**.

### Features Implemented

- Real-time noise monitoring
- Study Quality Score calculation
- Live Web Dashboard Monitoring
- Wi-Fi communication between ESP32 and Dashboard
- RGB LED status indication
- Silent vibration-based warning system
- 3-strike warning mechanism
- USB-powered operation (No Battery)

Advanced features such as multi-table monitoring, battery-powered slave devices, centralized analytics, and mobile notifications are included as future scope.

---

# 🚀 Problem Statement

Libraries and study spaces often face several challenges that reduce student productivity:

- Gradual increase in noise levels without immediate feedback.
- Lack of real-time monitoring for librarians.
- Difficulty maintaining quiet study environments.
- Dependence on manual monitoring by staff.
- No fair and consistent warning mechanism.
- Existing commercial solutions are expensive and often cloud-dependent.

---

# 💡 Proposed Solution

SilentGuard combines embedded sensing with intelligent local processing to maintain productive study environments.

The system consists of:

- ESP32 as the main controller
- INMP441 Digital I2S Microphone for noise monitoring
- RGB LED for visual status indication
- Coin Vibration Motor for silent alerts
- Web Dashboard for centralized monitoring

The collected noise data is processed locally to generate:

- Study Quality Score (0–100)
- Real-time noise monitoring
- Progressive warning escalation
- Silent vibration feedback
- Student self-correction opportunities

Simultaneously, each ESP32 transmits live status updates over the local Wi-Fi network to a centralized web dashboard where librarians can monitor all connected devices in real time.

---

# ✨ Features

- Real-time Noise Monitoring
- Study Quality Score (0–100)
- Adaptive Noise Thresholds
- Progressive 3-Strike Warning System
- Silent Vibration Alerts
- Live Web Dashboard Monitoring
- RGB LED Status Indicators
- Local Processing (No Cloud Required)
- Low-Cost Deployment
- Wi-Fi Based Communication

---

# 🔍 SCAMPER Analysis

## 🔄 Substitute

- Replace manual monitoring with automated sensing.
- Replace verbal warnings with silent vibration alerts.
- Replace individual displays with a centralized web dashboard.

---

## 🤝 Combine

- Combine noise monitoring and warning systems.
- Combine Study Quality Score with live dashboard monitoring.
- Combine embedded sensing and Wi-Fi communication.

---

## 🛠️ Adapt

- Adapt smart building monitoring concepts for libraries.
- Adapt haptic feedback systems used in smartphones.
- Adapt progressive warning systems used in behavioural management.

---

## ✨ Modify

- Convert reactive monitoring into proactive intervention.
- Introduce fair warning escalation.
- Use silent vibration feedback instead of public audible alarms.

---

## 📈 Put to Another Use

The system can also be used in:

- Reading Rooms
- Examination Halls
- Computer Laboratories
- Co-working Spaces
- Study Lounges
- Corporate Meeting Rooms
- Training Centres

---

## ❌ Eliminate

- Cloud dependency
- Subscription costs
- Manual monitoring
- Expensive commercial solutions
- Ambiguous enforcement

---

## 🔁 Reverse / Rearrange

- Alert students before staff intervention.
- Encourage self-correction first.
- Use silent feedback instead of audible alarms.

---

# ⚙️ Working Principle

```
1. INMP441 Microphone captures ambient sound
                  │
                  ▼
2. ESP32 continuously samples sound levels
                  │
                  ▼
3. Rolling average noise calculation
                  │
                  ▼
4. Study Quality Score generation
                  │
                  ▼
5. If noise exceeds threshold:
   ├── RGB LED changes colour
   ├── Vibration Motor activates
   └── Warning Counter increases
                  │
                  ▼
6. ESP32 sends live data over Wi-Fi
                  │
                  ▼
7. Web Dashboard displays:
   • Noise Level
   • Study Quality Score
   • Warning Count
   • Device Status
                  │
                  ▼
8. Librarian monitors all connected tables
```

---

# 🧩 Components Required

| Component | Quantity | Purpose |
|-----------|---------:|---------|
| ESP32 Dev Board | 1 | Main Controller |
| INMP441 Digital Microphone | 1 | Noise Monitoring |
| RGB LED Module | 1 | Visual Status |
| Coin Vibration Motor | 1 | Silent Alerts |
| Breadboard | 1 | Prototyping |
| Jumper Wires | As Required | Connections |
| Resistors | As Required | Current Limiting |
| Capacitors | As Required | Decoupling |
| USB Power Supply | 1 | Power Source |

## Estimated Prototype Cost

**₹800 – ₹1,000**

---

# 🏗️ System Architecture

## Prototype Architecture

```
        INMP441
            │
            ▼
         ESP32
            │
     ┌──────┴──────┐
     │             │
     ▼             ▼
 RGB LED     Vibration Motor
            │
            ▼
      Wi-Fi Network
            │
            ▼
  Web Dashboard (Master)
```

## Future Multi-Table Architecture

```
Table 1 ESP32 ─┐
Table 2 ESP32 ─┤
Table 3 ESP32 ─┼────► Web Dashboard
Table 4 ESP32 ─┤
Table N ESP32 ─┘
```

---


# 📊 Study Quality Score Formula

The **Study Quality Score** is calculated by combining the current noise level with the recent noise trend to provide a more stable representation of the study environment.

```
Quality Score =
(80% × Current Noise Score)
+
(20% × Noise Trend Score)
```

### Where

- **Current Noise Score** = 100 − Noise Level (%)
- **Noise Trend Score** = Moving Average of Recent Noise Readings

## Score Range

| Score | Status |
|--------|--------|
| **75 – 100** | 🟢 Excellent |
| **50 – 74** | 🟡 Moderate |
| **0 – 49** | 🔴 Poor |

The Study Quality Score is updated continuously and displayed on the **web dashboard** for the librarian.

---

# 🚨 Warning System

SilentGuard follows a **progressive three-strike warning mechanism** to encourage students to self-correct before librarian intervention.

## Warning 1

- Single vibration pulse
- Dashboard displays **Warning 1/3**
- RGB LED changes to **Yellow**

---

## Warning 2

- Double vibration pulse
- Dashboard displays **Warning 2/3**
- RGB LED remains **Yellow**

---

## Warning 3

- Continuous vibration for approximately 3 seconds
- Dashboard displays **Warning 3/3**
- RGB LED turns **Red**
- Student is identified for possible librarian intervention

---


# 🎯 Inputs

- INMP441 Digital I2S Microphone

---

# 📺 Outputs

- RGB LED Status Indicator
- Coin Vibration Motor
- Live Web Dashboard

---

# 👥 Target Users

## Primary Users

- Students
- Libraries
- Reading Rooms
- Educational Institutions

---

## Secondary Users

- Library Staff
- Study Space Operators
- Co-working Spaces
- Training Centres

---

# 📈 Future Scope

SilentGuard has been designed with scalability in mind. Future versions can include:

- Multi-table monitoring
- Battery-powered slave devices
- Automatic device discovery
- Mobile application
- Push notifications
- Historical data logging
- Noise analytics and heatmaps
- AI-based disturbance prediction
- Occupancy monitoring
- Library management integration
- OTA firmware updates
- Cloud synchronization (optional)

---

# ✅ Advantages

- Low Cost
- Easy Installation
- Silent & Non-Intrusive Alerts
- Fair Warning Mechanism
- Real-Time Monitoring
- Local Processing (No Cloud Dependency)
- Wi-Fi Based Communication
- Scalable Architecture
- Encourages Student Self-Regulation
- Suitable for Educational Institutions

---

# 🛠️ Technology Stack

## Hardware

- ESP32 Dev Board
- INMP441 Digital I2S Microphone
- RGB LED Module
- Coin Vibration Motor
- Breadboard
- USB Power Supply

---

## Software

- Arduino IDE
- ESP32 Arduino Core
- HTML
- CSS
- JavaScript
- Node.js / Express Server
- Web Dashboard
- Wi-Fi Communication (HTTP)

---

SilentGuard is a practical and affordable embedded IoT solution designed to improve study environments through intelligent noise monitoring and silent feedback mechanisms.

By combining real-time sensing, Wi-Fi communication, vibration-based alerts, and a centralized web dashboard, the system encourages self-regulation while allowing librarians to monitor multiple study areas without manual supervision.

The project demonstrates embedded systems design, IoT networking, web integration, human-centred feedback systems, and real-world engineering problem solving, making it an effective solution with strong deployment potential.

---

# 🚀 Project Tagline

> **"SilentGuard transforms libraries into self-regulating study environments through real-time noise monitoring, silent haptic feedback, and intelligent warning escalation."**

---

# 🏗️ Mechanical / CAD

## Fabricated Components

The prototype enclosure has been designed to be compact, modular, and easy to install on study tables.

### Enclosure Features

- Compact housing for ESP32
- Mounting provision for INMP441 microphone
- RGB LED viewing window
- Coin vibration motor mounting
- Ventilation openings for accurate sound sensing
- USB cable routing for Version 1
- Screw-fit assembly for maintenance

---

## Future Mechanical Improvements

- Rechargeable battery compartment
- Wall/Table mounting clips
- Smaller PCB design
- Injection-moulded enclosure
- Waterproof casing for durability

---

# ⚙️ 8. Prototype Development

---

## Version 1

### Description

The first prototype validates the core concept of SilentGuard using a single ESP32-based monitoring unit.

The ESP32 continuously monitors ambient noise using the INMP441 microphone and processes the readings locally.

When excessive noise is detected:

- Study Quality Score is updated
- RGB LED changes status
- Silent vibration alerts are generated
- Warning count is increased

The ESP32 sends all live data over the local Wi-Fi network to a **web-based dashboard**, allowing the librarian to monitor the study area in real time.

Version 1 is powered directly through **USB** and **does not include a battery**.

### Features Implemented

- Single-table monitoring
- Real-time dashboard
- Wi-Fi communication
- Study Quality Score
- RGB LED indication
- Silent vibration alerts
- Three-strike warning system
- USB powered

### Lessons Learned

- Digital microphones provide much higher accuracy than analog sound sensors.
- Rolling average filtering significantly improves noise stability.
- Local Wi-Fi communication is sufficient without cloud infrastructure.
- Silent vibration alerts are less disruptive than audible alarms.
- A centralized web dashboard is significantly more useful than a local display for librarians.

---

## Version 2

### Description

Version 2 expands SilentGuard into a distributed monitoring system.

Multiple ESP32 slave devices communicate with one centralized web dashboard over the same Wi-Fi network.

Each study table operates independently while all devices are visible from a single dashboard.

### Planned Improvements

- Multiple slave devices
- Battery-powered operation
- Compact PCB
- Automatic device discovery
- Better enclosure
- Improved calibration
- Device identification

### Lessons Learned

*(To be completed after implementation.)*

---

## Final Prototype

### Description

The final envisioned system consists of multiple ESP32 slave devices deployed across an entire library.

Each device continuously monitors ambient sound and communicates wirelessly with a centralized web dashboard.

Students receive silent vibration alerts whenever excessive noise is detected, while librarians can monitor every connected table in real time.

The modular architecture allows SilentGuard to scale from a single prototype to an entire institutional deployment with minimal infrastructure changes.

---

# 🧪 9. Testing & Validation

## Testing Plan

| Test | Success Criteria |
|------|------------------|
| Noise Detection | Correctly differentiate quiet and noisy environments |
| Wi-Fi Communication | Stable communication with dashboard |
| Dashboard Updates | Live updates with minimal delay |
| Warning Logic | Correct warning escalation |
| RGB LED | Correct colour changes |
| Vibration Alerts | Correct vibration sequence |
| Continuous Operation | Stable operation over extended periods |

---

## User Feedback

| User | Feedback | Action Taken |
|------|----------|--------------|
| Students | Silent alerts are less distracting than audible alarms | Retained vibration alerts |
| Students | Dashboard does not disturb users | Continued centralized monitoring |
| Librarian | Live monitoring simplifies supervision | Planned multi-device dashboard |
| Faculty | Low-cost implementation is practical | Maintained affordable component selection |

---

---

# 💡 10. Innovation Assessment

## Existing Solutions

Current solutions available in the market include:

- Manual library supervision
- Basic sound level meters
- Decibel display systems
- Commercial IoT noise monitoring systems
- CCTV-based monitoring solutions

Most existing systems either:
- Only measure sound levels without providing corrective feedback.
- Depend heavily on manual intervention.
- Require expensive cloud infrastructure.
- Do not encourage student self-regulation.

---

## What Makes This Different?

SilentGuard introduces a student-centric approach to maintaining quiet study environments.

### Key Innovations

- Silent vibration-based feedback instead of audible alarms.
- Progressive 3-strike warning mechanism.
- Study Quality Score for monitoring study conditions.
- Local Wi-Fi communication without cloud dependency.
- Centralized web dashboard for librarians.
- Low-cost ESP32-based architecture.
- Modular design allowing deployment from a single table to an entire library.
- Encourages self-correction before librarian intervention.

---

## Innovation Score

| Parameter | Score (/10) |
|------------|------------:|
| Novelty | 8 |
| Technical Depth | 9 |
| Feasibility | 9 |
| Impact | 9 |
| Scalability | 8 |

---

# 🛡️ 11. Intellectual Property

## Prior Art Search

### Patents / Products Found

- Commercial decibel monitoring systems
- Smart classroom monitoring solutions
- IoT environmental monitoring systems
- Noise alert devices for offices and schools

---

## Novel Features

The following features differentiate SilentGuard from existing systems:

- Silent vibration-based warning mechanism.
- Progressive three-level warning escalation.
- Study Quality Score calculation.
- Distributed ESP32 architecture.
- Local Wi-Fi based dashboard monitoring.
- Scalable multi-device deployment.
- Affordable implementation using commodity hardware.

---

## Provisional Patent Draft

### Title

**SilentGuard: Smart Study Environment Monitoring and Silent Feedback System**

---

### Abstract

SilentGuard is an embedded IoT system designed to improve study environments by continuously monitoring ambient noise using distributed ESP32-based sensor nodes. The system provides silent vibration-based feedback to students while transmitting live environmental data over a local Wi-Fi network to a centralized web dashboard for librarians. The solution enables fair warning escalation, real-time supervision, and scalable deployment without relying on cloud infrastructure.

---

### Problem

Libraries and study spaces often rely on manual supervision to maintain silence, resulting in inconsistent enforcement and inefficient monitoring. Existing commercial solutions are expensive and often require cloud connectivity, making them unsuitable for many educational institutions.

---

### Solution

SilentGuard uses distributed ESP32 monitoring units equipped with digital microphones to detect excessive noise levels. Each device processes data locally, generates a Study Quality Score, provides silent vibration alerts, and communicates with a centralized web dashboard over the local Wi-Fi network. The modular architecture enables deployment across multiple study tables while maintaining affordability and ease of installation.

---

### Claims

1. Silent vibration-based warning mechanism for study environments.
2. Progressive three-strike warning escalation system.
3. Study Quality Score generation using real-time and historical noise trends.
4. Distributed ESP32 monitoring architecture.
5. Local Wi-Fi based centralized dashboard.
6. Modular and scalable deployment across multiple study areas.

---

# 💼 12. Business & Deployment

## Target Users

### Primary Users

- Libraries
- Universities
- Colleges
- Reading Rooms
- Educational Institutions

### Secondary Users

- Coaching Centres
- Study Cafés
- Co-working Spaces
- Corporate Training Centres

---

## Estimated Cost

| Item | Approximate Cost |
|------|-----------------:|
| Prototype (Version 1) | ₹800–₹1,000 |
| Estimated Production Cost | ₹700–₹900 per unit |

---

## Market Opportunity

Educational institutions are increasingly adopting smart campus technologies to improve student experiences and operational efficiency.

SilentGuard offers a cost-effective alternative to expensive commercial monitoring systems by combining embedded sensing, IoT communication, and centralized monitoring.

Its modular architecture allows institutions to begin with a small deployment and expand gradually as required.

---

## Sustainability Considerations

- Low power consumption.
- Local processing reduces cloud resource usage.
- Modular hardware minimizes electronic waste.
- Replaceable components increase product lifespan.
- Easy maintenance and future upgrades.

---

# 🎥 13. Final Demonstration

## Prototype Images

> *(Insert prototype photographs here.)*

---

## Demonstration Video Link

> *(Insert YouTube / Google Drive link.)*

---

## GitHub Repository

> *(Insert GitHub repository link.)*

---

## Presentation Link

> *(Insert Canva / Google Slides link.)*

---

# 📝 14. Reflection

## What Worked Well?

- Accurate noise detection using the INMP441 microphone.
- Stable Wi-Fi communication between ESP32 and dashboard.
- Silent vibration alerts effectively notify students without disturbing others.
- The centralized dashboard simplifies monitoring for librarians.
- Modular hardware design supports future expansion.

---

## What Failed?

- Initial sound sensor selection lacked sufficient accuracy.
- Noise thresholds required multiple rounds of calibration.
- Environmental sounds occasionally caused false positives during testing.
- Early dashboard communication experienced latency before optimization.

---

## Key Learnings

- Digital microphones provide more consistent measurements than analog sound sensors.
- Local Wi-Fi networking is sufficient for real-time monitoring in indoor environments.
- User-centered feedback mechanisms improve acceptance compared to audible alarms.
- Modular IoT architectures simplify scalability and maintenance.

---

## Next Steps

- Battery-powered slave devices.
- Multi-device deployment across larger libraries.
- Historical analytics and reporting.
- AI-based disturbance prediction.
- OTA firmware updates.
- Mobile application.
- Long-term field testing.
- Cloud synchronization (optional).

---

## Patent Filing

SilentGuard has the potential for a **provisional patent** based on the combination of distributed embedded monitoring, silent haptic feedback, progressive warning logic, and centralized web-based supervision.

---

## Startup Exploration

SilentGuard can be commercialized as an affordable smart library monitoring solution for schools, colleges, universities, and public libraries.

---

## Product Development

Future product roadmap:

- Compact custom PCB
- Rechargeable battery-powered devices
- Multi-floor deployment
- Mobile dashboard
- AI-based analytics
- Occupancy sensing
- Automatic firmware updates

---

## Research Publication

Potential research areas include:

- Smart Learning Environments
- Human-Centered IoT Systems
- Embedded Noise Monitoring
- Distributed Wireless Sensor Networks
- Intelligent Study Space Management

---

# ✅ 15. Final Deliverables Checklist

- [x] Problem Discovery Complete
- [x] User Interviews Complete
- [x] Persona Created
- [x] Problem Statement Finalized
- [x] System Design Complete
- [x] Prototype Demonstrated
- [x] Testing Completed
- [x] Patent Draft Prepared
- [ ] Presentation Submitted
- [ ] GitHub Repository Updated

---

# 📌 Conclusion

SilentGuard is a practical and affordable embedded IoT solution designed to improve study environments through intelligent noise monitoring, silent vibration-based feedback, and centralized real-time supervision.

By combining distributed ESP32 devices, local Wi-Fi communication, and a web-based dashboard, the system encourages student self-regulation while reducing the need for constant manual monitoring.

The project demonstrates embedded systems design, IoT networking, web integration, human-centered feedback systems, and scalable engineering, making it a promising solution for educational institutions and other shared workspaces.

---

# 🚀 Project Tagline

> **"SilentGuard transforms libraries into self-regulating study environments through real-time noise monitoring, silent haptic feedback, and intelligent web-based supervision."**
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
