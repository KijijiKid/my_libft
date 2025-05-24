/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:38:36 by mandre            #+#    #+#             */
/*   Updated: 2025/04/28 10:54:03 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*get_error(void)
{
	static int	status = 0;

	return (&status);
}

void	set_error(int new_status)
{
	int	*status;

	status = get_error();
	*status = new_status;
}
