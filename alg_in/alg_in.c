#include "libft.h"
#include "list.h"
#include "lem_list.h"
#include "alg_in.h"

lem_fi *lem_newfinder(lem_p *point)
{
    lem_fi *finder;

    if(!point)
        return NULL;
    if(!(finder = (lem_fi*) malloc(sizeof(lem_fi))))
        return NULL;

    finder->lem_point = point;
    finder->next = NULL;

    return finder;
}

size_t lem_len_afinder(lem_fi **afinder)
{
    size_t i = 0;

    while(afinder[i] != NULL)
        ++i;
    return i;
}

lem_fi *lem_last_finder(lem_fi **afinder)
{
    size_t i = 0;

    while(afinder[i] != NULL)
        ++i;
    return afinder[i-1];
}

void lem_addbackfinder(lem_fi **afinder, lem_fi *finder)
{
    lem_fi *curs = NULL;

    if(!(*afinder) || !finder)
        return;
    
    curs = lem_last_finder(afinder);

    curs->next = finder;
}

int lem_dupli_afinder(lem_fi **afinder)
{
    lem_fi *dup = NULL;
    size_t afinder_len = 0;

    if(!(*afinder))
        return NULL;
    
    
}

void lem_afinder_newtab(lem_fi **afinder, lem_fi **dup_afinder, )
{
    size_t afinder_len = 0;
    size_t i = 0;

    if(!afinder)
        return;
    
    afinder_len = lem_len_afinder(afinder);

    if(!(dup_afinder = (lem_fi**) malloc(sizeof(lem_fi*) * (afinder_len + 2))))
        return;
    while(afinder[i] != NULL)
    {
        dup_afinder[i] = afinder[i];
        i++;
    }

    dup_afinder[i] = ;

}

