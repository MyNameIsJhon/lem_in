#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "list.h"
#include "file.h"

#define BUFF_SIZE 120 // nombre max de caractères lus

char *strdup_chr(const char *str, char c)
{
    int i = 0;

    while (str[i] != c && str[i] != '\0')
        i++;

    char *sub = ft_strsub(str, 0, i);
    return sub;
}

int ft_get_next_line(int fd, char **line)
{
    if (fd < 0 || !line)
        return (-1);

    char *str = (char*) malloc(sizeof(char) * (BUFF_SIZE + 1));
    if (!str)
        return (-1);

    char c;
    size_t i = 0;

    while (i < BUFF_SIZE && read(fd, &c, 1) > 0)
    {
        str[i] = c;
        i++;
        if (c == '\n')
        {
            str[i] = '\0';
            *line = strdup_chr(str, c);
            free(str);
            return 1;
        }
    }

    if (i == 0)
    {
        free(str);
        return 0;
    }

    str[i] = '\0';
    *line = strdup_chr(str, '\0');
    free(str);
    return 1;
}



