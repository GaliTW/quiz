#include <stdlib.h>

char smallest_character(char str[], char c)
{
    if (str == NULL)
        return 0;

    for (char* w = str; *w != '\0'; ++w)
        if (*w > c)
            return *w;

    return *str;
}

