/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:42:49 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:30:04 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_var
{
	int		ver;
	char	*buffer;
	char	*temp;

}			t_var;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//---------------------------character------------------------------//
int		ft_isalnum(int c);
int		ft_isalpha(int a);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int arg);
//---------------------------ft_printf------------------------------//
int		ft_printf_fd(int fd, const char *type, ...);
int		ft_printfc_fd(int c, int fd);
int		ft_printfs_fd(char *str, int fd);
int		ft_printfp_fd(void *p, int fd);
int		ft_printfd_fd(int n, int fd);
int		ft_printfu_fd(unsigned int n, int fd);
int		ft_printfx_fd(unsigned int n, int fd);
int		ft_printfxx_fd(unsigned int n, int fd);
//------------------------------GNL---------------------------------//
char	*get_next_line(int fd);
//-----------------------------list---------------------------------//
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
//-----------------------------mem----------------------------------//
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_realloc(void *pointer, size_t len, size_t size);
void	*ft_xfree(void *pointer);
void	*ft_xxfree(void **pointer);
//---------------------------number---------------------------------//
double	ft_atof(char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
//---------------------------string---------------------------------//
int		ft_searchstr(char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
//----------------------------write---------------------------------//
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif