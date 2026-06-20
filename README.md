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



# ESP32-Based Smart Mini LED Game Console

A compact ESP32 gaming console built with an 16x8 MAX7219 LED matrix and push buttons. It supports two simple games: a mini Tetris-style game and a pattern memory recreation game.

## 📌 Project Overview

The **ESP32-Based Smart Mini LED Game Console** is a low-cost embedded gaming device designed for retro-style gameplay on a small LED matrix. It uses an ESP32 microcontroller as the main controller, an 16x8 MAX7219 LED matrix as the display, and push buttons for input.

The project is intended for students and beginner makers who want to learn embedded programming, SPI communication, display control, and game logic through a fun hands-on build.

## 🚀 Problem Statement

Many student game projects become expensive or too complex because they rely on large displays, advanced controllers, or too many components. This makes them harder to build, test, and demonstrate in a classroom or budget-focused environment.

A small LED-based console solves this by using basic hardware such as an ESP32, an 8x8 matrix, and buttons. It provides a simple platform for retro games while still teaching display interfacing, input handling, and embedded logic.

## 💡 Proposed Solution

The proposed system uses:
- An **ESP32** as the main controller
- An **16x8 MAX7219 LED matrix** as the display
- **Push buttons** for game input
- An optional **buzzer** for sound feedback

The console starts with a menu screen where the user can select between two games:
1. **Mini Tetris**
2. **Pattern Copy / Memory Game**

The system is compact, easy to assemble on a breadboard or perfboard, and suitable for student projects.

## ✨ Features

- Dual game support: mini Tetris and pattern memory game.
- 16x8 LED matrix display for retro pixel-style gameplay.
- Push-button controls for navigation and gameplay.
- Game selection menu.
- Optional buzzer for sound effects.
- Low-cost and beginner-friendly hardware.
- Easy to expand with more games later.


## 🔍 SCAMPER Analysis

### 🔄 Substitute

Replace expensive graphical displays with a compact 8×8 LED matrix.

### 🤝 Combine

Combine gaming, embedded programming, and display control into a single platform.

### 🛠️ Adapt

Adapt classic retro gaming concepts into a simple embedded system.

### ✨ Modify

Modify traditional Tetris and memory games to fit an 8×8 display.

## ⚙️ Working Principle

When powered on, the ESP32 initializes the LED matrix, buttons, and menu system. The player uses buttons to select between the available games.

In **Mini Tetris**, small blocks fall on the 8x8 matrix, and the player moves or rotates them to complete lines. Because the display is very small, the game is simplified compared to full-size Tetris.

In **Pattern Copy**, the console briefly shows a random LED pattern. After the pattern disappears, the player must recreate it using the buttons. The ESP32 compares the player’s pattern with the original and shows whether the attempt was correct.

## 🧩 Suggested Components

- ESP32 development board.
- MAX7219 16x8 LED matrix module.
- 4 to 5 push buttons.
- Breadboard or perfboard.
- Jumper wires.
- Optional buzzer.
- Optional battery module for a portable version.

## 🎮 Suggested Games

| Game | Suitability on 8x8 | Notes |
|---|---|---|
| Pattern Copy | Excellent | The display itself works naturally as a memory grid. |
| Mini Tetris | Possible | Must be simplified because of the limited display space. |

## 🛠️ Future Scope

- Add more games such as Snake, Pong, or Reaction Challenge.
- Upgrade from 16x8 to 32x8 for improved gameplay.
- Add buzzer sound effects and scoring.
- Add battery operation for portability.
- Add Bluetooth or Wi‑Fi score sharing using ESP32 features.
- Build a custom enclosure using acrylic or 3D printing.
- Create a mobile or web configuration interface for settings.

## ✅ Advantages

- Low-cost and compact student project.
- Improves embedded programming skills.
- Teaches display control, SPI communication, and input handling.
- Easy to prototype and demonstrate.
- Can be expanded into a multi-game handheld later.

## 📎 Conclusion

The ESP32-Based Smart Mini LED Game Console is a practical and creative embedded systems project. It combines simple hardware with engaging gameplay, making it ideal for students who want to learn microcontroller programming through an interactive and fun build.
# 2. Problem Discovery

# 2.1 Observation Area

## Where did you conduct your observations?

* Hostel
* Home
* College Campus
* Electronics/DIY Project Discussions

---

# 2.2 AEIOU Observation Sheet

## Activities

* Playing simple games on phones or small devices.
* Using buttons or controllers for game input.
* Watching basic LED displays for feedback.
* Selecting games from a simple menu.
* Testing embedded hardware projects.

## Environment

* Small student workspaces.
* Hostels and homes with limited project resources.
* College labs and DIY electronics setups.
* Low-cost prototype environments.
* Places where compact and portable devices are preferred.

## Interactions

* Users interact with buttons and switches.
* Users interact with the LED matrix display.
* Users select games through a menu.
* Users receive visual feedback from the screen.
* Users interact with the device as a small handheld-style console.

## Objects

* ESP32 Development Board
* 8×8 MAX7219 LED Matrix
* Push Buttons
* Buzzer
* Jumper Wires
* Breadboard or Perfboard
* Power Supply or Battery Module

## Users

* Students
* Hobbyist Makers
* Beginner Embedded System Learners
* DIY Electronics Enthusiasts
* Children

---

# 2.3 Observation Log

| Observation                                         | Evidence                                                | Pain Point                                            |
| --------------------------------------------------- | ------------------------------------------------------- | ----------------------------------------------------- |
| Students enjoy simple retro games.                  | Observed during mobile gaming and project discussions.  | Most gaming projects are expensive or overly complex. |
| Compact devices are preferred for student projects. | Seen in hostel and college project setups.              | Large displays and controllers increase cost.         |
| Basic LED modules attract interest.                 | Observed in DIY electronics experiments.                | Full-screen displays are not always necessary.        |
| Users like quick interactive challenges.            | Based on informal project discussions.                  | Many systems do not offer simple gameplay.            |
| Students want affordable embedded projects.         | Repeatedly mentioned in project planning conversations. | High-cost components make prototyping difficult.      |

---

# 3. User Research

## 3.1 Interview Summary

**Number of Users Interviewed:** 5

---

## 3.2 Key Quotes

* “I like small game projects because they are easy to understand.”
* “A compact LED game console would be fun to build.”
* “Big displays make student projects more expensive.”
* “I want something simple but still interactive.”
* “A two-game console would be a good college project.”

---

## 3.3 User Persona

### Aayushi Choudhary

**Age:** 20

**Occupation:** Engineering Student

### Goals

* Build a low-cost game console.
* Learn embedded programming.
* Create an interesting college project.
* Play simple games on a compact device.

### Frustrations

* Expensive hardware parts.
* Complicated project designs.
* Limited experience with embedded systems.
* Difficulty building large display-based games.

### Needs

* Affordable components.
* Simple game logic.
* Easy-to-build circuit.
* Compact and portable design.

---

# 4. Problem Framing

## Problem Statement

Students need a low-cost and simple game console project because many DIY gaming systems are too expensive, too large, or too complex to build using basic electronic components.

---

## How Might We Questions

* How might we create a compact game console using low-cost hardware?
* How might we design simple games that work on a small LED matrix?
* How might we build an engaging embedded project that is easy for students to prototype?

---

## Opportunity Ranking

| Criteria         | Score     |
| ---------------- | --------- |
| Severity         | 4         |
| Frequency        | 4         |
| Feasibility      | 5         |
| Novelty          | 4         |
| Market Potential | 4         |
| **Total**        | **21/25** |

---

# 5. Solution Ideation

## Brainstormed Ideas

| Idea                          | Advantages                 | Challenges                       |
| ----------------------------- | -------------------------- | -------------------------------- |
| Full-Screen Mobile Game App   | Easy to make visually rich | Not an embedded hardware project |
| Arduino LCD Game Console      | Simple and low-cost        | Limited display creativity       |
| Smart Mini LED Game Console   | Affordable and compact     | Needs simplified game design     |
| Bluetooth Controller Game Box | More interactive           | More complex and costly          |

---

## Selected Concept

### Smart Mini LED Game Console

---

## Why Was This Concept Chosen?

* Uses affordable and easily available hardware components.
* Compact and suitable for student-level projects.
* Supports simple but engaging gameplay.
* Can run multiple games on a single device.
* Easy to prototype, test, and demonstrate.
* Helps students learn embedded programming, display control, and user input handling.
* Encourages hands-on learning of ESP32-based system design.

# 6. System Design

## High-Level Description

Explain your solution.

---

## Block Diagram

Insert diagram here.

---

## Inputs

List sensors, user inputs, data sources.

---

## Outputs

List displays, actuators, software outputs.

---

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
