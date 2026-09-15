# PublicPulse SA System

 C++ infrastructure management system designed to simulate how municipalities can efficiently report, track, prioritise, and manage public infrastructure maintenance using fundamental data structures and algorithms.

---

# Authors

**Group Project**

Developed as part of the **Introduction to Data Structures** module.

**Repository maintained by:**  
**Unathi Spele**

---

# Getting Started

## Prerequisites

Before running the project, ensure you have:

- A C++17 compatible compiler (GCC, Clang, or Microsoft Visual Studio)
- CMake *(optional if using an IDE)*
- Any C++ IDE such as:
  - Visual Studio
  - Code::Blocks
  - CLion
  - VS Code

Verify your compiler installation:

```bash
g++ --version
```

---

## Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/PUBLICPULSE-SA-System.git
```

Navigate into the project folder:

```bash
cd PUBLICPULSE-SA-System
```

---

## Compile

Using g++:

```bash
g++ *.cpp -o PublicPulse
```

---

## Run

Windows

```bash
PublicPulse.exe
```

Linux/macOS

```bash
./PublicPulse
```

---

# Overview

PublicPulse SA System is a C++ application that simulates a municipal infrastructure maintenance platform designed to improve the reporting and management of public infrastructure faults across South Africa.

The project focuses primarily on potholes and road damage as a practical case study while demonstrating how classic data structures and algorithms can be applied to solve real-world service delivery challenges.

Citizens can submit infrastructure reports, monitor repair progress, and avoid duplicate submissions, while administrators can prioritise repairs, assign maintenance teams, analyse infrastructure trends, and manage completed maintenance records.

The primary objective of this project is to demonstrate how software engineering principles and data structures can be applied to improve municipal accountability and infrastructure maintenance.

---

# Features

## Citizen Portal

- Submit infrastructure fault reports
- Report potholes, road cracks, pipe bursts, and other infrastructure issues
- Prevent duplicate report submissions
- View pending reports
- Track completed repairs
- Sort reports by severity
- Search existing reports

---

## Administrator Portal

- Password-protected administrator login
- Review incoming reports
- Assign maintenance teams
- Update repair progress
- Mark reports as completed
- Search reports
- Analyse completed repairs
- Generate organised repair records

---

# Data Structures & Algorithms

The project demonstrates the practical application of several fundamental data structures and algorithms commonly taught in introductory computer science courses.

| Data Structure / Algorithm | Purpose |
|----------------------------|---------|
| Arrays | Store collections of infrastructure reports |
| Queue | Manage pending repair requests using FIFO scheduling |
| Doubly Linked List | Store completed repair records |
| Stack | Undo recently assigned repair actions |
| Binary Search Tree | Organise and analyse reports by severity |
| Bubble Sort | Sort reports by severity |
| Insertion Sort | Efficient sorting for partially sorted reports |
| Selection Sort | Demonstrates comparison-based sorting |
| Shell Sort | Improved sorting performance for larger datasets |
| Linear Search | Search reports using Report ID |
| Binary Search | Search reports by severity level |
| Tree Traversals | Inorder, Preorder and Postorder analysis |

---

# System Workflow

```
Citizen

      │

      ▼

Submit Infrastructure Report

      │

      ▼

Duplicate Report Detection

      │

      ▼

Pending Report Queue

      │

      ▼

Administrator Review

      │

      ▼

Assign Repair Team

      │

      ▼

Repair Completed

      │

      ▼

Completed Repairs List

      │

      ▼

Severity Analysis using BST
```

---

# Real-World Impact

Public infrastructure plays a critical role in transportation, public safety, and economic development.

PublicPulse SA demonstrates how software systems can improve communication between citizens and municipalities by:

- Encouraging public participation
- Reducing duplicate reports
- Prioritising critical repairs
- Improving service delivery accountability
- Supporting proactive infrastructure maintenance through organised data management

Although this implementation focuses on potholes and road damage, the underlying architecture could easily be extended to support additional municipal services such as:

- Water leaks
- Electricity faults
- Streetlight maintenance
- Waste collection
- Drainage issues
- Sidewalk damage

---

# Technologies Used

| Technology | Purpose |
|------------|----------|
| C++ | Core programming language |
| Object-Oriented Programming | Software design |
| Structs & Classes | Data modelling |
| Queues | Pending report management |
| Stacks | Undo functionality |
| Doubly Linked Lists | Completed repairs |
| Binary Search Trees | Severity analysis |
| Sorting Algorithms | Report prioritisation |
| Searching Algorithms | Efficient report retrieval |

---

# Learning Outcomes

This project strengthened our understanding of:

- Object-Oriented Programming
- Dynamic Memory Management
- Data Structures
- Searching Algorithms
- Sorting Algorithms
- Binary Search Trees
- Queue Management
- Linked Lists
- Tree Traversals
- Modular Software Design
- Team Collaboration
- Problem Solving

---

# Future Improvements

Potential future enhancements include:

- Database integration
- User authentication
- GPS location reporting
- Image uploads for reported faults
- Interactive map integration
- Municipal analytics dashboard
- Email notifications
- SMS repair updates
- Mobile application
- REST API
- Cloud deployment
- Machine learning for predictive maintenance
- Repair scheduling optimisation
- Real-time reporting statistics

---

# Contributing

This project was developed as an academic group project.

Suggestions and improvements are always welcome.

If you would like to contribute:

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Submit a Pull Request

---

# License

This project is licensed under the MIT License.

You are free to use, modify, and distribute this software provided that the original copyright notice and license are retained.

---

# Repository Maintainer

**Unathi Spele**

BSc Mathematical and Computer Science Student  
Sol Plaatje University

Interested in:

- Financial Technology (FinTech)
- Software Engineering
- Backend Development
- Data Structures & Algorithms
- C++ Development
- Mobile Application Development

---

## Support

If you found this project interesting or useful, consider giving the repository a **Star**.
