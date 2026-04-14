/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:10:59 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 03:09:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

//main
void	launch_thread(t_input *input);
//init
void	init_input(t_data *data, int ac, char **av);
void	init_data(t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);
//task
void	*boulot_dodo(void *arg);
void	hello(t_philo *philo);
//utils
long	get_time(void);

////////////////// PARSING ////////
//utils_nbr
int		ft_atoi(char *str);
void	ft_putnbr(int n);
int		is_non_digit(char *str);
int		is_nbr_overflow(char *str);
int		is_only_zero(char *str);
//check_input
int		verify_input(int ac, char **av);
void	instruction(void);
void	err(int e);

#endif
