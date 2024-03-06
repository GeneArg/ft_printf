## Code Flow Diagram

### Start
- The program begins execution.

### `ft_printf(const char *format, ...)`
- The main function that emulates the behavior of printf.
- Takes a format string and a variable number of arguments.

### `print_format(char c, va_list ap)`
- Determines the format specifier and calls the appropriate function to print the corresponding argument.
- Supports format specifiers: 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'.

### `print_char(char c)`
- Prints a single character.
- Returns the number of characters printed.

### `print_string(char *s)`
- Prints a string.
- Handles NULL strings by printing "(null)".
- Returns the number of characters printed.

### `print_pointer(void *p)`
- Prints a pointer address in hexadecimal format.
- Handles NULL pointers by printing "(nil)".
- Returns the number of characters printed.

### `print_int(int n)`
- Prints a signed integer.
- Handles negative numbers and the special case of INT_MIN.
- Returns the number of characters printed.

### `print_unsigned(unsigned int n)`
- Prints an unsigned integer.
- Returns the number of characters printed.

### `print_hex(unsigned long long n, int upper)`
- Prints an integer in hexadecimal format.
- Supports uppercase ('X') and lowercase ('x') formats.
- Returns the number of characters printed.

### End
- The program ends execution.
