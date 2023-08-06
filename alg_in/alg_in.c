#include "libft.h"
#include "list.h"
#include "lem_list.h"
#include "alg_in.h"

lem_p *lem_start_finder(lem_p *lemp_map)
{
    lem_p *curs = NULL;

    if(!lemp_map)
        return NULL;

    curs = lemp_map;

    while(curs != NULL)
    {
        if(curs->startorend == 1)
            return curs;
        curs = curs->next;
    }
    
    return curs;
}

lem_p *lem_end_finder(lem_p *lemp_map)
{
    lem_p *curs = NULL;

    if(!lemp_map)
        return NULL;

    curs = lemp_map;

    while(curs != NULL)
    {
        if(curs->startorend == 2)
            return curs;
        curs = curs->next;
    }
    
    return curs;
}

size_t lem_finder_tablen(t_list **finder)
{
    size_t i = 0;

    if(!(finder[0]))
        return i;
    while(finder[i] != NULL)
        i++;
    return i;
}

void lem_finder_cp(t_list **finder,t_list **finder_cp)
{
    size_t i = 0;

    while(finder[i] != NULL)
    {
        finder_cp[i] = finder[i];
        ++i;
    }
    finder_cp[i] = NULL; 
}

void lem_free_finder(t_list **finder)
{
    size_t i = 0;

    while(finder[i] != NULL)
    {
        free(finder[i]);
        ++i;
    }
}




t_list *lem_bestway_finder(lem_p *lemp_map)
{
    t_list **finder;
    lem_p *lemp = NULL;

    if(!lemp_map)
        return NULL;
    if(!(finder = (t_list**) malloc(sizeof(t_list*) * 2)))
        return NULL;
    
    finder[0] = ft_lstnew(lemp_map);
    finder[1] = NULL;

    ft_lstadd_back(&finder[0], ft_lstnew(lemp_map->pont[0]));

    lemp = (lem_p*) finder[0]->content; 

    ft_printf("%s \n", lemp->name);

}