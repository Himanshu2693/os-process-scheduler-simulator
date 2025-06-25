# 🖥️ OS Process Scheduler Simulator

A C++ console-based simulator for classic CPU scheduling algorithms with Gantt chart visualization and file I/O support.

## 🚀 Features

- ✅ FCFS (First-Come First-Served)
- ✅ SJF (Shortest Job First – Non-Preemptive)
- ✅ Priority Scheduling (Non-Preemptive)
- ✅ Round Robin Scheduling
- ✅ Gantt Chart representation in console
- ✅ File-based input/output support

---

## 🧠 Algorithms Simulated

| Algorithm        | Preemption | Priority Support | Use Case                             |
|------------------|------------|------------------|---------------------------------------|
| FCFS             | No         | No               | Basic job queue                       |
| SJF              | No         | No               | Efficient batch processing            |
| Priority         | No         | ✅ Yes           | Time-sensitive tasks                  |
| Round Robin      | ✅ Yes     | No               | Time-sharing systems, multitasking    |

---

## 📁 Folder Structure

OS Process Scheduler Simulator/
├── bin/ # Compiled output (.exe)
├── data/
│ ├── input.txt # Input file for processes
│ └── output.txt # Output file (auto-generated)
├── src/
│ ├── main.cpp
│ ├── scheduler.cpp
│ ├── scheduler.h
│ ├── utils.cpp
├── .gitignore
├── README.md



## 📥 Input Format (`data/input.txt`)

Each line = `ArrivalTime BurstTime Priority`

0 5 2
1 3 1
2 8 3
3 6 2


## 🧪 Build & Run (Windows)

g++ .\src\main.cpp .\src\scheduler.cpp .\src\utils.cpp -o .\bin\scheduler.exe
.\bin\scheduler.exe
💡 Requires g++ (MinGW or similar)

📤 Output
Console output: Gantt chart and turnaround/waiting times

File output: Written to data/output.txt

