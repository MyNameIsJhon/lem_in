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
    lst->pont = NULL;

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

size_t pont_len(lem_p **pont)
{
    size_t i = 0;

    if(!(pont))
        return 0;
    while(pont[i] != NULL)
        i++;
    return i;
}

void set_pont(lem_p *lem_a, lem_p *lem_b)
{
    size_t i = 0; 
    lem_p **pont_bis;

    size_t pt_len = 0;

    if (lem_a->pont == NULL)
    {
        lem_a->pont = (lem_p**) malloc(sizeof(lem_p*) * 2);
        lem_a->pont[0] = lem_b;
        lem_a->pont[1] = NULL;
    }
    else
    {
        pt_len = pont_len(lem_a->pont);
        pont_bis = (lem_p**) malloc(sizeof(lem_p*) * (pt_len + 2));
        
        while (i < pt_len)
        {
            pont_bis[i] = lem_a->pont[i];
            i++;
        }

        pont_bis[i] = lem_b;
        pont_bis[i+1] = NULL;
        free(lem_a->pont);

        lem_a->pont = pont_bis;
    }
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

