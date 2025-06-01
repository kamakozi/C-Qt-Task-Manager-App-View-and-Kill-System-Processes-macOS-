# C++ Qt Task Manager App – View and Kill System Processes (macOS)

A modern system-level task manager app built using **C++17**, **Qt6**, and **macOS sysctl** system calls. Displays all running processes with PID and name, and allows you to stop (kill) them directly from the GUI.

---
## 📽️ Demo

[▶️ Watch Demo Video](demo.mp4)

##  Features

-  **Live Process Fetching** using `sysctl` (macOS-specific)
-  **Qt6 GUI** with QTableWidget for display
-  **Smart Pointer (unique_ptr)** usage for memory safety
-  **Process Kill** with `kill(pid, SIGKILL)` on button press
-  **Clean MVC-like Architecture**
-  **Error logging** to `Logs.txt` for sysctl failures
-  **macOS ARM64 compatible**
-  **Search/filter for process names**

---

##  Interface Preview

- PID | Process Name | [Stop] Button
- Dark-themed layout
- Kill process instantly from GUI

---

##  Architecture

```
taskmanager/
├── FrontEnd/
│   └── MainWindow.cpp / MainWindow.hpp
├── BackEnd/
│   ├── GetProcesses/
│   │   └── GetProcesses.cpp / .h
│   ├── Processes/
│   │   └── Proceses.cpp / .h
│   └── TaskManager.h
├── main.cpp
├── CMakeLists.txt
```

---

##  Build Instructions (macOS with Qt6)

### 1. Install Dependencies

```bash
brew install qt
```

### 2. Link Qt if needed

```bash
brew link --overwrite --force qt
```

### 3. Build & Run

```bash
cmake -B build -S .
cmake --build build
./build/taskmanager
```

---

##  Next Goals

-  Auto-refresh process list
-  Double-click row for more task details (CPU%, Memory)
-  Add unit tests

---

##  Built With

- [C++17](https://en.cppreference.com/)
- [Qt6](https://www.qt.io/)
- [macOS sysctl API](https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/sysctl.3.html)
- CMake

---
