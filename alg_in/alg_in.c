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

void lem_finder_cp(t_list **finder,t_list **finder_cp)//il va falloir que je crée une nouvelle fonction dans list afin de me permettre de doubler un chemin et de ne pas perdre les donnés lors du free
{
    size_t i = 0;

    while(finder[i] != NULL)
    {
        finder_cp[i] = ft_lstcp(&finder[i]);
        ++i;
    }
    finder_cp[i] = NULL; 
}

void lem_free_finder(t_list **finder)
{
    size_t i = 0;

    while(finder[i] != NULL)
    {
        ft_lstclear(&finder[i]);
        ++i;
    }
}

void lem_new_way(t_list ***finder, t_list *way_2_cp)
{
    t_list **finder_cp = NULL;
    size_t finder_len = 0;
    lem_p *lemp;

    if(!way_2_cp || !(*finder)[0])
        return;
    finder_len = lem_finder_tablen(*finder) + 1;

    if(!(finder_cp = (t_list**) malloc(sizeof(t_list*) * (finder_len + 1))))
        return;
    
    lem_finder_cp(*finder, finder_cp);
    finder_cp[finder_len-1] = ft_lstcp(&way_2_cp);
    finder_cp[finder_len] = NULL;
    lem_free_finder(*finder);

    if(!(*finder = (t_list**) malloc(sizeof(t_list*) * (finder_len + 1))))
        return;
    
    lem_finder_cp(finder_cp, *finder);
    (*finder)[finder_len] = NULL;
    
    lem_free_finder(finder_cp);



t_list *lem_bestway_finder(lem_p *lemp_map)
{
    t_list **finder;
    lem_p *lemp = NULL;

    if(!lemp_map)
        return NULL;
    if(!(finder = (t_list**) malloc(sizeof(t_list*) * 2)))
        return NULL;
    
    finder[0] = ft_lstnew(lem_start_finder(lemp_map));
    ft_lstadd_back(&finder[0], ft_lstnew(lem_start_finder(lemp_map)->pont[0]));
    finder[1] = NULL;

    lem_new_way(&(finder), finder[0]);

    lemp = (lem_p*) finder[1]->content; 

    ft_printf("%s \n", lemp->name);

}