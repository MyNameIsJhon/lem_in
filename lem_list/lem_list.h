#ifndef LEM_LIST
#define LEM_LIST

typedef struct lem_points{

    size_t x;
    size_t y;

    char *name;
    int startorend; //de 0 à 2, 0 pour salle normal, 1 pour entrée, 2 pour end

    struct lem_points *next;

}lem_p;

lem_p *new_lem_point(size_t x, size_t y, char *name, int stoend);
lem_p *lem_last(lem_p *lemp);
void lem_add_back(lem_p **alemp, lem_p *new);


#endif