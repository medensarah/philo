/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:21:24 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 14:58:15 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_data
{
	t_input input;
	t_philo *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
}	t_data;


typedef struct s_input
{
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
}	t_input;

typedef struct s_philo
{
	int	id;
	pthread_t thread;
	t_data *data;
}	t_philo;

#endif
