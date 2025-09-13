/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:19:26 by mateoandre        #+#    #+#             */
/*   Updated: 2025/09/09 13:25:57 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief This function scalse two values in a given range in
/// = [1..2] -> [0..799]
/// @param unscaledNum 
/// @param minAllowed 
/// @param maxAllowed 
/// @param min 
/// @param max 
/// @return 
double	scaleBetween(double unscaledNum, double minAllowed, double maxAllowed, double min, double max)
{
  return ((maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed);
}