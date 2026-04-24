# Libft Plus

An extended and enhanced custom C library for the 42 school curriculum.

**Context within 42:** `libft` is the very first project of the 42 school's Common Core (*Tronc Commun*), where the goal is to recreate a standard C library from scratch. However, this repository represents the **final, evolved state** of the library at the end of the Common Core curriculum. Throughout the cursus, students are expected to continuously expand their `libft` with new utilities, robust data structures, and other early projects (like `ft_printf` and `get_next_line`) to build a powerful personal toolkit for subsequent advanced projects.

This project builds upon the foundations of the standard 42 [`libft`](https://github.com/42School/norminette) by incorporating several essential extensions needed for advanced projects. It serves as a unified utility toolkit containing not only standard C library functions but also specialized data structures, the `ft_printf` family, and `get_next_line`.

## 🚀 Features

This enhanced library is divided into several sections:

### 1. Standard Libc Functions
Re-implementations of standard C library functions:
- **Memory**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **String**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- **Character types**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- **Parsing**: `ft_atoi`

### 2. Standard 42 Functions
Additional utility functions required by the 42 curriculum:
- **Strings**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
- **Numbers**: `ft_itoa`
- **File Descriptors**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Linked Lists (Bonus)
A module for basic singly linked list manipulations:
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### 4. Dynamic Arrays (Vectors)
A custom data structure for resizable arrays to easily manage memory allocation dynamically:
- `ft_dynarr_init`, `ft_dynarr_add_char`, `ft_dynarr_add_int`, `ft_dynarr_add_ptr`, `ft_dynarr_remove`, `ft_dynarr_from`, `ft_dynarr_free`

### 5. `ft_printf` Family
Re-implementation of the standard output formatters:
- `ft_printf`: Prints to standard output.
- `ft_dprintf`: Prints to a specific file descriptor.
- `ft_sprintf` / `ft_snprintf`: Prints to a string buffer.
- `ft_vprintf`, `ft_vdprintf`, `ft_vsprintf`, `ft_vsnprintf`: `va_list` variants.

### 6. File Reading
- `get_next_line` / `safe_gnl`: Read text from file descriptors line by line.

### 7. Extra Utilities (The "Plus" features)
Additional quality-of-life helpers:
- **Numbers & Parsing**: `ft_atol`, `ft_atoll`, `ft_atoi_base`
- **Memory**: `ft_realloc`, `ft_free_arr`
- **Strings**: `ft_strcmp`, `ft_stricmp`
- **Checkers**: `ft_isspace`, `ft_is_valid_filename`
- **Misc**: `ft_arrlen`, `ft_int_arr_get`, `ft_rand`, `ft_ternary`

## 🛠️ Usage

### Compilation
Simply run `make` at the root of the repository to build the library. 

```bash
make        # Compiles the library (libft.a)
make clean  # Removes object files
make fclean # Removes object files and libft.a
make re     # Re-compiles everything
```

### Including in your project
Once `libft.a` is compiled, you can include it in your C projects:

1. Include the header in your C files:
   ```c
   #include "libft.h"
   ```

2. Compile your program alongside `libft.a`:
   ```bash
   cc my_program.c -L. -lft -o my_program
   ```

## 📜 License
This project is part of the 42 school curriculum and is open-sourced for educational purposes.
