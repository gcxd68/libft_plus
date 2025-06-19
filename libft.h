/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:18:52 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/02 17:04:41 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
//# include <string.h>
# include <time.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define PRINTF_BUFFER_SIZE 4096

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dynarr
{
	size_t			size;
	size_t			capacity;
	size_t			elem_size;
}	t_dynarr;

int			ft_atoi(const char *nptr);
int			ft_atoi_base(const char *nptr, char *base);
long		ft_atol(const char *nptr);
long long	ft_atoll(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_dprintf(int fd, const char *format, ...)
			__attribute__((format(printf, 2, 3)));
char		ft_dynarr_add_char(char **arr, char value);
int			ft_dynarr_add_int(int **arr, int value);
void		*ft_dynarr_add_ptr(void ***arr, void *value);
void		ft_dynarr_free(void *arr);
void		*ft_dynarr_from(void *static_arr, size_t elem_size, size_t count);
void		*ft_dynarr_init(size_t elem_size, size_t capacity);
void		ft_dynarr_remove(void **arr_ptr, size_t index);
void		ft_free_arr(void ***arr);
void		ft_free_int_arr(int ***arr, size_t size);
int			ft_int_arr_get(const int *arr, size_t size,
				size_t idx, int def_value);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_rand(int min, int max);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int			ft_snprintf(char *str, size_t size, const char *format, ...)
			__attribute__((format(printf, 3, 4)));
char		**ft_split(char const *s, char c);
int			ft_sprintf(char *str, const char *format, ...)
			__attribute__((format(printf, 2, 3)));
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(char *s);
int			ft_stricmp(const char *s1, const char *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_ternary(bool condition, void *true_val, void *false_val);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_vprintf(const char *format, va_list args);
int			ft_vsnprintf(char *str,
				size_t size, const char *format, va_list args);
int			ft_vsprintf(char *str, const char *format, va_list args);
char		*get_next_line(int fd);

#endif
