/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 07:08:17 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 09:02:10 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	launch_threads(t_data *data)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = data->input.nbr_philos;
	while (i < n)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&boulot_dodo, &data->philos[i]) != 0)
		{
			data->dead = 1;
			j = 0;
			while (j < i)
				pthread_join(data->philos[j++].thread, NULL);
			return (err(6), 0);
		}
		i++;
	}
	if (!launch_checker(data))
		return (0);
	return (1);
}

int	launch_checker(t_data *data)
{
	int	i;
	int	n;

	n = data->input.nbr_philos;
	if (pthread_create(&data->checker, NULL,
			&check_death, data) != 0)
	{
		data->dead = 1;
		i = 0;
		while (i < n)
			pthread_join(data->philos[i++].thread, NULL);
		return (err(6), 0);
	}
	return (1);
}

void	join_threads(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->input.nbr_philos;
	while (i < n)
		pthread_join(data->philos[i++].thread, NULL);
	pthread_join(data->checker, NULL);
}
