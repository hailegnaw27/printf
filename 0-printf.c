#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int i, len = 0;
    char c;
    char *str;
    va_list args;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            c = format[i];
            write(1, &c, 1);
            len++;
        }
        else
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    len++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        len++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    len++;
                    break;
                default:
                    break;
            }
        }
    }

    va_end(args);

    return len;
}

