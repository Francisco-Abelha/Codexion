/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 20:03:57 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/03 20:30:13 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_args	args;
	long	start;
	long	timestamp;

	start = get_current_time();
	if (argc != 9)
		return (print_error("invalid number of args"), 1);
	if (!(parse_args(&args, argv)))
		return (1);
	usleep(200 * 1000);
	timestamp = get_current_time() - start;
	printf("%ld\n", timestamp);
	return (0);
}
