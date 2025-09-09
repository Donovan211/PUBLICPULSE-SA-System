# PUBLICPULSE-SA-System

Tracking and Maintenance of public infrastructure - Pothole & Road Damage Maintenance Planner

## Overview:

A C++ program designed to address issues with public infrastructure in South Africa by utilizing Tracking and maintenance feedback, designed to allow citizens to easily report and keep track of repair progress. The system ensures accountability by utilizing data structures to efficiently log, categorize and prioritize repair tasks through real-world problems. Ultimately, it empowers municipalities by preventing further breakdowns by implementing predictive analytics. Since the topic regarding infrustructure is embiguous, the code mainly focuses on pothole and road damage maintanance.

## Key Features:

### User Portal
- Submit fault reports (potholes, cracks, pipe bursts, etc.)
- Prevent duplicate submissions by checking existing reports
- View pending and completed report statuses
- Sort reports by severity using different sorting algorithms:
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Shell Sort
- Search reports:
  - **Linear Search** by Report ID
  - **Binary Search** by Severity Level

### Admin Portal
- Secure login with password protection
- Assign repair teams to pending reports
- Mark reports as completed
- View and manage completed repairs (Doubly Linked List)
- Analyze reports by severity using **Binary Tree Traversals**:
  - Inorder (Low → High severity)
  - Preorder
  - Postorder
- Search reports from the admin side as well

## Data Structures and Algorithms: (Uses throughout the program)

Arrays-
Doubly Linked List- Completed repairs tracking 
Queues- Pending pothole/fault reports
Stack- undpo functionality ( last assigned reports)
Binary Search Trees- organizing and analyzing completed reports by severity
Sorting Algorithms- Bubble, Insertion, Selection, Shell
Searching Algorithms-  Linear and Binary Search


## Real World Impact:

The system is ultimately used to improve municipal service accountability and ensure that citizens keep track of repairs by supporting proactive infrastructure maintenance.


## Technology:

- Language: C++
- Concepts: Structs, Classes, Recursion, Linked Lists, Queues, Stacks, Trees, Searching & Sorting Algorithms.

