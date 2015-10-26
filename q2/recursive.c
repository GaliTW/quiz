#include <stdio.h>

char _smallest_character(char str[], char c)
{
    if (*str == '\0')
        return 0;

    if (*str > c)
        return *str;

    return _smallest_character(++str, c);
}

char smallest_character(char str[], char c)
{
    if (str == NULL)
        return 0;

    c = _smallest_character(str, c);
    if (c == 0)
        return *str;

    return c;
}

