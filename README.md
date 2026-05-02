*This project has been created as part of the 42 curriculum by \<your_login\>.*

---

# ft_printf

## Description

`ft_printf` is a partial reimplementation of the C standard library function `printf`. The goal of the project is to understand and reproduce the core formatting and output mechanism of `printf` from scratch, without relying on any standard output functions beyond `write`.

The function handles the following format specifiers:

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String (prints `(null)` for NULL) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` / `%X` | Unsigned hexadecimal (lower / upper case) |
| `%p` | Pointer address (prints `(nil)` for NULL) |
| `%%` | Literal percent sign |

---

## Algorithm and Data Structure

The implementation follows a straightforward **linear scan with dispatch** approach:

1. `ft_printf` iterates over the format string character by character.
2. When it encounters a `%`, it advances one character and passes the next character to `format_handler`, which dispatches to the appropriate output function.
3. Every function returns the **number of bytes written**, which are accumulated and returned as the final return value — matching `printf`'s contract.

No complex data structures are needed for this project. The design is intentionally minimal:

- **Recursion** is used in `ft_putnbr`, `ft_un_putnbr`, and `ft_puthex` to decompose numbers digit by digit, from most significant to least significant, without needing a buffer or stack structure. This works because integer digits can be derived cleanly by repeated division, and recursion naturally reverses the order.
- **`va_list`** (from `<stdarg.h>`) is the only non-trivial mechanism used. It allows the function to accept a variable number of arguments and consume them one by one in the order they are passed, matching each to its format specifier.
- `INT_MIN` (`-2147483648`) is special-cased explicitly because negating it in a 32-bit integer causes undefined overflow — the value has no positive counterpart in `int`.

---

## Instructions

### Compilation

The library compiles to a static archive `libftprintf.a`:

```bash
make
```

To clean object files:

```bash
make clean
```

To remove all generated files including the archive:

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

### Usage

Include the header in your source file and link against the archive:

```c
#include "ft_printf.h"
```

```bash
gcc main.c libftprintf.a -o my_program
./my_program
```

---

## Resources

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — The official Linux manual page for `printf`, used as the reference for expected behaviour and return values.
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — Documentation for `va_list`, `va_start`, `va_arg`, and `va_end`, which are the foundation of variadic function handling in C.
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — Supplementary reference for format specifier behaviour.

### AI Usage

Claude (Anthropic) was used during the **testing and review phase** only — not for writing any code. Specifically, it was used to:
- Write a test harness that compared `ft_printf` output and return values against the real `printf` side by side across all supported specifiers and edge cases.
- Review the finished implementation for correctness and flag any deviations from standard `printf` behaviour.

No AI was used during design, algorithm selection, or implementation.
