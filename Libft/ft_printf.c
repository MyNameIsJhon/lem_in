#include "libft.h"
#include "list.h"

char *pointer_create(char *str)
{
    char *pointt;

    if(!(pointt = (char*) malloc(sizeof(char) * (ft_strlen(str) + 1)))) // +1 pour inclure le caractère de fin de chaîne '\0'
        return NULL;
    
    ft_strcpy(pointt, str);
    
    return (pointt);
}


void ft_printf(char *str, ...)
{
    t_list **alst = NULL;
    t_list *lst;
    va_list ap;

    int i = 0;
    int z = 0;

    int g = 0;

    va_start(ap, str);

    while(str[i])
    {
        if(str[i] == '%' && str[i+1] != '%' && str[i-1] != '%')
        {
            switch(str[i+1]){

                case 'd':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    break;

                case 'D':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    break;

                case 's':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(pointer_create(va_arg(ap, char*))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(pointer_create(va_arg(ap, char*)));
                        alst = &lst;
                    }
                    break;
                
                case 'S':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(pointer_create(va_arg(ap, char*))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(pointer_create(va_arg(ap, char*)));
                        alst = &lst;
                    }
                    break;

                case 'o':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int)))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int))));
                        alst = &lst;
                    }
                    break;

                case 'O':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int)))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int))));
                        alst = &lst;
                    }
                    break;
                
                case 'u':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    break;
                
                case 'U':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    break;

                case 'c':
                    char *c = (char*) malloc(sizeof(char) * 1);
                    int lt = va_arg(ap, int);
                    c = (char*) &lt;
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(c));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(c);
                        alst = &lst;
                    }
                    break;
                
                
                
                /*case 'p'://error
                {
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(st));
                    else if(z == 0)
                    {
                        void *point = va_arg(ap, void*);
                        int nb = &point;
                        lst = ft_lstnew(ft_itoa((point)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                }
                    */
            }
            z++;
        }
        i++;
    }

    lst = *alst;

    while(str[g])
    {
        reloader:
        while(str[g] && str[g] != '%')
            ft_putchar(str[g++]);
        if(str[g+1] == '%')
            goto reloader;
        while(str[g] != 'u' && str[g] != 'U' && str[g] != 'd' && str[g] != 'D' && str[g] != 'u' && str[g] != 'U' && str[g] != 's' && str[g] != 'S' && str[g] != 'o' && str[g] != 'O' && str[g] != 'c' && str[g])
            g++;
        if(str[g] && lst != NULL)
        {
            g++;
            ft_putstr((char*) lst->content);
            lst = lst->next;
        }
        
    }


    ft_lstclearall(alst, &free);

    va_end(ap);
}

