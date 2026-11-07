/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 20:04:20 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/07 16:41:16 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_simulation	t_simulation;

typedef struct s_args
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_args;

typedef struct s_dongle
{
	int				taken;
	long			released_at;
	pthread_mutex_t	lock;
}	t_dongle;

typedef struct s_coder
{
	pthread_t		thread;
	int				id;
	int				num_compiles;
	long			last_compile_start_value;
	pthread_mutex_t	compile_info_lock;
	t_dongle		*left_dongle;
	t_dongle		*right_dongle;
	t_simulation	*simulation;
}	t_coder;

typedef struct s_simulation
{
	t_args			rules;
	long			start_time;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_mutex_t	print;
	int				sim_over_bool;
	pthread_mutex_t	sim_over_lock;
}	t_simulation;

int		parse_args(t_args *args, char **argv);
int		check_scheduler(char *scheduler);
int		to_int(char *s, int *out);
int		print_error(char *msg);
long	get_current_time(void);
int		init_dongles(t_simulation *sim);
int		init_coders(t_simulation *sim);
void	destroy_dongles(t_simulation *sim, int count);
void	destroy_coders(t_simulation *sim, int count);
void	cleanup(t_simulation *sim);
void	destroy_shared(t_simulation *sim);
int		init_simulation(t_simulation *sim);

#endif