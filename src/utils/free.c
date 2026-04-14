/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:46:33 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 08:51:01 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	free_data(t_data *data)
{
	int	i;
	int	n;

	n = data->input.nbr_philos;
	if (data->forks)
	{
		i = 0;
		while (i < n)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		i = 0;
		while (i < n)
			pthread_mutex_destroy(&data->philos[i++].meal_mutex);
		free(data->philos);
		data->philos = NULL;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
}
