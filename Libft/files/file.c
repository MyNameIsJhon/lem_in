#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "list.h"
#include "file.h"


FT_FILE *ft_fopen(const char *path, int right)
{
    FT_FILE *file;

    file = (FT_FILE*) malloc(sizeof(FT_FILE));
    if(file == NULL)
        return NULL;

    file->fd = open(path, right);
    if(file->fd == -1)
    {
        free(file);
        return NULL;
    }
    
    file->flags = right;
    file->path = ft_strdup(path);

    return file;
}

void ft_fclose(FT_FILE *file)
{
    if(file == NULL)
        return;

    close(file->fd);
    free(file->path);
    free(file);
}


int ft_fget_next_line(FT_FILE *file, char **line)
{
    int fd;
    char c;
    size_t i = 0;

    if (!file|| !line || access(file->path, R_OK) == (-1))
        return (-1);

    char *str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));

    fd = file->fd;

    if (!str)
        return (-1);


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

int resetloc_file(FT_FILE *file)
{
    if(!file || access(file->path, R_OK))
        return 0;

    close(file->fd);
    open(file->path, file->flags);

    return (file->fd != -1) ? 1 : 0;
}


size_t ft_flen(FT_FILE *file)
{
    int fd;
    char c;
    size_t i = 0;

    if((fd = open(file->path, O_RDONLY)) == (-1))
        return 0;
    
    while(read(fd, &c, 1))
        i++;
    return i;
}


int ft_fseek(FT_FILE *file, unsigned int seek_pos, size_t nb_c)
{
    size_t i = 0;
    char c;

    if(!file || file->flags > 2 || access(file->path, R_OK) == (-1))
        return 0;
    
    if(seek_pos == SEEK_SET)
        resetloc_file(file);
    else if(seek_pos == SEEK_END)
    {
        resetloc_file(file);
        nb_c = ft_flen(file) - (nb_c + 1);
    }
    
    while(read(file->fd, &c, 1) && i < nb_c)
        i++;
    return 1;
}


int file_2_lst(t_list **alst, char *path)
{
    t_list *lst = NULL;
    char *line = NULL;
    FT_FILE *file = NULL;

    if(access(path, R_OK) == -1)
        return 0;
    if(!(file = ft_fopen(path, O_RDONLY)))
        return 0;
    
    ft_fget_next_line(file, &line);
    lst = ft_lstnew((char*) ft_strdup(line));
    free(line);

    while(ft_fget_next_line(file, &line))
    {
        ft_lstadd_back(&lst, ft_lstnew((char*) ft_strdup(line)));
        free(line);
    }

    *alst = lst;

    ft_fclose(file);

    return 1;
}


void cat_file(char *path)
{
    FT_FILE *file = NULL;
    char *line = NULL;

    if(!(file = ft_fopen(path, O_RDONLY)))
        return;
    while(ft_fget_next_line(file, &line) > 0)
    {
        ft_putstr(line);
        ft_putchar('\n');
        free(line);
    }
    ft_putstr("\n");
}

