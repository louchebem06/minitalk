/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:42:49 by bledda            #+#    #+#             */
/*   Updated: 2021/06/15 17:46:59 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char s2);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_iswhitespace(char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

#endif
