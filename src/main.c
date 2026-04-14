/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 08:17:06 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!verify_input(ac, av))
		return (1);
	init_input(&data, ac, av);
	init_data(&data);
	if (!init_forks(&data))
		return (free_data(&data), 1);
	if (!init_philos(&data))
		return (free_data(&data), 1);
	if (!launch_threads(&data))
		return (free_data(&data), 1);
	join_threads(&data);
	free_data(&data);
	return (0);
}
