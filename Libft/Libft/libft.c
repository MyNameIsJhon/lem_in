#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"


void ft_memset(void *b, int c, size_t n)
{
    unsigned char *str = (unsigned char*) b;
    size_t i;

    for (i = 0; i < n; i++) {
        str[i] = (unsigned char) c;
    }
}


void ft_bzero(void *b, size_t n)// initialise toutes cles cases d'un tableau 
{
    unsigned char *str = (unsigned char*) b;

    while(n--)
        *str++ = '\0';
}

void *ft_memcpy(void *dest, void *src, size_t n) // me permet de copier les bites d'un tableau à un autre avec une limite de n 
{
    unsigned char* dest_bis = (unsigned char*) dest;
    unsigned char* src_bis = (unsigned char*) src;

    while(n--)
        *dest_bis++ = *src_bis++; 

    return dest;
}

void *ft_memccpy(void *dest, void *src, int c, size_t n)// me permet de copier les bites d'un tableau à un autre avec une limite de n en permettant de stopper lors de la rencontres d'un bite specifiaue
{
    int i = 0;
    unsigned char* dest_bis = (unsigned char*) dest;
    unsigned char* src_bis = (unsigned char*) src;

    while(n--)
    {
        dest_bis[i] = src_bis[i];
        if(dest_bis[i] == (unsigned char) c)
            return (void*) dest + i + 1; 
    }
        

    return dest;
}

void	*ft_memmove(void *dst, const void *src, size_t n)//similaire a memccpy mais en evitant le chevauchement(bites) 
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = n;
	if (src == 0 && dst == 0)
		return (0);
	if (ptr_dst > ptr_src && ptr_dst < (ptr_src + n))
		while (n > 0)
		{
			ptr_dst[n - 1] = ptr_src[n - 1];
			n--;
		}
	else
	{
		i = -1;
		while (++i < n)
			ptr_dst[i] = ptr_src[i];
	}
	return (dst);
}

const void *ft_memchr (const void *ptr, int c, size_t n)//rechercche caractere dans string (bites)
{
    unsigned char *str = (unsigned char*) ptr;
    int i = 0;

    while(i < n)
    {
        if(str[i] == (char) c)
            return &str[i];
        i++;
    }
    
    return NULL;
}

int ft_memcmp(const void *str1, const void* str2, size_t n)
{
    int i = 0;
    unsigned char *ptr_str1 = (unsigned char*) str1;
    unsigned char *ptr_str2 = (unsigned char*) str2;

    while(i < n)
    {
        if(ptr_str1[i] != ptr_str2[i])
            return ptr_str1[i] - ptr_str2[i];
        i++;
    }
    return 0;
}

size_t ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return i;
}

char *ft_strdup(const char *s)// me crée une chaine de caractere alloué (important de free !)
{
    char *str;
    int i = 0;
    size_t n = ft_strlen((char*) s);

    if(!(str = (char*) malloc((sizeof(char) * n) + 1)))
        return NULL;
    ft_memmove((void*) str, (const void*) s, n);

    str[n] = '\0';
    
    return str;
}

char *ft_strcpy(char *dest, const char *src)// copie src dans dest (char)
{
    ft_memset((void*) dest, (int) '\0', ft_strlen((char*) src) + 1);
    ft_memcpy((void*) dest, (void*) src, ft_strlen((char*) src) + 1);

    return dest;
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    ft_memset((void*) dest, (int) '\0', n);
    ft_memmove(dest, src, n);
    return dest;
}

char *ft_strcat(char *dest, const char *src) 
{
    char *tmp = dest;

    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }

    *dest = '\0';

    return tmp;
}

char *ft_strncat(char *dest, const char *src, size_t n) 
{
    char *tmp = dest;

    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0' && n--) {
        *dest++ = *src++;
    }

    *dest = '\0';

    return tmp;
}

size_t ft_strlcat(char *dest, const char *src, size_t size) //concatene avec plus de securité strncat car joins en tenant compte de longueur total de deux chaines
{
    
    size_t dest_len = ft_strlen((char*) dest);
    size_t src_len = ft_strlen((char*) src);

    size_t i = 0;

    if (size <= dest_len) {
        return size + src_len;
    }

    while (src[i] != '\0' && dest_len + i < size - 1) {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len + i] = '\0';
    return dest_len + src_len;
}

char *ft_strchr(const char *str, char c)//recherche premiere occurence d'un caract
{
    while(*str++ != '\0')
    {
        if(*str == c)
            return (char*) str;
    }

    return NULL;
}

char *ft_strrchr(const char *str, char c)//recherche derniere occurence d'un caract
{
    char *last = NULL;

    while(*str++ != '\0')
    {
        if(*str == c)
            last = (char*) str;
    }

    return last;
}

char *ft_strstr(const char *str, const char *str2)
{
    int i = 0;
    size_t str2_len = (size_t) ft_strlen((char*) str2);

    while(*str != '\0')
    {
        if(*str == str2[i])
            i++;
        else
            i = 0;
        if(i == str2_len)
            return (char*) str - str2_len;
        str++;
    }

    return NULL;
}

char *ft_strnstr(const char *str, const char *str2, size_t n)
{
    int i = 0;
    size_t str2_len = (size_t) ft_strlen((char*) str2);

    if(str2_len > n)
        return NULL;
    while(*str != '\0')
    {
        if(*str == str2[i])
            i++;
        else
            i = 0;
        if(i == str2_len)
            return (char*) str - str2_len;
        str++;
    }
    
    return NULL;
}

int ft_strcmp(const char *str, const char *str2)
{
    while (*str && *str2) 
    {
        if (*str != *str2)
            return *str - *str2;
        str++;
        str2++;
    }

    return *str - *str2;
}

int ft_strncmp(const char *str, const char *str2, size_t n)
{
    n = n-1;

    while (str[n] && str2[n] && n >= 0) 
    {
        if(str[n] != str2[n])
            return str[n] - str2[n];
        n--;
    }

    return str2[n] - str[n];
}


int ft_isalpha(const char c)
{
    if(!((c >=  'a' && c <=  'z') || (c >=  'A' && c <=  'Z')))
        return 0;
    return 1;    
}

int ft_isdigit(const char c)
{
    if(!(c>=  '0' && c <=  '9'))
        return 0;
    return 1; 
}

int ft_isalnum(const char c)
{
    if(!(c >=  '0' && c <=  '9') && !((c >=  'a' && c <=  'z') || (c >=  'A' && c<=  'Z')))
        return 0;
    return 1; 
}

int ft_isprint(const char c)
{
    
    if(!(c >=  32 && c <=  126))
        return 0;
    return 1; 
}

int ft_isascii(const char c)
{
    if(!(c >=  0 && c <=  127))
        return 0;
    return 1; 
}

char ft_toupper(char c)
{
    if(!(ft_isalpha((const char) c)))
        return 0;
    
        c -= 32;

    return c;
}

char ft_tolower(char c)
{
    if(!(ft_isalpha((const char) c)))
        return 0;
    
        c += 32;

    return c;
}

void ft_str_tolower(char *str)
{
    while(*str)
    {
        if(*str >= 'A' && *str <= 'Z')
            *str += 32;
        *str++;
    }
}

void *ft_memalloc(size_t size)
{
    void *ptr;

    if(!(ptr = malloc(size)))
        return NULL;
    ft_memset(ptr, 0, size);
}

void ft_memdel(void **ptr)
{
    free(*ptr);
    *ptr = NULL;
}

void ft_strclr(char *str)
{
    ft_bzero((void*) str, ft_strlen(str));
}

char *ft_strnew(size_t n)
{
    char *str = NULL;

    if(!(str = (char*) malloc(n * sizeof(char))))
        return NULL;
    ft_bzero((void*) str, n);

    return str;
}

void ft_strdel(char *str)
{
    free(str);
    str = NULL;
}

void ft_striter(char *str, void (*f)(char*))
{
    while(*str) {
        (*f)(str);
        str++;
    }
}

char *strmap(char *str, void (*f)(char*))
{
    while(*str) {
        (*f)(str);
        str++;
    }

    return str;
}

char *ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
    size_t len = ft_strlen((char*) str);
    char *alloc = (char*) malloc(sizeof(char) * (len + 1));

    if (!alloc) {
        return NULL;
    }
    for (unsigned int i = 0; i < len; i++) {
        alloc[i] = (*f)(i, str[i]);
    }
    
    alloc[len] = '\0';
    return alloc;
}

int ft_strequ(char const *s1, char const *s2)
{
    if (!s1 || !s2) 
        return 0;
    while (*s1 || *s2)
    {
        if (*s1 != *s2) 
            return 0;
        s1++; 
        s2++; 
    }

    return 1;
}

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    if (!s1 || !s2) 
        return 0;
    while ((i < n) && (*s1 || *s2)) 
    {
        if (*s1 != *s2) 
            return 0;
        s1++; 
        s2++; 
        i++;
    }

    return 1; 
}

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *sub = (char *)malloc((len + 1) * sizeof(char)); 

    if (!s || !sub) 
        return NULL;
    for (size_t i = 0; i < len; i++) 
        sub[i] = s[start + i];
    sub[len] = '\0'; 

    return sub;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = ft_strlen((char*) s1);
    size_t len2 = ft_strlen((char*) s2);
    char *new_str = (char *)malloc((len1 + len2 + 1) * sizeof(char)); // Allouer de la mémoire pour la nouvelle chaîne

    if (!s1 || !s2 || !new_str) 
        return NULL;
    ft_memcpy((void*) new_str, (void*) s1, len1); 
    ft_memcpy((void*) new_str + len1, (void*) s2, len2 + 1);

    return new_str; 
}

static int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char *ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);

	start = 0;
	end = ft_strlen((char*) s);

	while (ft_iswhitespace(s[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_iswhitespace(s[end - 1]))
		end--;
	return (ft_strsub(s, start, end - start));
}

static int	count_words(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*extract_word(char const **s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (**s == c)
		(*s)++;
	while ((*s)[len] != c && (*s)[len] != '\0')
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = '\0';
	*s += len;
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		nb_words;
	int		i;

	if (s == NULL)
		return (NULL);
	nb_words = count_words(s, c);
	split = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		split[i] = extract_word(&s, c);
		if (split[i] == NULL)
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
			}
		i++;
	}
	split[i] = NULL;
	return (split);
}

void ft_free_strsplit(char **split)
{
    int i = 0;

    while (split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}



void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(const char *str)
{
    int i = 0;

    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void  ft_putnbr(int nb)
{
    long i;

    i = nb;
    if (i < 0)
    {
        ft_putchar('-');
        i = i * (-1);
    }
    if (i > 9)
    {
        ft_putnbr(i / 10);
        ft_putnbr(i % 10);
    }
    else
    {
        ft_putchar(i + '0');
    }
}

int ft_atoi(char *str)
{
    int x = 0;
    int neg = 1;
    int nb = 0;

    if(!str)
        return 0;
    while(str[x] == '\t' || str[x] == '\v' || str[x] == '\n'||str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
        x++;
    while(str[x] == '-' || str[x] == '+')
    {
        if(str[x] == '-')
            neg *= -1;
        x++;
    }
    while(str[x] >= '0'&& str[x] <= '9')
    {
        nb = nb + str[x] - '0';
        
        if(str[x+1] >= '0' && str[x+1] <= '9')
            nb *= 10;
        x++;
    }
    nb *= neg;
    return nb;
}

static size_t   number_size(int n)
{
        size_t  size;

        size = 0;
        if (n <= 0)
                size++;
        while (n != 0)
        {
                n /= 10;
                size++;
        }
        return (size);
}

char    *ft_itoa(int n)
{
    char    *res;
    int             sign;
    size_t  i;

    i = number_size(n);
    sign = 1;
    res = malloc(sizeof(*res) * (i + 1));
    if (!res)
        return (0);
    res[i] = 0;
    i--;
    if (n < 0)
    {
        sign *= -1;
        res[0] = '-';
    }
    if (n == 0)
        res[i] = '0';
    while (n != 0)
    {
        res[i] = ((n % 10) * sign) + 48;
        n /= 10;
        i--;
    }
    return (res);
}

int ft_octal(int nb)
{
    int e = 1;
    int y = 0;
    int i = 0;
    int final = 0;;

    int *octal;

    while(e >= nb)
    {
        e*=10;
        y++;
    }
    if(!(octal = (int*) malloc(sizeof(int) * y)))
        return 0;
    while(nb != 0)
    {
        octal[i++] = nb % 8;
        nb /= 8;
    }
    while(i >= 0)
    {
        final *= 10;
        final += octal[i--];
    }
    
    free(octal);

    return final;
}

char    *ft_unsigned_itoa(unsigned int n)
{
    char    *res;
    size_t  i;

    i = number_size(n);
    res = malloc(sizeof(*res) * (i + 1));
    if (!res)
        return (0);
    res[i] = 0;
    i--;
    if (n == 0)
        res[i] = '0';
    while (n != 0)
    {
        res[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return (res);
}


size_t ft_chrlen(const char *str, char c)//copie jusqu'à renconté un char specifique
{
    size_t i = 0;

    if(!str || !c)
        return 0;
    while(str[i] != c && str[i])
        i++;
    return i;
}

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}


void ft_putstr_fd(char const *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    if (n > 9)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd(n % 10 + '0', fd);
}