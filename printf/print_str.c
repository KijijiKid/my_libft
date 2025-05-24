/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:08:42 by mateoandre        #+#    #+#             */
/*   Updated: 2025/04/28 12:49:04 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	rtn_value;

	if (!str)
		return (print_str("(null)"));
	rtn_value = -1;
	while (str[++rtn_value])
		ft_putchar(str[rtn_value]);
	return (rtn_value);
}
