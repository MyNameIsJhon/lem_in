#include <unistd.h>
#include "file.h"
#include "libft.h"
#include "list.h"
#include "lem_list.h"
 #include <fcntl.h>

typedef struct lem_s{

    size_t size_x;
    size_t size_y;

} lem_t;


lem_t lem_size(t_list **alst) //not finish
{
    t_list *lst = *alst;
    char **astr = NULL;
    lem_t lems;

    lems.size_x = 0;
    lems.size_y = 0;

    getchar();

    while(lst != NULL)
    {
        astr = ft_strsplit((const char*) lst->content, ' ');
        lst = lst->next;
        if(astr[1] != NULL)
        {
            if(lems.size_x < ft_atoi(astr[1]))
                lems.size_x = ft_atoi(astr[1]);
            if(lems.size_y < ft_atoi(astr[2]))
                lems.size_y = ft_atoi(astr[2]);
            
        }
        ft_free_strsplit(astr);
    }

    return lems;
}

int main(int argc, char **argv)
{
    t_list *lst = NULL;
    lem_t lems; // taille tableau

    file_2_lst(&lst, "./fourmiliere.txt");

    lems = lem_size(&lst);
    
    ft_lstclearall(&lst, &free);
}