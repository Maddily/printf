# Custom Printf function


## Description

The custom printf function is an implementation of the widely used printf function in the C programming language. It provides a versatile and flexible way to format and print text output. This custom implementation aims to mimic the behavior and functionality of the standard C library's printf function while allowing for customization and extensibility.

## Languages and Tools


<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> </p>


## Contributors details

Mayada Saeed - [`Maddily`](https://github.com/Maddily) - [`LinkedIn Profile`](https://www.linkedin.com/in/mayadase/)

Sibongile Nhlema - [`Sibongile-Nhlema`](https://github.com/Sibongile-Nhlema) - [`LinkedIn Profile`](https://www.linkedin.com/in/sibongile-nhlema/)

## Tasks

### Task 0

This task involves writing a function that produces output according to a format.

#### Prototype

```c
int _printf(const char *format, ...);
```

#### Usage

* `format` is a character string composed of zero or more directives.
* The following conversion specifiers are to be handled:
	* `c`
	* `s`
	* `%`
* You don’t have to:
	* Reproduce the buffer handling of the C library `printf` function
	* Handle the flag characters
	* Handle field width
	* Handle precision
	* Handle the length modifiers

### Task 1

This task involves handling the conversion specifiers `d` and `i`.

#### Usage

* You don’t have to:
	* Handle the flag characters
	* Handle field width
	* Handle precision
	* Handle the length modifiers

### Task 2

This task involves handling the following custom conversion specifier:
* `b`: the unsigned int argument is converted to binary

#### Example

```c
int main(void)
{
    _printf("%b\n", 98); /*Output: 1100010*/
    return (0);
}
```

### Task 3

This task involves handling the following conversion specifiers:
	* `u`
	* `o`
	* `x`
	* `X`

#### Usage

* You don’t have to:
	* Handle the flag characters
	* Handle field width
	* Handle precision
	* Handle the length modifiers

### Task 4

This task involves using a local buffer of 1024 chars in order to call write as little as possible.

### Task 5

This task involves handling the following custom conversion specifier:
* `S`: Prints a string.

#### Usage
* Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters).

### Task 6

This task involves handling the `p` conversion specifier.

* You don’t have to:
	* Handle the flag characters
	* Handle field width
	* Handle precision
	* Handle the length modifiers

### Task 7

This task involves handling the following flag characters for non-custom conversion specifiers:

* `+`
* space
* `#`

### Task 8

This task involves handling the following length modifiers for non-custom conversion specifiers:

* `l`
* `h`

#### Conversion specifiers to handle:

* `d`
* `i`
* `u`
* `o`
* `x`
* `X`

### Task 9

This task involves handling the field width for non-custom conversion specifiers.

### Task 10

This task involves handling the precision for non-custom conversion specifiers.

### Task 11

This task involves handling the `0` flag character for non-custom conversion specifiers.

### Task 12

This task involves handling the `-` flag character for non-custom conversion specifiers.

### Task 13

This task involves handling the following custom conversion specifier:

* `r` : prints the reversed string

### Task 14

This task involves handling the following custom conversion specifier:

* `R`: prints the rot13'ed string

### Task 15

This task involves making sure that all the above options work well together.
