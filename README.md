# 42Warsaw

This repository contains 42 Warsaw curriculum projects by bgorski.

## Projects

### libft
A C library containing reimplementations of standard string and memory manipulation functions.

**Includes:**
- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Memory functions: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- String functions: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Character conversion: `ft_toupper`, `ft_tolower`
- Conversions: `ft_atoi`, `ft_itoa`
- Allocation: `ft_calloc`
- String manipulation: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
- Output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Linked list (bonus): `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

**Build:**
```bash
cd libft && make        # Build libft.a
cd libft && make bonus  # Build with linked list functions
```

---

### ft_printf
A reimplementation of the C standard library `printf` function.

**Supported format specifiers:**
- `%c` — character
- `%s` — string
- `%p` — pointer address
- `%d` / `%i` — signed integer
- `%u` — unsigned integer
- `%x` / `%X` — hexadecimal (lowercase / uppercase)
- `%%` — literal percent sign

**Build:**
```bash
cd ft_printf && make
```

**Usage:**
```c
#include "ft_printf.h"
ft_printf("Hello, %s! Value: %d\n", "world", 42);
```

---

### get_next_line
A function that reads one line at a time from a file descriptor on each call.

**Features:**
- Works with any file descriptor (files, stdin)
- Configurable buffer size via `BUFFER_SIZE` macro (default: 42)
- Returns `NULL` on EOF or error

**Build:**
```bash
cd get_next_line && make
```

**Usage:**
```c
#include "get_next_line.h"
char *line;
while ((line = get_next_line(fd)) != NULL) {
    // process line
    free(line);
}
```

---

### push_swap
A sorting algorithm that sorts integers using two stacks and a limited set of operations.

**Stack operations:**
- `sa` / `sb` / `ss` — swap top two elements
- `pa` / `pb` — push top element to the other stack
- `ra` / `rb` / `rr` — rotate stack upward
- `rra` / `rrb` / `rrr` — reverse rotate stack

**Algorithm:** Greedy insertion sort with circular stack maintenance.

**Build:**
```bash
cd push_swap && make
```

**Usage:**
```bash
./push_swap 3 1 4 5 2   # Outputs the sequence of operations
```

---

## Future Projects

Python projects will be added in the future.
