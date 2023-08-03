#include <unistd.h>
#include "file.h"
#include "libft.h"
#include "list.h"
#include "lem_list.h"
#include "alg_in.h"
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

void lemp_connection(lem_p **alemp, t_list **alst)
{
    t_list *lst = *alst;
    char **astr = NULL;

    lem_p *lemp_search_a = NULL;
    lem_p *lemp_search_b = NULL;

    size_t i = 0;

    while(lst != NULL)
    {
        astr = ft_strsplit((const char*) lst->content, '-');

        if(astr[1] != NULL)
        {
            if(!(lemp_search_a =  lem_name_searcher_point(alemp, astr[0])))
            {
                ft_printf("you enter a bad way connection : %s", astr[0]);
                return;
            }
            if(!(lemp_search_b =  lem_name_searcher_point(alemp, astr[1])))
            {
                ft_printf("you enter a bad way connection : %s", astr[1]);
                return;
            }

            set_pont(lemp_search_a, lemp_search_b);
            set_pont(lemp_search_b, lemp_search_a);

            i++; 
        }
        lst = lst->next;
        ft_free_strsplit(astr);
    }
}

int main(int argc, char **argv)
{
    t_list *lst = NULL;
    lem_t lems; // taille tableau
    lem_p *lemp_map = NULL;


    file_2_lst(&lst, "./fourmiliere.txt");

    lems = lem_size(&lst);

    lemp_map = recup_lempoints(&lst);

    lemp_connection(&lemp_map, &lst);

    ft_printf("%s \n", lemp_map->next->next->pont[1]->name);

    ft_lemp_clearall(&lemp_map, &free);
    
    ft_lstclearall(&lst, &free);
}