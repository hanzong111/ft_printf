/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:20:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 19:36:05 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char *str = "%-123%";
	t_flags	flags;

	ft_initializeflags(&flags);
	ft_checks(str, 1, &flags);
	printf("Your '-' flag is %d\n",flags.minus);
	printf("Your '%%' flag is %d\n",flags.percent);
	ft_print(&flags, str, 0);
}
