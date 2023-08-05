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

t_list *lem_bestway_finder(lem_p *lemp_map)
{
    t_list **finder;

    if(!lemp_map)
        return NULL;
    

}