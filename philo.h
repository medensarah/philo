/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:10:59 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/15 08:39:05 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"

////////////////// MAIN ///////////

//init
void	init_input(t_data *data, int ac, char **av);
void	init_data(t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);
//thread
int		launch_threads(t_data *data);
int		launch_checker(t_data *data);
void	join_threads(t_data *data);
//task
void	*boulot_dodo(void *arg);
void	spaghetti(t_philo *philo);
void	dodo(t_philo *philo);
void	gamberge(t_philo *philo);
void	print_action(t_philo *philo, char *msg);
//checker
void	*check_death(void *arg);

////////////////// UTILS //////////

//time
long	get_time(void);
void	ft_usleep(long milisec, t_data *data);
//free
void	free_data(t_data *data);

////////////////// PARSING ////////

//nbr
int		ft_atoi(char *str);
void	ft_putnbr(int n);
int		is_non_digit(char *str);
int		is_nbr_overflow(char *str);
int		is_only_zero(char *str);
//verify
int		verify_input(int ac, char **av);
void	instruction(void);
void	err(int e);

#endif
