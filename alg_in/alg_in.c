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
        if(curs->startorend = 1)
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
        if(curs->startorend = 2)
            return curs;
        curs = curs->next;
    }
    
    return curs;
}



t_list *lem_bestway_finder(lem_p *lemp_map)
{
    t_list **finder;
    lem_p *lemp_start = NULL;

    if(!lemp_map)
        return NULL;
    if(!(finder = (t_list**) malloc(sizeof(t_list*) * 2)))
        return NULL;
    
    

}