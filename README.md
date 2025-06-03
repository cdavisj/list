# Doubly Linked List Implementation

A template-based C++ implementation of a doubly linked list data structure with comprehensive test coverage.

## Prerequisites

- C++ compiler with C++11 support (g++ recommended)
- Make build system
- Catch2 testing framework (included in `lib/catch.hpp`)

## Project Structure

```
.
├── list.h              # Main list implementation (header-only)
├── lib/
│   └── catch.hpp       # Catch2 testing framework
├── tests/
│   └── test_list.cpp   # Test suite
├── Makefile           # Build configuration
└── README.md          # This file
```

## Building and Running Tests

1. Build and run the tests:
   ```bash
   make
   ```

2. To clean build artifacts:
   ```bash
   make clean
   ```

## Usage

The list implementation is header-only, so you can simply include `list.h` in your project:

```cpp
#include "list.h"

int main() {
    list<int> myList;           // Create an empty list
    myList.push_back(42);       // Add elements
    myList.push_front(10);
    
    int front = myList.front(); // Access elements
    int back = myList.back();
    
    myList.pop_back();          // Remove elements
    myList.clear();             // Clear the list
    
    return 0;
}
```

## Features

- Template-based implementation supporting any data type
- Doubly linked list with O(1) insertions at front and back
- Comprehensive test coverage using Catch2
- Memory-safe implementation with proper cleanup

## Available Operations

- `push_back()`: Add element to end of list
- `push_front()`: Add element to front of list
- `pop_back()`: Remove and return last element
- `pop_front()`: Remove and return first element
- `front()`: Access first element
- `back()`: Access last element
- `clear()`: Remove all elements
- `size()`: Get number of elements
- `empty()`: Check if list is empty
- `resize()`: Change size of list
- `reverse()`: Reverse order of elements
- `print()`: Display list contents forward
- `print_reverse()`: Display list contents backward