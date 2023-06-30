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

lem_p *recup_lempoints(t_list **alst) //not finish
{
    t_list *lst = *alst;
    char **astr = NULL;
    lem_p *lemp;

    int stoend = 0;

    size_t i = 0;

    getchar();

    while(lst != NULL)
    {
        astr = ft_strsplit((const char*) lst->content, ' ');

        if(ft_strcmp("##start", (char*) lst->content) == 0)
            stoend = 1;
        else if(ft_strcmp("##end", (char*) lst->content) == 0)
            stoend = 2;
        if(astr[1] != NULL)
        {
            if(i == 0)
                lemp = new_lem_point(ft_atoi(astr[1]), ft_atoi(astr[2]), ft_strdup(astr[0]), stoend);  
            else
            {
                lem_add_back(&lemp, new_lem_point(ft_atoi(astr[1]), ft_atoi(astr[2]), ft_strdup(astr[0]), stoend));
            }
            stoend = 0;
            i++; 
        }
        lst = lst->next;
        ft_free_strsplit(astr);
    }

    return lemp;
}

int main(int argc, char **argv)
{
    t_list *lst = NULL;
    lem_t lems; // taille tableau
    lem_p *lemp = NULL;

    file_2_lst(&lst, "./fourmiliere.txt");

    lems = lem_size(&lst);

    lemp = recup_lempoints(&lst);

    ft_lemp_clearall(&lemp, &free);
    
    ft_lstclearall(&lst, &free);
}