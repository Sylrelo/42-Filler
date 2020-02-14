/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:47:24 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:04:22 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** STRUCTURES
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}				t_color;
/*
** ------
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
char			*ft_strdup(const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_atoi(const char *str);
char			*ft_itoa(long long int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
/*
** MEM
*/
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
/*
** ETC
*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/*
** SUPL FUNCTIONS
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
/*
** --
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(long int nb);
/*
** FILE OPS
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
** OPTIONNALS
*/
int				ft_intlen(long long int n);
int				ft_lstsize(t_list *list);
t_list			*ft_lstat(t_list *list, size_t nbr);
/*
** BONUS
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_error(char *str);
void			ft_errusage(char *name, char *str);
void			ft_errmalloc(void);

int				ft_file_isspecial(char *name);
int				ft_file_ishidden(char *name);

void			ft_putstrfield(const char *str, int field, char justify);
int				ft_countwords(char const *str, char c);
int				ft_splitdel(char ***split);

void			ft_log(char *file, char *str);

void			ft_putfloat(float x, int p);
void			ft_printspace(int nb);

int				ft_dstrlen(char **str);
void			ft_printdstr(char **str);
int				ft_cpy_dstr(char ***dest, char **src);
int				ft_dstr_add(char ***dest, char *newvalue);
int				ft_dstr_getindex(const char **haystack, const char *needle);
int				ft_dstr_del(char ***dest, char *todelete);
void			ft_dstr_free(char **str);
int				ft_sqrt(int nb);
void			ft_swap(int *a, int *b);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
t_color			ft_hexrgb(int value);

#endif
