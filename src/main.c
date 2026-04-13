/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/12 23:55:59 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void launch_thread(t_input *input)
{
	int	i;
	int	n;
	t_philo philo[input->nbr_philos];

	i = 0;
	n = input->nbr_philos;
	while (i < n)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].thread, NULL, boulot_dodo, &philo[i]);
		i++;
	}
	write(1, "END CREATE\n", 11);
	i = 0;
	while (i < n)
		pthread_join(philo[i++].thread, NULL);
	write(1, "END JOIN\n", 9);
}

int	main(int ac, char **av)
{
	t_data data;

	if (!verify_input(ac, av))
		return (1);
	init_input(&data, ac, av);
	if (!init_forks(&data))
		return (error(0), 1);
	if (!init_philos(&data))
		return (error(0), 1);
	// launch_thread(&input);
	write(1, "END MAIN\n", 9);
	return (0);
}
