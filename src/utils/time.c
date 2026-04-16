/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 08:49:17 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/16 08:22:19 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	get_time(void)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	return (v.tv_sec * 1000 + v.tv_usec / 1000);
}

void	ft_usleep(long milisec, t_data *data)
{
	long	start;
	int		d;

	pthread_mutex_lock(&data->dead_mutex);
	d = data->dead;
	pthread_mutex_unlock(&data->dead_mutex);
	start = get_time();
	while (!d)
	{
		if (get_time() - start >= milisec)
			break ;
		usleep(100);
		pthread_mutex_lock(&data->dead_mutex);
		d = data->dead;
		pthread_mutex_unlock(&data->dead_mutex);
	}
}
