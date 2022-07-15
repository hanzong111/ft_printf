/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:02:49 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 16:43:43 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include"libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		wc;
	int		width;
	int		index;
	int		c;
	int		s;
	int		p;
	int		d;
	int		i;
	int		u;
	int		x;
	int		capx;
	int		percent;
	int		start;
	int		end;
	int		strlen;
	char	*substr;
	int		precision;
}	t_flags;

void	ft_initializeflags(t_flags *var);
void	ft_checks(char	*str, int index, t_flags *flags);
int		ft_concheck(char c, t_flags *type);
int		ft_concheck1(char c, t_flags *type);
int		ft_concheck2(char c, t_flags *type);
int		ft_concheck3(char c, t_flags *type);
void	ft_flagscheck(char c, char d, t_flags *flags);
void	ft_print(t_flags *flags, char *str, int index, va_list args);
void	ft_print_percent(t_flags *flags, char *str, int index);
void	ft_print_char(t_flags *f, char *str, int index, int c);
void	ft_print_str(t_flags *f, char *str, int index, char *args);
int		ft_printf(char	*str, ...);
void	ft_precision_width(t_flags *f, char *str, int index);
void	ft_print_null(t_flags *f, char *str, int index);

#endif