
# Preprocessors. Header files and Header guards

## Preprocessors
- The <b>preprocessor</b> is best thought of as a separate program that manipulates the text in each code file.

### Preprocessor directives:
- instructions that start with a # symbol and end with a newline (NOT a semicolon);
- tell the preprocessor to perform specific particular text manipulation tasks.

### Includes (#include)

### Macro defines (#define)
- Object-like macros with substitution text;
- Object-like macros without substitution text;
- Function-like macros.

### Conditional compilation
- <b>#ifdef
- <b>#ifndef
- <b>#endif
- <b>#if 0
```
#include <iostream>

#define PRINT_JOE

int  main() {

#ifdef PRINT_JOE
	std::cout  <<  "Joe\n";  // if PRINT_JOE is defined, compile this code
#endif

#ifdef PRINT_BOB
	std::cout  <<  "Bob\n";  // if PRINT_BOB is defined, compile this code
#endif

	return  0;
}
```

- Object-like macros don’t affect other preprocessor directives
- The scope of defines

##
##  Header files

### Headers, and their purpose:
- Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing in multi-file programs.
- Using standard library header files.
- Header files typically only contain function and variable declarations, not function and variable definitions.
- When writing a source file, include the corresponding header (If one exists), even if you don’t need it yet.

### Angled brackets vs double quotes

### Including header files from other directories

### Headers may include other headers
- Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.

### The #include order of header files
- Order your #includes as follows: your own user-defined headers first, then 3rd party library headers, then standard library headers, with the headers in each section sorted alphabetically.

##
## Header guards

### The duplicate definition problem

### Header guards (Include guards):
```
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
	// your declarations (and certain types of definitions) here
#endif
```

### #pragma once

#
# Задачи:

### Задача 1:
Дефинирайте структурата DynArray, която има size, capacity и динамичен масив от тип int. Декларирайте следните функции към структурата в header файл и напишете дефинициите им в source файл:

- create() - създава структурата с подходящ капацитет;
- push_back() - добавя елемент в края на масива;
- resize() - помощна функция за преоразмеряване на масива;
- pop_back() - премахва елемент от края на масива;
- get() - взима елемент по подаден индекс;
- remove() - премахва елемент на подаден индекс;
- map() - функция от по-висок ред, която приема друга функция като параметър и променя всички елементи в масива спрямо нея;
- filter() - функция от по-висок ред, която приема друга функция като параметър и филтрира само елемнтите, които отговарят на нея;