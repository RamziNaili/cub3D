/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:39:32 by asalam            #+#    #+#             */
/*   Updated: 2021/02/25 16:09:07 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    200
# endif

void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *destination,
		const void *source, size_t size);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int a);
int					ft_isalnum(int a);
int					ft_isascii(int a);
int					ft_isprint(int a);
int					ft_toupper(int a);
int					ft_tolower(int a);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *string, int searchedchar);
int					ft_strncmp(char *s1, char *s2, int n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(char *fullstring, char *substring, int n);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
		void *(*f)(void *), void (*del)(void *));

char				*ft_save_line(char *line, char **str);
int					get_next_line(int fd, char **line);
char				*ft_strjoin_gnl(char *str, char *buf);
char				*ft_save_end(char *str);
char				*ft_split_back(char *str);
int					ft_line_indice(char *str);
char				*ft_strdup(char *str);

typedef struct		s_flags
{
	char			zero;
	int				moins;
	int				chifre;
	int				point;
}					t_flags;

int					ft_printf(const char *s, ...);
int					ft_caracter(char c, t_flags stru);
void				ft_norm(int *sign);
int					ft_digit(int nbr, t_flags stru, int printed_car);
void				ft_fill_struct(t_flags *stru, char *str,
		int *i, va_list ap);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_print(char c, int size);
int					ft_hexa(unsigned int nbr, t_flags stru, int printed_car);
int					ft_hexadecimal(unsigned int nbr,
		t_flags stru, int printed_car);
int					ft_percent(t_flags stru);
int					ft_pointeur(unsigned long long a, t_flags stru);
int					ft_types(char c, void *ap, t_flags stru);
void				ft_initialize_stru(t_flags *stru);
int					ft_hexa_len(unsigned int nbr);
int					ft_stop(char c);
int					ft_string(char *str, t_flags stru);
int					ft_unsigned(unsigned int nbr,
		t_flags stru, int printed_car);

#endif
