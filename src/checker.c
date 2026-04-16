/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 07:05:22 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/16 09:41:58 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->dead)
	{
		i = 0;
		while (i < data->input.nbr_philos && !data->dead)
		{
			if (has_philo_died(data, &data->philos[i]))
				return (NULL);
			i++;
		}
		if (data->limit_mode
			&& (data->philos_finished == data->input.nbr_philos))
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

int	has_philo_died(t_data *data, t_philo *philo)
{
	long	now;
	long	last_meal;

	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	now = get_time();
	if (now - last_meal >= data->input.time_to_die)
	{
		pthread_mutex_lock(&data->print_mutex);
		if (!data->dead)
		{
			printf("%ld %d died\n",
				now - data->start_time, philo->id);
			data->dead = 1;
		}
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

// void    *check_death(void *arg)
// {
//     t_data  *data = (t_data *)arg;
//     int     i;
//     int     d;

//     while (1)
//     {
//         // Lire dead de manière thread-safe
//         pthread_mutex_lock(&data->dead_mutex);
//         d = data->dead;
//         pthread_mutex_unlock(&data->dead_mutex);
//         if (d)
//             return (NULL);

//         i = 0;
//         while (i < data->input.nbr_philos)
//         {
//             pthread_mutex_lock(&data->dead_mutex);
//             d = data->dead;
//             pthread_mutex_unlock(&data->dead_mutex);
//             if (d)
//                 return (NULL);

//             if (has_philo_died(data, &data->philos[i]))
//                 return (NULL);
//             i++;
//         }

//         if (data->limit_mode
//             && data->philos_finished == data->input.nbr_philos)
//         {
//             pthread_mutex_lock(&data->dead_mutex);
//             data->dead = 1;
//             pthread_mutex_unlock(&data->dead_mutex);
//             return (NULL);
//         }
//         usleep(1000);
//     }
// }

// int has_philo_died(t_data *data, t_philo *philo)
// {
//     long    now;
//     long    last_meal;

//     pthread_mutex_lock(&philo->meal_mutex);
//     last_meal = philo->last_meal_time;
//     pthread_mutex_unlock(&philo->meal_mutex);

//     now = get_time();

//     if (now - last_meal >= data->input.time_to_die)
//     {
//         // Protéger dead AVANT de print
//         pthread_mutex_lock(&data->dead_mutex);
//         if (!data->dead)
//         {
//             data->dead = 1;

//             pthread_mutex_lock(&data->print_mutex);
//             printf("%ld %d died\n",
//                 now - data->start_time, philo->id);
//             pthread_mutex_unlock(&data->print_mutex);
//         }
//         pthread_mutex_unlock(&data->dead_mutex);
//         return (1);
//     }
//     return (0);
// }
