#ifndef LIBFT
#define LIBFT LIBFT

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>


void ft_memset(void *b, int c, size_t n);//set tout les bits d'un tableau ou chaine sur une valeur
void ft_bzero(void *b, size_t n);//set tout les bits sur '\0'
void *ft_memcpy(void *dest, void *src, size_t n);//copie tout les bits d'une chaine 'a une autre avec limite
void *ft_memccpy(void *dest, void *src, int c, size_t n);//pareil mais avec
void *ft_memmove(void *dst, const void *src, size_t n);//pareil mais en plus sur car evite le chevauchement de memoire
const void *ft_memchr (const void *ptr, int c, size_t n);//recherche bit dans une chaine et renvois l'addresse du bit correspondant ou NULL si rien n'est trouvé
int ft_memcmp(const void *str1, const void* str2, size_t n);
size_t ft_strlen(char *str);//compte caractere dans une chaine
char *ft_strdup(const char *s);
char *ft_strcpy(char *dest, const char *src);
char *ft_strncpy(char *dest, const char *src, size_t n);
char *ft_strcat(char *dest, const char *src);
char *ft_strncat(char *dest, const char *src, size_t n);
size_t ft_strlcat(char *dest, const char *src, size_t size);
char *ft_strchr(const char *str, char c);
char *ft_strrchr(const char *str, char c);
char *ft_strstr(const char *str, const char *str2);
char *ft_strnstr(const char *str, const char *str2, size_t n);
int ft_strcmp(const char *str, const char *str2);
int ft_strncmp(const char *str, const char *str2, size_t n);
int ft_isalpha(const char c);
int ft_isdigit(const char c);
int ft_isalnum(const char c);
int ft_isprint(const char c);
int ft_isascii(const char c);
char ft_toupper(char c);
char ft_tolower(char c);
void ft_str_tolower(char *str);
void *ft_memalloc(size_t size);
void ft_memdel(void **ptr);
void ft_strclr(char *str);
char *ft_strnew(size_t n);
void ft_strdel(char *str);
void ft_striter(char *str, void (*f)(char*));
char *strmap(char *str, void (*f)(char*));
char *ft_strmapi(char const *str, char (*f)(unsigned int, char));
int ft_strequ(char const *s1, char const *s2);
int ft_strnequ(char const *s1, char const *s2, size_t n);
char *ft_strsub(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);
void ft_free_strsplit(char **split);
void ft_putchar(char c);
void ft_putstr(const char *str);
void  ft_putnbr(int nb);
int ft_atoi(char *str);
static size_t  number_size(int n);
char    *ft_itoa(int n);
int ft_octal(int nb);
char    *ft_unsigned_itoa(unsigned int n);

void ft_printf(char *str, ...);
char *ft_strsjoin(int count, ...);

void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char const *s, int fd);
void ft_putnbr_fd(int n, int fd);

int ft_get_next_line(int fd, char **line);
char *strdup_chr(const char *str, char c);


size_t ft_chrlen(const char *str, char c);//copie jusqu'à renconté un char specifique

#endif