/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 20:04:01 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/03 20:12:31 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	return (0);
}

int	check_scheduler(char *scheduler)
{
	if (strcmp(scheduler, "fifo") == 0 || strcmp(scheduler, "edf") == 0)
		return (1);
	return (0);
}

int	to_int(char *s, int *out)
{
	long	n;
	int		i;

	if (s[0] == '\0')
		return (0);
	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = n * 10 + (s[i] - '0');
		if (n > INT_MAX)
			return (0);
		i++;
	}
	*out = (int)n;
	return (1);
}

int	parse_args(t_args *args, char **argv)
{
	if (!to_int(argv[1], &args->number_of_coders) || args->number_of_coders < 1)
		return (print_error("invalid number_of_coders"));
	if (!to_int(argv[2], &args->time_to_burnout))
		return (print_error("invalid time to burnout"));
	if (!to_int(argv[3], &args->time_to_compile))
		return (print_error("invalid time to compile"));
	if (!to_int(argv[4], &args->time_to_debug))
		return (print_error("invalid time to debug"));
	if (!to_int(argv[5], &args->time_to_refactor))
		return (print_error("invalid time to refactor"));
	if (!to_int(argv[6], &args->number_of_compiles_required))
		return (print_error("invalid number of compiles required"));
	if (!to_int(argv[7], &args->dongle_cooldown))
		return (print_error("invalid time for dongle cooldown"));
	if (!(check_scheduler(argv[8])))
		return (print_error("scheduler method given not accepted"));
	args->scheduler = argv[8];
	return (1);
}
