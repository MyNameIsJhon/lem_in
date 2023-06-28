#include <unistd.h>
#include "file.h"
#include "libft.h"
#include "list.h"
#include "lem_list.h"

typedef struct lem_s{

    size_t size_x;
    size_t size_y;

    char *start;
    char *end;

} lem_t;

lem_p **file_to_lem_loc(FT_FILE *file)
{
    char *str = NULL;
    char **astr;

    int stoend = 0;

    lem_p *lemp;

    int i = 0;

    while(ft_fget_next_line(file, &str) != (-1))
    {
        astr = ft_strsplit(str, ' ');

        if(ft_strcmp("##start", str) == 0)
            stoend = 1;
        else if(ft_strcmp("##end", str) == 0)
            stoend = 2;
        else if(astr[1] && astr[2])
        {
            if(i == 0)
            {
                lemp = new_lem_point(ft_atoi(astr[1]), ft_atoi(astr[2]), ft_strdup(astr[0]), stoend);
                i++;
            }
            else
                lem_add_back(&lemp, new_lem_point(ft_atoi(astr[1]), ft_atoi(astr[2]), ft_strdup(astr[0]), stoend));

            stoend = 0;
        }

        free(str);
        free(astr);
    }

    ft_fseek(file, SEEK_SET, 0);

    return lemp;
}

lem_t lem_size(FT_FILE *file) //not finish
{
    char *str = NULL;
    char **astr;

    while(ft_fget_next_line(file, &str))
    {
        ft_strsplit(str, ' ');
        free(str);
    }

}

int main(int argc, char **argv)
{
    FT_FILE *file = NULL;

    lem_p *lemp;

    int eva;

    scanf("%d", &eva);

    ft_fopen("./fourmiliere.txt", 00);
    
    lemp = file_to_lem_loc(file);

    ft_putnbr(lemp->next->x);
}