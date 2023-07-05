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

    while(lemp != NULL && lemp->startorend != 2) 
        lemp = lemp->next;
    
    return lemp;
}

size_t way_len(lem_p **pont)
{
    size_t i = 0;

    if(!(pont))
        return 0;
    while(pont[i] != NULL)
        i++;
    return i;
}

void set_way(lem_al *lem_a, lem_p *lem_b)
{
    size_t i = 0; 
    lem_p **pont_bis;

    size_t pt_len = 0;

    if (lem_a->way == NULL)
    {
        lem_a->way = (lem_p**) malloc(sizeof(lem_p*) * 2);
        lem_a->way[0] = lem_b;
        lem_a->way[1] = NULL;
    }
    else
    {
        pt_len = way_len(lem_a->way);
        pont_bis = (lem_p**) malloc(sizeof(lem_p*) * (pt_len + 2));
        
        while (i < pt_len)
        {
            pont_bis[i] = lem_a->way[i];
            i++;
        }

        pont_bis[i] = lem_b;
        pont_bis[i+1] = NULL;
        free(lem_a->way);

        lem_a->way = pont_bis;
    }
}



lem_al *lem_add_way(lem_p *way)
{
    lem_al *path_finder = NULL;

    if(!way)
        return NULL;
    if(!(path_finder = (lem_al*) malloc(sizeof(lem_al))))
        return NULL;
    
    set_way(path_finder, way);
    path_finder->counter = way_len(path_finder->way);
    path_finder->next = NULL;

    return path_finder;
}

lem_al *lem_finder_lastway(lem_al **apath_finder)
{
    lem_al *path_finder = NULL;


    if(!(*apath_finder))
        return NULL;
    while(path_finder->next != NULL)
        path_finder = path_finder->next;
    
    return path_finder;
}

void lem_add_wayback(lem_al **apath_finder, lem_al *new)
{
    lem_al *path_finder = NULL;

    if(!(*apath_finder))
        return;
    path_finder = lem_finder_lastway(apath_finder);

    path_finder->next = new;    
}

lem_al *lem_find_bestway(lem_p **alemp, lem_al **apath_finder) //configurer sur NULL si aucune sources de chemin principale
{
    lem_p *start_lem = NULL;
    lem_p *end_lem = NULL;

    lem_al *path_finder = NULL;
    
    if(apath_finder == NULL)
        path_finder = NULL;
    else
        path_finder = *apath_finder;
    
    if(!(start_lem = lem_start_searcher(alemp)))
        return NULL;
    if(!(end_lem = lem_end_searcher(alemp)))
        return NULL;
    
    


}

