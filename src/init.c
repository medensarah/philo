/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:46:33 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/16 07:47:25 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_input(t_data *data, int ac, char **av)
{
	data->input.nbr_philos = ft_atoi(av[1]);
	data->input.time_to_die = ft_atoi(av[2]);
	data->input.time_to_eat = ft_atoi(av[3]);
	data->input.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->input.nb_must_eat = ft_atoi(av[5]);
	else
		data->input.nb_must_eat = -1;
}

void	init_data(t_data *data)
{
	data->dead = 0;
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	if (data->input.nb_must_eat == -1)
		data->limit_mode = 0;
	else
		data->limit_mode = 1;
	data->philos_finished = 0;
	data->start_time = get_time();
}

int	init_forks(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->input.nbr_philos;
	data->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->forks)
		return (err(0), 0);
	while (i < n)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->input.nbr_philos;
	data->philos = malloc(sizeof(t_philo) * n);
	if (!data->philos)
		return (err(0), 0);
	while (i < n)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % n];
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].meals_eaten = 0;
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
		i++;
	}
	return (1);
}
