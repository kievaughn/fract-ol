/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:58:54 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/13 13:00:34 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t				ft_strlen(char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *src);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(char c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				*ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memchr(const void *s, int c, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int				ft_printf(const char *s, ...);
int				ft_putnbr(int n);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr_u(unsigned int n);
int				ft_puthex(unsigned long int n);
int				ft_puthexcaps(unsigned long int n);
int				ft_putptr(void *ptr);

#endif
