MY PREPROCESSOR PROJECT

1. Introduction

A C preprocessor performs operations on source code before the actual compilation process. This project demonstrates basic preprocessing operations using C programming.

2. Objectives

- Understand the basic working of a C preprocessor.
- Remove comments from source code.
- Handle file inclusion.
- Perform macro substitution.
- Process function-like macros.

3. Technologies Used

- Programming Language: C
- Operating System: Ubuntu Linux
- Compiler: GCC
- Version Control: Git and GitHub

4. Project Modules

4.1 Comment Removal

This module removes single-line and multi-line comments from a C source file.

4.2 File Inclusion

This module demonstrates header file inclusion by processing the required header file content.

4.3 Macro Substitution

This module replaces object-like macros with their corresponding values.

4.4 Function-like Macro Substitution

This module demonstrates the replacement of function-like macros with their expanded expressions.

5. Project Workflow

1. Provide a C source file as input.
2. Process the source code using the required preprocessing module.
3. Generate the processed output.
4. Save the result in an ".i" file.
5. Compile the generated output using GCC to test it.
6. The user selects the required preprocessing operation through the menu-driven main program.

6. Compilation and Execution

Example commands:

gcc -x c output.i -o final
./final

The generated preprocessed file can be compiled and executed to verify the output.

7. Testing

The project includes separate input files and generated output files for testing the preprocessing functionalities.

8. Conclusion

This project provides practical understanding of basic C preprocessing operations, including comment removal, file inclusion, object-like macro substitution, and function-like macro substitution.

9. Future Enhancements

- Integrate all preprocessing modules into a single program.
- Improve error handling.
- Support more complex preprocessing directives.
