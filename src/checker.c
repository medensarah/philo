/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 07:05:22 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/15 13:00:43 by smedenec         ###   ########.fr       */
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
        if (all_philos_ate_enough(data))
        {
            pthread_mutex_lock(&data->print_mutex);
            data->dead = 1;
            pthread_mutex_unlock(&data->print_mutex);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}

int has_philo_died(t_data *data, t_philo *philo)
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

int	all_philos_ate_enough(t_data *data)
{
    int	i;
    int	count;

	i = 0;
	count = 0;
    if (!data->limit_mode)
        return (0);
    while (i < data->input.nbr_philos)
    {
        pthread_mutex_lock(&data->philos[i].meal_mutex);
        if (data->philos[i].meals_eaten >= data->input.nb_must_eat)
            count++;
        pthread_mutex_unlock(&data->philos[i].meal_mutex);
        i++;
    }
    return (count == data->input.nbr_philos);
}

