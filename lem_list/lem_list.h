#ifndef LEM_LIST
#define LEM_LIST

typedef struct lem_points{

    size_t x;
    size_t y;

    char *name;
    int startorend; //de 0 à 2, 0 pour salle normal, 1 pour entrée, 2 pour end

    size_t level;

    struct lem_points **pont; //ici seront tout les ponts disponibles sous formes de tableau de strings
    struct lem_points **used_pont;
    struct lem_points *next;

}lem_p;

lem_p *new_lem_point(size_t x, size_t y, char *name, int stoend);
lem_p *lem_last(lem_p *lemp);
void lem_add_back(lem_p **alemp, lem_p *new);
void ft_lemp_clearall(lem_p **alemp, void (*f)(void*));


#endif