# Introduction

## 1. Compiled Languages and C++
### 1.1 Why Use a Language Like C++?

At its core, a computer is just a processor with some memory, capable of running tiny instructions like “store 5 in memory location 23459.” Why would we express a program as a text file in a programming language, instead of writing processor instructions?

The advantages:

1. <b>Conciseness:</b> programming languages allow us to express common sequences of commands more concisely. C++ provides some especially powerful shorthands.

2. <b>Maintainability:</b> modifying codeis easier whenit entailsjust afew text edits,instead of rearranging hundreds of processor instructions. C++ is *object oriented* (more on that in Lectures 7-8), which further improves maintainability.

3. <b>Portability:</b> differentprocessors makedifferentinstructions available. Programs written as text can be translated into instructions for many different processors; one of 

C++ is a *high-level* language: when you write a program in it,the shorthands are sufficiently expressive that you don’t need to worry about the details of processor instructions. C++ does give access to some lower-level functionality than other languages(e.g. memory addresses).

### 1.2 The Compilation Process
A program goes from text files (or *source files*) to processor instructions as follows:

![image](https://user-images.githubusercontent.com/85934122/221882777-d044bb9f-c95c-4372-818f-4b95d0247a78.png)

Object files are intermediate files that represent an incomplete copy of the program: each source file only expresses a piece of the program, so when it is compiled into an object file, the object file has some markers indicating which missing pieces it depends on. The linker takes those object files and the compiled libraries of predefined code that they rely on, fills in all the gaps, and spits out the final program, which can then be run by the operating system(OS).

The compiler and linker are just regular programs. The step in the compilation process in which the compiler reads the file is called *parsing*.

In C++, all these steps are performed ahead of time, before you start running a program. In some languages, they are done during the execution process, which takes time. This is one of the reasons C++ code runs far faster than code in many more recent languages.

C++ actually adds an extra step to the compilation process: the code is run through a preprocessor, which applies some modifications to the source code, before being fed to the compiler. Thus, the modified diagram is:

![image](https://user-images.githubusercontent.com/85934122/221883441-5577b9c2-f301-42fb-9c47-1d7a6c856ef0.png)

### 1.3 General Notes on C++
C++ is immensely popular, particularly for applications that require speed and/or access to some low-level features. It was created in 1979 by Bjarne Stroustrup, at first as a set of extensions to the C programming language. C++ extends C; our first few lectures will basically be on the C parts of the language.

Though you can write graphical programs in C++,it is much hairier and less portable than text-based (*console*) programs. We will be sticking to console programs in this course.

Everything in C++ is case sensitive: `someName` is not the same as `SomeName`.

## 1. Hello World

In the tradition of programmers everywhere, we’ll usea “Hello,world!” program as an entry point into the basic features of C++.

### 2.1 The code
```c
// A Hello World program
#include <iostream>

int main() {
  std::cout << "Hello, world!\n";

  return 0;
}
```

### 2.2 Tokens

Tokens are the minimals chunk of program that have meaning to the compiler –the smallest meaningful symbols in the language. Our code displays all 6 kinds of tokens, though the usual use of operators is not present here:

| Token type | Description/Purpose | Examples |
| :---         |     :---      |          :--- |
| Keywords   | Words with special meaning to the compiler     | int, double, for, auto    |
| Identifiers     | Names of things that are not built into the language       | cout, std, x, myFunction      |
| Literals     | Basic constant values whose value is specified directly in the source code       | "Hello, world!", 24.3, 0, ’c’      |
| Operators     | Mathematical or logical operations       | +, -, &&, %, <<      |
| Punctuation/Separators     | Punctuation defining the structure of a program       | { } ( ) , ;      |
| Whitespace     | Spaces of various sorts; ignored by the compiler       | Spaces, tabs, newlines, comments      |

### 2.3 Line-By-Line Explanation

1. // indicates that everything following it until the end of the line is a comment: it is ignoredby thecompiler. Anotherway towriteacommentistoputitbetween /* and */ (e.g. x = 1 + /*sneaky comment here*/ 1;). A comment of this form may span multiple lines. Comments exist to explain non-obvious things going on in the code. Use them: document your code well!

2. Lines beginning with # are preprocessor commands, which usually change what code is actually being compiled. #include tells thepreprocessor to dump in the contents of another file, here the iostream file, which defines the procedures for input/output.

3. int main() {...}defines the code that should execute when the program starts up. The curly braces represent grouping of multiple commands into a block. More about this syntax in the next few lectures.
4. • cout << : This is the syntax for outputting some piece of text to the screen. We’ll discuss how it works in Lecture 9.

   • **Namespaces:** In C++, identifiers can be defined within a context – sort of a directory of names – called a namespace. When we want to access an identifier definedin a namespace, we tell the compiler tolookforitin that namespace using the scope resolution operator (::). Here, we’re telling the compiler to look for cout in the std namespace, in which many standard C++ identifiers are defined.

    A cleaner alternative is to add the following line below line 2:
  ```c++
  using namespace std;
  ```
  <br> 
    This line tells the compiler that it should look in the std namespace for any identifier we haven’t defined. If we do this, we can omit the std:: prefix when writing cout. This is the recommended practice.
    
   • **Strings:** A sequence of characters such as Hello, world isknown as a string.A string that is specified explicitly in a program is a string literal.
   
   • **Escape sequences:** The \n indicates a newline character. Itis an example of an escape sequence – a symbol used to represent a special character in a text literal. Here are all the C++ escape sequences which you can include in strings:
| Escape Sequence | Represented Character | 
| :---:         |     :---      |         
| \a   | System bell (beep sound)     | 
| \b     | Backspace       | 
| \f     | Formfeed (page break)       | 
| \n     | Newline (line break)       | 
| \r     | “Carriage return” (returns cursor to start of line)       | 
| \t     | Tab       | 
| \\     | Backslash       | 
| \’     | Single quote character       | 
| \"     | Double quote character       | 
| \some integer x     | The character represented by x       | 

5. return 0 indicates that theprogram should tell the operating systemithas completed successfully. Thissyntax willbeexplainedinthecontext offunctions;fornow,just include it as the last line in the main block.

Note that every statement ends with a semicolon(exceptpreprocessor commands andblocks using {}). Forgetting these semicolonsis a common mistake among newC++programmers.
