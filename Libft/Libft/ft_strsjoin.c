#include <stdarg.h>
#include <stddef.h>
#include "list.h"
#include "libft.h"

size_t ft_list_strstrlen(t_list **alst)
{
    t_list *lst;
    size_t count = 0;

    if (alst == NULL || *alst == NULL)
        return 0;

    lst = *alst;
    while (lst != NULL)
    {
        count += ft_strlen((char *)(lst->content));
        lst = lst->next;
    }

    return (count+1);
}


char *ft_strsjoin(int count, ...)
{
    va_list ap;
    t_list *lst;
    t_list **alst;
    int i = 1;

    size_t size = 0;

    char *str = NULL;

    if (count <= 0)
        return NULL;

    va_start(ap, count);

    lst = ft_lstnew(ft_strdup(va_arg(ap, char*)));
    if (lst == NULL)
        return NULL;
    alst = &lst;

    while(i < count)
    {
        char *s = va_arg(ap, char*);
        if (s == NULL)
        {
            ft_lstclearall(alst, &free);
            return NULL;
        }
        ft_lstadd_back(alst, ft_lstnew(ft_strdup(s)));
        i++;
    }

    size = ft_list_strstrlen(alst);

    str = (char*) malloc((sizeof(char) * size) + 1);
    if (str == NULL)
    {
        ft_lstclearall(alst, &free);
        return NULL;
    }

    str[0] = '\0';  // initialiser str avec une chaîne vide
    str = ft_listtostr(alst, str);

    ft_lstclearall(alst, &free);

    return str;
}
