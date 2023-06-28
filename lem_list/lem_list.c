#include "libft.h"
#include "list.h"
#include "file.h"
#include "lem_list.h"

lem_p *new_lem_point(size_t x, size_t y, char *name, int stoend)
{
    lem_p *lst;

    lst = (lem_p*) malloc(sizeof(lem_p));

    if(!name || !lst || (stoend <= 0 && stoend >= 2))
        return NULL;

    lst->x = x;
    lst->y = y;
    lst->name = ft_strdup(name);
    lst->startorend = stoend;

    lst->next = NULL;

    return (lst);
}

lem_p *lem_last(lem_p *lemp)
{
    lem_p *curs;

    curs = lemp;

    while(curs->next != NULL)
        curs = curs->next;
    return (curs);
}

void lem_add_back(lem_p **alemp, lem_p *new)
{
    lem_p *curs = lem_last(*alemp);

    if(!alemp || !new)
        return;
    
    curs->next = new;
    new->next = NULL;
}

