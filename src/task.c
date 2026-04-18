/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/18 08:58:04 by smedenec         ###   ########.fr       */
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
		if (philo->data->dead)
			break ;
		if (!take_forks(philo))
			break ;
		spaghetti(philo);
		if (philo->data->dead)
			break ;
		dodo(philo);
		if (philo->data->dead)
			break ;
		gamberge(philo);
	}
	return (NULL);
}

void	spaghetti(t_philo *philo)
{
	print(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->input.time_to_eat, philo->data);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->input.nb_must_eat)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		philo->data->philos_finished++;
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	take_forks(t_philo *philo)
{
	if (philo->data->dead)
		return (0);
	pthread_mutex_lock(philo->left_fork);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print(philo, "has taken a fork");
	return (1);
}

void	dodo(t_philo *philo)
{
	if (philo->data->dead)
		return ;
	print(philo, "is sleeping");
	ft_usleep(philo->data->input.time_to_sleep, philo->data);
}

void	gamberge(t_philo *philo)
{
	if (philo->data->dead)
		return ;
	print(philo, "is thinking");
}
