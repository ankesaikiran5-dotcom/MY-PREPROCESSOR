MY PREPROCESSOR

Mini Project Submission Report

Project Title: MY PREPROCESSOR
Programming Language: C
Operating System: Ubuntu Linux
Compiler: GCC
Version Control: Git and GitHub
Repository: https://github.com/ankesakiran5-dotcom/MY-PREPROCESSOR

---

1. ABSTRACT

MY PREPROCESSOR is a C programming mini project that demonstrates basic preprocessing operations performed on C source code before compilation.

The project implements four major functionalities:

1. Comment Removal
2. File Inclusion
3. Object-like Macro Substitution
4. Function-like Macro Substitution

A menu-driven main program allows users to select and execute each functionality independently.

2. INTRODUCTION

The C preprocessor processes source code before the compilation stage. It performs operations such as removing comments, including header files, and expanding macros.

This project demonstrates the basic working principles of these operations through separate C modules connected using a central menu-driven program.

3. OBJECTIVES

- Understand the basic working of a C preprocessor.
- Remove single-line and multi-line comments.
- Demonstrate header file inclusion.
- Perform object-like macro substitution.
- Perform function-like macro substitution.
- Understand file handling in C.
- Develop and test a menu-driven C application.

4. SOFTWARE AND HARDWARE REQUIREMENTS

Software Requirements

- Ubuntu Linux
- GCC Compiler
- C Programming Language
- Git
- GitHub

Hardware Requirements

- Computer or laptop
- Minimum 2 GB RAM
- Keyboard and monitor

5. MODULE DESCRIPTION

5.1 Comment Removal

Source file: "comment_removal.c"

This module reads a C source file named "input.c" and removes single-line and multi-line comments.

The processed source code is stored in "clean.i".

5.2 File Inclusion

Source file: "file_inclusion.c"

This module reads "input1.c", identifies quoted header file inclusion statements, and copies the header file contents into the output.

The processed code is stored in "output.i".

5.3 Object-like Macro Substitution

Source file: "macro_substitution.c"

This module identifies object-like macro definitions using "#define".

It stores macro names and corresponding values and replaces matching identifiers in the source code.

The processed result is stored in "output1.i".

5.4 Function-like Macro Substitution

Source file: "function_macro.c"

This module accepts a function-like macro definition and an input expression from the user.

It identifies formal and actual arguments and substitutes the actual arguments into the replacement expression.

The expanded expression is displayed on the terminal.

6. MENU-DRIVEN MAIN PROGRAM

Source file: "main.c"

The main program connects all four modules through a menu-driven interface.

The user can select:

1. Comment Removal
2. File Inclusion
3. Object-like Macro Substitution
4. Function-like Macro Substitution

Based on the selected option, the corresponding function is executed.

7. PROJECT WORKFLOW

1. Start the application.
2. Display the main menu.
3. Select the required preprocessing operation.
4. Execute the selected module.
5. Read the required input file or keyboard input.
6. Perform the preprocessing operation.
7. Generate the output file or display the expanded expression.
8. Return to the terminal.

Each module currently operates independently using its own input and output.

8. COMPILATION AND EXECUTION

Compile all modules together using:

gcc main.c comment_removal.c file_inclusion.c macro_substitution.c function_macro.c -o my_preprocessor

Execute the application:

./my_preprocessor

9. TESTING AND RESULTS

All four modules were compiled and executed individually.

The integrated application was also compiled successfully and tested through its menu.

Test| Result
Comment Removal| Passed
File Inclusion| Passed
Object-like Macro Substitution| Passed
Function-like Macro Substitution| Passed
Integrated compilation| Passed
Menu execution| Passed

The generated "output.i" file was also compiled and executed successfully using GCC.

10. ADVANTAGES

- Demonstrates important C preprocessing concepts.
- Uses modular programming.
- Provides a simple menu-driven interface.
- Demonstrates file handling operations.
- Helps understand macro expansion and header inclusion.

11. APPLICATIONS

- Learning C programming concepts.
- Understanding preprocessing operations.
- Practicing file handling.
- Understanding macro substitution.
- Learning modular program development.

12. FUTURE ENHANCEMENTS

- Integrate all preprocessing stages into a single automatic pipeline.
- Support additional preprocessing directives.
- Improve error handling.
- Support more complex macro expressions.
- Improve header file inclusion capabilities.

13. CONCLUSION

The MY PREPROCESSOR project successfully demonstrates four basic preprocessing functionalities using C programming.

The four modules were developed and tested independently and connected through a menu-driven main program.

This project provides practical knowledge of C preprocessing concepts, file handling, functions, and modular programming.

14. GITHUB REPOSITORY

Project source code and documentation are available at:

https://github.com/ankesakiran5-dotcom/MY-PREPROCESSOR
