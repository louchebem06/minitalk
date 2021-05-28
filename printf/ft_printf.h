/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:00:05 by bledda            #+#    #+#             */
/*   Updated: 2021/04/22 16:53:16 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *input, ...);
char	*ft_itoh(unsigned long long nb);
void	ft_strrev(char *str);
char	*ft_strtoupper(char *str);
char	*ft_strtolower(char *str);
void	ft_before_data(int start, int size, char charset, unsigned int *cmp);
int		ft_isconvert(char charset);
char	*ft_strreplace(char *mainstr, char charset, char *replace);
int		ft_strchrintab(char *str, char a, char b);
void	ft_putnstr(char *str, int n);
void	ft_flagsjoin(int *flags_value, va_list args, char *flags);
char	*ft_uitoa(unsigned int n);
void	ft_flags(char *flags, char *input, int *a);
void	ft_check_c(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_percent(char input, int *flags_value, unsigned int *cmp);
void	ft_check_s(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_p(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_di(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_u(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_check_xX(char input, va_list args, int *flags, unsigned int *cmp);
void	ft_flags_di_minus(unsigned int *cmp, int *flags, int neg, char *str);
void	ft_flags_di_clear(unsigned int *cmp, int *flags, int neg, char *str);
void	ft_flags_di_zero(unsigned int *cmp, int *flags, int neg, char *str);
void	ft_flags_di_zero_min(unsigned int *cmp, int *flags, int neg, char *str);
int		ft_isneg_di(int neg, unsigned int *cmp);
void	ft_just_print(int neg, unsigned int *cmp, char *str);
void	ft_space_neg(size_t f, int flags, int neg, unsigned int *cmp);
void	ft_zero_neg(size_t f, int flags, int neg, unsigned int *cmp);
void	ft_print_and_f_size(size_t *f, char *str);
void	ft_flags_di(int *flags, unsigned int *cmp2, int neg, char *str);
void	ft_f_size(size_t *f, int flags, char *str);
int		ft_str_is_zero(char *str);
void	ft_print_zero_str_and_f_size(int flags, size_t *f, char *str);
void	ft_print_zero_str(int neg, unsigned int *cmp, int flags, char *str);
int		ft_print_space_str(int neg, unsigned int *cmp, int flags, char *str);
void	ft_print_zero_if(int *flags, char *str, size_t f, unsigned int *cmp);
void	ft_prt_zer_str_spc(int *flags, char *str, size_t *f, unsigned int *cmp);
void	ft_zero_or_str(size_t *f, char *str, int *flags);

#endif