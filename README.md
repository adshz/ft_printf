# ft_printf

## Introduction
Following the [42cursus](https://42.fr/en/cursus/web-development-school/) curriculum, we must implement the `printf` function in C. This may sounds like a nonsense project, but the philosophy at 42 London is "If you need to use it, you must build it yourself". It is difficult to convey the Why to a person who has not been through the experience, but the project is not only a good exercise in understanding the C language and the `printf` function, but also a training on rigour and resiliance when you are doing something that you don't know.

Through this project, I have learned a lot about the C language and varidic argument as well as the data structure Struct in C programming. 

## Usage

### Installation

```
git clone https://github.com/adshz/ft_printf.git
```

### Project Setup

```bash
cd ft_printf    
make
```

You would need to create the main program `main.c` inside the `./src` directory to use the `ft_printf` function. Here is an example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, World!\n");
    return (0);
}
```

### Compilation

```bash
gcc main.c libftprintf.a && ./a.out
```

the output should be:

```
Hello, World!
``` 

## Format Examples
The project supports the following flags:
- `%c` for a single character
- `%s` for a string of characters
- `%d` and `%i` for integers
- `%u` for unsigned integers
- `%x` and `%X` for hexadecimal integers
- `%%` for the `%` character itself

### Basic Format Specifiers
```c
ft_printf("Number: %d\n", 42);           // Output: Number: 42
ft_printf("String: %s\n", "hello");      // Output: String: hello
ft_printf("Char: %c\n", 'A');            // Output: Char: A
ft_printf("Hex lower: %x\n", 255);       // Output: Hex lower: ff
ft_printf("Hex upper: %X\n", 255);       // Output: Hex upper: FF
ft_printf("Unsigned: %u\n", 4294967295); // Output: Unsigned: 4294967295
ft_printf("Percent: %%\n");              // Output: Percent: %
```

## Advanced Usage:  Format Specifiers

`ft_printf` supports format specifiers as follows:

### Flags

- `-` - left alignment
- `0` - padding with zeros
- `.` - precision
- `*` - width   

### Width
- `(number)` - the field minimum width
- `*` - the width is given in the argument list (only works with the `%*s` and `%*d` format specifiers)


### Advanced Examples
#### Width and Alignment
```c
// Right-aligned (default)
ft_printf("|%10s|\n", "hello");     // Output: |     hello|
ft_printf("|%10d|\n", 42);          // Output: |        42|

// Left-aligned with '-' flag
ft_printf("|%-10s|\n", "hello");    // Output: |hello     |
ft_printf("|%-10d|\n", 42);         // Output: |42        |
```

#### Zero Padding
```c
ft_printf("%05d\n", 42);            // Output: 00042
ft_printf("%07d\n", -42);           // Output: -000042
ft_printf("%08x\n", 255);           // Output: 000000ff
```

#### Width with Star *
```c
ft_printf("|%*s|\n", 10, "hello");  // Output: |     hello|
ft_printf("|%*d|\n", 5, 42);        // Output: |   42|
```


### Precision
- `.` - precision (only works with the `%.*s` and `%.*d` format specifiers)
- `.(*)` - the precision is given in the argument list (only works with the `%*.*s` and `%*.*d` format specifiers)

as for the project, I have designed it in a way to manage any combinations, except for the `.precisions` flags



#### Multiple Formats
```c
ft_printf("Hi %s, you are %d years old and have %X points\n", 
          "John", 25, 255);
// Output: Hi John, you are 25 years old and have FF points

ft_printf("Hex: %#x, Decimal: %d, Char: %c\n", 
          255, 42, 'Z');
// Output: Hex: ff, Decimal: 42, Char: Z
```

#### Combined Flags
```c
ft_printf("|%-10.5s|\n", "hello world");  // Output: |hello     |
ft_printf("|%010d|\n", -42);              // Output: |-000000042|
ft_printf("|%-#8X|\n", 255);              // Output: |FF      |
```


## Status
![](https://i.imgur.com/rTaP3JM.png)

- [x] Mandatory part
- [x] Bonus part
- [X] Norminette



## Implementation Details
The project is implemented using:
- Variadic functions to handle multiple arguments
- Custom parsing for format specifiers
- Modular design with separate handlers for each format type
- Struct-based flag management


---
Made by [szhong](szhong@student.42london.com)

I am writing this README in the process of learning, so if you have any suggestions or find any issues, please let me know. You can reach me via:
- LinkedIn: [@szhong](https://www.linkedin.com/in/shenghongzhong/) 
- X: [@amzdsz](https://x.com/amzdsz) 


I am writing newsletter about career change from Data Analyst to Software Engineering, Building products with A.I, if you are interested, please [![Subscribe to Newsletter](https://img.shields.io/badge/Subscribe-Newsletter-blue)](https://amazingdavid.substack.com/)
