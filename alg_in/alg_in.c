#include "libft.h"
#include "list.h"
#include "lem_list.h"
#include "alg_in.h"

size_t lem_waylen(lem_p **way)
{
    size_t i = 0;

    if(!way)
        return 0;
    while(way[i++] != NULL)
        i++;
    return i;

}

void set_new_way(lem_p **way, lem_p *lemp)
{
    size_t i = 0;
    lem_p **way_bis = NULL;

    size_t waylen = NULL;

    if(!way || !lemp)
        return;

    waylen = lem_waylen(way);

    if(!(way_bis = (lem_p**) malloc(sizeof(lem_p*) * waylen + 2)))
        return;

    while(way[i])
    {
        way_bis[i] = way[i];
        i++;
    }
    free(way);

    way_bis[i] = lemp;
    way_bis[i+1] = NULL;

    i = 0;

    if(!(way = (lem_p**) malloc(sizeof(lem_p*) * waylen + 2)))
        return;

    while(way_bis[i])
    {
        way[i] = way_bis[i];
        i++;
    }
    free(way_bis);

    way[i] = 0;

}

lem_p **way_cp(lem_p **way)
{
    lem_p **new = NULL;
    size_t waylen = 0;

    size_t i = 0;

    if(!way)
        return NULL;

    waylen = lem_waylen(way);

    if(!(new = (lem_p**) malloc(sizeof(lem_p*) * (waylen + 1))))
        return NULL;
    while(way[i])
    {
        new[i] = way[i];
        i++;
    }
    new[i] = NULL;

    return new;
}

lem_fi *finder_new_pathlist(lem_p **way)
{
    lem_fi* finder = NULL;

    finder = NULL;
}