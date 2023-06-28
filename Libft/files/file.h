#ifndef FILES_INT
#define FILES_INT

#include "list.h"

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define BUFF_POS_SAVE 1
#define BUFF_POS_UNSAVE 0

#define BUFF_SIZE 200 //afin de géré fget_next_line


typedef struct FT_FILE{

    int fd;
    int flags;
    char *path;

} FT_FILE;


size_t ft_flen(FT_FILE *file);
int resetloc_file(FT_FILE *file);
FT_FILE *ft_fopen(const char *path, int right);
void ft_fclose(FT_FILE *file);
int ft_fget_next_line(FT_FILE *file, char **line);
int ft_fseek(FT_FILE *file, unsigned int seek_pos, size_t nb_c);
int file_2_lst(t_list **alst, char *path);
void cat_file(char *path);



#endif