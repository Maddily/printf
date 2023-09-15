% Version 1.0 "15 Sept. 2023" | "_printf_" Documentation (man pages)

Custom printf function
====

**_printf** — Custom printf function that prints a string

SYNOPSIS
========

    #include <main.h>
    #include <stdarg.h>
    #include <stdlib.h>

    int custom_printf(const char *format, ...);

DESCRIPTION
===========

The custom_printf function is a custom implementation of the printf function in the C programming language.

It prints a string to the terminal.
The custom_printf function supports the following format specifiers:

 1. %d:  Prints an integer.
 2. %f:  Prints a floating-point number.
 3. %s:  Prints a string.
 4. %x:  Prints Hexidecimal (lower)
 5. %X:  Prints Hexidecimal (upper)
 6. %%:  Prints percentage
 7. %u:  Prints unsigned
 8. %i:  interger 
 9. %o:  Prints octal
 10. %p:  precision
 11. %l:  Length nodifier
 12. %h:  Height modifier
 13. %b:  Print binary

**RETURN VALUE**

The custom_printf function returns the number of characters printed.

**EXAMPLES**
Here are some examples of using the custom_printf function:
Example 1:
----------

    #include <stdio.h>

    int main() 
    {
        _printf("Hello, %s!\n", "world");
        return 0;
    }


Options
-------

-v, --version

:   Prints the current version number.

FILES
=====

*./printf.c*
:   custom function.

BUGS
====

See GitHub Issues: <https://github.com/Maddily/printf/issues>

AUTHORS
=======

1. Sibongile Nhlema <sibongile.nhlema@gmail.com>
2. Mayada Saeed <mayadasaeeddev@gmail.com.com>

SEE ALSO
========

printf(3)

