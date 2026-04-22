# Corner Grocer Grocery Tracker

## Project Overview

This project is a C++ program designed to analyze grocery purchase data for the Corner Grocer. The program reads a text file containing a list of items purchased throughout the day and calculates how frequently each item appears.

The goal of this program is to help the store make informed decisions about product placement by identifying which items are purchased most often.

---

## Problem Being Solved

The Corner Grocer collects purchase data in a simple text format but lacks a system to analyze it. Without frequency data, the store cannot efficiently organize its produce section.

This program solves that problem by:
- Counting how often each item appears
- Allowing quick lookup of specific item frequencies
- Displaying data in both numeric and visual (histogram) formats
- Creating a backup file for persistent storage

---

## Features

- Search for the frequency of a specific grocery item
- Display all grocery items with their purchase counts
- Display a histogram using asterisks
- Automatically create a backup file (`frequency.dat`)
- Input validation to prevent invalid user entries
- Case-insensitive item searching

---

## Technologies Used

- C++
- Standard Library (`<map>`, `<fstream>`, `<string>`)
- Object-Oriented Programming
- File Input/Output
- Modular multi-file architecture

---

## Project Structure
main.cpp -> Controls program flow
GroceryTracker.h/.cpp -> Handles data processing and storage
Menu.h/.cpp -> Handles user interaction and validation
FileConstants.h -> Stores constant values

---

## Reflection

### What did I do particularly well?

I structured the program in a modular way using multiple files and separated concerns between user interface and data processing. The use of a class with a private map allowed for clean data management and reusable functionality.

---

### Where could I enhance my code?

I could improve the program by:
- Adding sorting options (e.g., highest frequency first)
- Improving the histogram formatting
- Adding error logging instead of simple console messages
- Supporting larger datasets with more efficient data handling

These improvements would make the program more scalable and closer to production-level software.

---

### What was most challenging?

The most challenging part was managing file input and ensuring that data was correctly processed into the map. I also found input validation tricky, especially preventing invalid menu input from breaking the program.

I overcame these challenges by:
- Breaking the problem into smaller steps
- Testing incrementally
- Reviewing documentation for `std::map` and file handling

---

### What tools or resources did I use?

- Course materials and zyBooks
- C++ documentation
- Debugging tools in Visual Studio

Going forward, I plan to continue using documentation and debugging tools to strengthen my problem-solving process.

---

### What skills are transferable?

This project strengthened several important skills:
- File handling in C++
- Data structures (maps)
- Object-oriented design
- Input validation and error handling
- Writing clean, modular code

These skills are directly applicable to future programming projects and coursework.

---

### How did I make the program maintainable and readable?

I improved maintainability by:
- Separating code into multiple files
- Using clear and descriptive function names
- Adding comments where needed
- Centralizing constants
- Avoiding global variables

This makes the program easier to understand, modify, and extend.

---

## How to Run the Program

1. Compile all `.cpp` files together
2. Ensure the input file is in the same directory:
   CS210_Project_Three_Input_File.txt
3. Run the program
4. Use the menu to interact with the system

---

## Author

Tristin Claus
---

## AI Usage Disclosure

This project was developed with the assistance of AI tools to support learning, code structure, and documentation refinement. All final code and explanations were reviewed and understood before submission.
