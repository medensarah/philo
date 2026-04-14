/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 06:51:35 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 06:52:40 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	launch_threads(t_input *input)
{
	int		i;
	int		n;
	t_philo	philo[input->nbr_philos];

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
