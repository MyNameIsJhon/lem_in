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

lem_p *lem_name_searcher_point(lem_p **alemp, char *str)
{
    lem_p *lemp = *alemp;

    while(lemp)
    {
        if(ft_strcmp(lemp->name, str) == 0)
            return lemp;
        lemp = lemp->next;
    }

    return lemp;
}


void set_pont(lem_p *pont_a, lem_p *pont_b)// a faire
{
    lem_p **pont_tab;
    lem_p *pont_bis = NULL;

    //à finir

}

void ft_lemp_clearall(lem_p **alemp, void (*f)(void*))
{
    lem_p *curr;
    lem_p *tmp;

    int i = 0;

    if(!alemp || !f)
        return;
    
    curr = *alemp;

    while(curr)
    {
        tmp = curr;
        f(curr->name);
        curr = curr->next;
        free(tmp);
        i++;
    }
    *alemp = NULL;
}

