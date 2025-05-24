/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:18:14 by mateoandre        #+#    #+#             */
/*   Updated: 2025/04/28 11:51:47 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long int ptr)
{
	int	rtn_val;

	rtn_val = 0;
	rtn_val = print_str("0x");
	rtn_val += hexa_lowercase(ptr, 0);
	return (rtn_val);
}
