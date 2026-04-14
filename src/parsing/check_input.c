/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 02:45:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	verify_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		return (instruction(), 0);
	if (ac != 5 && ac != 6)
		return (err(1), 0);
	while (i < ac)
	{
		if (is_non_digit(av[i]))
			return (err(2), 0);
		if (is_nbr_overflow(av[i]))
			return (err(3), 0);
		if (is_only_zero(av[i]))
			return (err(4), 0);
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		return (err(5), 0);
	return (1);
}

void	instruction(void)
{
	write(2,
		"Usage: ./philo number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
		132);
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
		write(2, "Error: number cannot be zero\n", 29);
	else if (e == 5)
		write(2, "Error: too much philos in input (>200)\n", 38);
	else
		write(2, "Error malloc\n", 13);
}
