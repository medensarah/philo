/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 19:18:21 by smedenec         ###   ########.fr       */
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

int	init_forks(t_data *data)
{
	int i;
	int n;

	i = 0;
	n = data->input.nbr_philos;
	data->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->forks)
		return ;//free
	while (i < n)
		pthread_mutex_init(&data->forks[i++], NULL);
}

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

int	verify_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (write(2, "Error: Only 4 or 5 arguments are accepted\n", 42), 0);
	while (i < ac)
	{
		if (is_non_digit(av[i]))
			return (write(2, "Error: only digits are allowed\n", 31), 0);
		if (is_nbr_overflow(av[i]))
			return (write(2, "Error: number out of range\n", 27), 0);
		if ((i != 5) && is_only_zero(av[i]))
			return (write(2, "Error: number cannot be zero except for arg[6]\n", 48), 0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data data;

	if (!verify_input(ac, av))
		return (1);
	init_input(&data, ac, av);
	if (!init_forks(&data))
		return (write(2, "Error: malloc forks failed\n", 28), 1);
	// ici
	// launch_thread(&input);
	write(1, "END MAIN\n", 9);
	return (0);
}
