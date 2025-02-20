# CPSC237-Project2
# Circular Linked List Implementation

## Overview
This project implements a **templated Circular Linked List (CLinkedList)** in C++, supporting ordered insertion, removal, deep copy, backward printing, and iteration. The project also includes a **menu-driven test program** allowing users to interact with the list.

## Features
- **Templated Circular Linked List** (`CLinkedList.h`)
  - Supports ordered insertion and removal
  - Allows deep copying
  - Provides backward printing functionality
- **Iterator for Traversal** (`ListIterator.h`)
- **Node Class Definition** (`Node.h`)
- **Interactive Test Program** (`testLL.cpp`)
  - Provides a menu for inserting, removing, and displaying the list
- **Additional Implementations**
  - `LinkedList.h`: Alternative singly linked list implementation
  - `Application.cpp`: Tests template ordered linked list operations

## Usage
### Compilation
To compile the project, use the provided **Makefile**:
```bash
make
```
This will generate an executable named `testll`.

### Running the Program
Run the interactive test program with:
```bash
./testll
```
### Interactive Menu Options
Upon running, the program provides a menu:
```
I)nsert Integer
R)emove Integer
F)orward Print
B)ackward Print
E)xit
```
Users can input letters (case-insensitive) to interact with the list.

### Cleaning Up
To remove compiled files:
```bash
make clean
```

## Code Structure
- `CLinkedList.h` - Defines the Circular Linked List class.
- `LinkedList.h` - Defines an alternative Linked List.
- `ListIterator.h` - Iterator class for traversing a linked list.
- `Node.h` - Node class definition.
- `Application.cpp` - Tests LinkedList functionality.
- `testLL.cpp` - Interactive program for testing CLinkedList.
- `script.txt` - Sample input script for testing.
- `makefile` - Compilation and cleanup rules.

## Error Handling
- Ensures **valid input handling** in interactive mode.
- Handles **empty list cases** for printing and removal.
- Provides **deep copy operations** to prevent data loss.

## Author
- **Justin Allen**
