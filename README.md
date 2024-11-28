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


I am writing newsletter, if you are interested, please subscribe: 

<div style="
   background-color: #2e2e2e; 
   color: #e0e0e0; 
   border: 1px solid #404040; 
   border-radius: 8px; 
   padding: 20px; 
   text-align: center; 
   margin-bottom: 20px;
   font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, sans-serif;">
   
   <h2 style="
       color: #ffffff; 
       margin-bottom: 16px; 
       font-size: 24px;">
       Amazing David
   </h2>
   
   <p style="
       color: #b0b0b0; 
       margin-bottom: 24px; 
       line-height: 1.6;
       text-align: left;">
       My personal mission is to live a rich flourish life and leave legacy to the world as an inspiration (hopefully)
   </p>
   
   <a href="https://amazingdavid.substack.com/" 
       style="
       display: inline-block;
       background-color: #4a4a4a;
       color: #ffffff;
       padding: 12px 24px;
       text-decoration: none;
       border-radius: 6px;
       font-weight: 500;
       transition: background-color 0.2s ease;
       cursor: pointer;
       border: 1px solid #555555;">
       Subscribe to Newsletter
   </a>
</div>

