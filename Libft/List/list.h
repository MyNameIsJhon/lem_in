#ifndef LIST 
#define LIST LIST


typedef struct  s_list
{
    void *content ;
    struct s_list *next;
}               t_list;

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **alst, t_list *new);
size_t ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **alst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **alst);
void ft_lstclearall(t_list **alst, void (*f)(void*));
void ft_lstiter(t_list *lst, void (*f)(void*));
char *ft_listtostr(t_list **alst, char *str);
char **ft_lst_to_argv(t_list **alst);

#endif