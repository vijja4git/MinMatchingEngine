# Mini Matching Engine

A lightweight C++ implementation of a basic **limit order book matching engine** — simulating core mechanics used by exchanges and trading platforms. Built as a personal project to explore how financial markets match buy/sell orders with **price-time priority**, inspired by real-world systems at firms like Susquehanna.

---

## 📌 Features

- Handles **BUY/SELL limit orders** with FIFO logic for matching
- Simulates **market microstructure** concepts:
  - Price-time priority
  - Partial fills
  - Trade execution reporting
- Clean, modular C++ code with STL (`map`, `queue`)
- Extensible design: cancel/replace logic and concurrency can be added later

---

## 🧠 Why This Project?

This project was built to:
- Learn and implement the **core logic behind exchange engines**
- Understand how **trading systems prioritize latency, determinism, and fairness**
- Showcase C++ systems design skills for roles in **quant trading and low-latency development**

---

## 🛠 Technologies

- **C++17**
- **CMake** (build system)
- **STL containers**: `map`, `queue`
- Tested and compiled with `g++` on macOS

---

## 📂 Folder Structure
