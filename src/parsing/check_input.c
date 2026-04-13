/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/12 23:41:43 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	verify_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (err(1), 0);
	while (i < ac)
	{
		if (is_non_digit(av[i]))
			return (err(2), 0);
		if (is_nbr_overflow(av[i]))
			return (err(3), 0);
		if ((i != 5) && is_only_zero(av[i]))
			return (err(4), 0);
		i++;
	}
	return (1);
}

void	err(int e)
{
	if (e == 1)
		write(2, "Error: Only 4 or 5 arguments are accepted\n", 42);
	else if (e == 2)
		write(2, "Error: only digits are allowed\n", 31);
	else if (e == 3)
		write(2, "Error: number out of range\n", 27);
	else if (e == 4)
		write(2, "Error: number cannot be zero except for arg[6]\n", 48);
	else
		write(2, "Error malloc\n", 13);
}