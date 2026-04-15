/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/15 09:35:21 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*boulot_dodo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->input.nbr_philos == 1)
		return (philo_alone(philo));
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (1)
	{
		if (philo->data->dead == 1)
			break ;
		spaghetti(philo);
		if (philo->data->dead == 1)
			break ;
		dodo(philo);
		if (philo->data->dead == 1)
			break ;
		gamberge(philo);
	}
	return (NULL);
}

void	spaghetti(t_philo *philo)
{	
	print(philo, "is sleeping");
    ft_usleep(200, philo->data);
}

void	dodo(t_philo *philo)
{
	print(philo, "is sleeping");
    ft_usleep(200, philo->data);
}

void	gamberge(t_philo *philo)
{
	print(philo, "is thinking");
    ft_usleep(200, philo->data);
}

void	*philo_alone(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    printf("%ld %d has taken a fork\n",
        get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->print_mutex);
    ft_usleep(philo->data->input.time_to_die, philo->data);
    pthread_mutex_lock(&philo->data->dead_mutex);
    if (!philo->data->dead)
        philo->data->dead = 1;
    pthread_mutex_unlock(&philo->data->dead_mutex);
    pthread_mutex_lock(&philo->data->print_mutex);
    printf("%ld %d died\n",
        get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->print_mutex);
    return (NULL);
}
