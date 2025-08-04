# 🎓 Digital Electronics 3 — Educational Project Examples (2025)

This repository provides a curated collection of embedded systems examples used in the **Digital Electronics 3** course at FCEFyN. It is designed as a complementary resource to explore low-level programming, HAL abstractions, and platform migration between ARM-based microcontrollers.

---

## 🎯 Project Purpose

The main objectives of this repository are:

- Demonstrate the **contrast between register-level programming and HAL-based development**
- Provide **hands-on examples for each core hardware module** (GPIO, ADC, DAC, UART, timers, etc.)
- **Compare development practices between LPC1769 and STM32 Blue Pill** platforms
- Support the transition from low-level register access to driver abstractions, such as the improved [CMSISv2p00_LPC17xx](https://github.com/David-A-T-M/CMSISv2p00_LPC17xx_Modernized) library
- Encourage students to explore embedded systems across different toolchains and MCUs

---

## 🧱 Repository Organization

Each project includes implementations for both LPC1769 and STM32 platforms, showcasing:

- A **register-level implementation**
- A **HAL-based implementation**
- Platform comparison: same project structure on both microcontrollers

Project directories are split into subfolders for each platform (LPC and STM). Each version shows the same logic implemented using direct register access and using the relevant HAL (either the modernized CMSISv2p00 for LPC or STM32Cube HAL for STM32).

> 🛠️ Toolchains used:
> - **LPC1769**: MCUXpresso IDE
> - **STM32 (Blue Pill)**: STM32CubeIDE  
    > All configuration and project setup files are IDE-managed for ease of replication.

---

## 🔬 Educational Value

This repository is actively used in _Digital Electronics 3 (ED3)_ to teach:

- **Direct register manipulation** for peripheral control
- **Progressive abstraction** using peripheral drivers
- **Code portability and migration** between different ARM Cortex-M3 MCUs
- **Platform-specific design considerations and trade-offs**

---

## ⚙️ Modules Covered

Example projects are continuously added and refined. The current and planned topics include:

- ✅ Blinking LED
- ✅ 7-segment digit auto counter
- 🗓️ External Interrupt
- 🗓️ GPIO Toggling
- 🗓️ Timer with SysTick
- 🗓️ ADC Read + UART Send
- 🗓️ PWM Generation

> 🚧 _In progress._
> 🗓️ _Planned._

---

## 🔗 Related Repository

This repository is meant to be used alongside the improved CMSIS driver library:

📦 [LPC17xx CMSISv2p00 Modernized Driver Library](https://github.com/David-A-T-M/LPC17xx-CMSIS-Driver-Enhancement)  
A modern, tested, and documented refactor of the original NXP CMSIS drivers for LPC176x/5x.

Together, these two repositories provide a complete workflow for both **educational exploration** and **professional embedded firmware development**.

---

## 👨‍🏫 Target Audience

While initially developed for students of **Digital Electronics 3**, the examples are written in a clean, modular style to benefit:

- Students transitioning from PICs to ARM
- Engineers exploring bare-metal development
- Developers comparing STM32 vs. LPC176x approaches
- Anyone learning about peripheral drivers and HAL abstractions

---

## 🤝 Contributions

Feel free to open issues or pull requests to suggest new examples, fix bugs, or improve portability. This project is open to contributions, especially from students who want to enhance their embedded development skills.

---

## 👨‍💻 Author

[David Trujillo Medina](https://github.com/David-A-T-M)

---
