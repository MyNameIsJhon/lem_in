#include "libft.h"
#include "list.h"

t_list *ft_lstnew(void *content)
{
    t_list *lst;

    lst = (t_list*) malloc(sizeof(t_list));

    if(!content || !lst)
        return NULL;

    lst->content = content;
    lst->next = NULL;

    return (lst);
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if(!alst || !new)
        return;
    new->next = *alst;
    alst = &new;
}

size_t ft_lstsize(t_list *lst)
{
    t_list *curs;
    size_t i = 0;

    curs = lst;

    while(curs->next != NULL)
    {
        curs = curs->next;
        i++;
    }
    return (i);
}

t_list *ft_lstlast(t_list *lst)
{
    t_list *curs;

    curs = lst;

    while(curs->next != NULL)
        curs = curs->next;
    return (curs);
}

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *curs = ft_lstlast(*alst);

    if(!alst || !new)
        return;
    
    curs->next = new;
    new->next = NULL;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(!lst || !del)
        return;
    
    (del)(lst->content);
    free(lst);
}

void ft_lstclear(t_list **alst)
{
    t_list *curr;
    t_list *tmp;

    if(!alst)
        return;
    
    curr = *alst;

    while(curr)
    {
        tmp = curr;
        curr = curr->next;
        if(tmp != NULL)
            free(tmp);
        tmp = curr;
    }
}
void ft_lstclearall(t_list **alst, void (*f)(void*))
{
    t_list *curr;
    t_list *tmp;

    int i = 0;

    if(!alst || !f)
        return;
    
    curr = *alst;

    while(curr)
    {
        tmp = curr;
        f(curr->content);
        curr = curr->next;
        free(tmp);
        i++;
    }
    *alst = NULL;
}

void ft_lstiter(t_list *lst, void (*f)(void*))
{
    t_list *curr;

    if(!lst || !f)
        return;
    while(curr)
    {
        (f)(curr->content);
        curr = curr->next;
    }
}

char *ft_listtostr(t_list **alst, char *str)
{
    t_list *lst;

    if (alst == NULL || *alst == NULL || str == NULL)
        return NULL;

    lst = *alst;
    while (lst != NULL)
    {
        ft_strcat(str, (char *)(lst->content));
        lst = lst->next;
    }

    return str;
}

char **ft_lst_to_argv(t_list **alst)
{
    char **argv;
    size_t argv_len;
    size_t len = 0;

    t_list *lst;

    size_t y = 0;
    size_t i = 0;

    if(!(alst))
        return NULL;
        
    lst = *alst;    
    argv_len = ft_lstsize(*alst) + 1;

    if(!(argv = (char**) malloc(sizeof(char*) * (argv_len + 1))))
        return NULL;
    while(y < argv_len && lst != NULL)
    {
        argv[y] = ft_strdup((char*) lst->content);
        lst = lst->next;
        y++;
    }
    argv[y] = NULL;

    return argv;
}

t_list *ft_lstcp(t_list **alst)
{
    t_list *lst = NULL;
    t_list *new_lst = NULL;
    t_list *new_node = NULL;
    
    if (!alst || !(*alst))
        return NULL;
    
    lst = *alst;

    new_lst = ft_lstnew(lst->content);

    if (!new_lst)
        return NULL;

    lst = lst->next;

    while (lst != NULL)
    {
        new_node = ft_lstnew(lst->content);

        if (!new_node)
        {
            ft_lstclear(&new_lst);
            return NULL;
        }

        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }

    return new_lst;
}

t_list *ft_lst_finder_wnb(int POS, size_t nb, t_list **alst)
{
    t_list *lst = NULL;
    size_t lst_len = 0;
    unsigned int lst_pos = 0;

    if(!(*alst))
        return lst;

    lst = *alst;

    if(POS == 0)//équivalent à START
    {
        while(lst->next != NULL && nb-- >= 0)
            lst = lst->content;
    }
    else if(POS == 1)
    {
        lst_len = ft_lstsize(&lst);
        lst_pos = lst_len - nb;

        while(lst_pos-- && lst != NULL)
            lst = lst->next;
    }
    else
        ft_pustr("vous avez introduis la mauvaise value\n");

    return lst;
}
