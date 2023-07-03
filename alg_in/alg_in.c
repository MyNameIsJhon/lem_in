#include "libft.h"
#include "list.h"
#include "lem_list.h"
#include "alg_in.h"

lem_p *lem_start_searcher(lem_p **alemp)
{
    lem_p *lemp = NULL;

    lemp = *alemp;

    while(lemp != NULL && lemp->startorend != 1) 
        lemp = lemp->next;
    
    return lemp;
}

lem_p *lem_end_searcher(lem_p **alemp)
{
    lem_p *lemp = NULL;

    lemp = *alemp;

    while(lemp != NULL && lemp->startorend != 1) 
        lemp = lemp->next;
    
    return lemp;
}

