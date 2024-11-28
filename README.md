# ft_printf

## Introduction
Following the [42cursus](https://42.fr/en/cursus/web-development-school/) curriculum, we must implement the `printf` function in C. This may sounds like a nonsense project, but the philosophy at 42 London is "If you need to use it, you must build it yourself". It is difficult to convey the Why to a person who has not been through the experience, but the project is not only a good exercise in understanding the C language and the `printf` function, but also a training on rigour and resiliance when you are doing something that you don't know.

Through this project, I have learned a lot about the C language and varidic argument as well as the data structure Struct in C programming. 

## Usage
The project supports the following flags:
- `%c` for a single character
- `%s` for a string of characters
- `%d` and `%i` for integers
- `%u` for unsigned integers
- `%x` and `%X` for hexadecimal integers
- `%%` for the `%` character itself


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


### Example
```c
ft_printf("%010d", 123);
```

the code above will output:
```
0000000123
```

### Precision
- `.` - precision (only works with the `%.*s` and `%.*d` format specifiers)
- `.(*)` - the precision is given in the argument list (only works with the `%*.*s` and `%*.*d` format specifiers)

as for the project, I have designed it in a way to manage any combinations, except for the `.precisions` flags

## Status
![](https://i.imgur.com/rTaP3JM.png)

- [x] Mandatory part
- [x] Bonus part
- [X] Norminette

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


---
Made by [szhong](szhong@student.42london.com)

I am writing this README in the process of learning, so if you have any suggestions or find any issues, please let me know. You can reach me via:
- LinkedIn: [@szhong](https://www.linkedin.com/in/shenghongzhong/) 
- X: [@amzdsz](https://x.com/amzdsz) 


I am writing newsletter about career change from Data Analyst to Software Engineering, Building products with A.I, if you are interested, please [![Subscribe to Newsletter](https://img.shields.io/badge/Subscribe-Newsletter-blue)](https://amazingdavid.substack.com/)
