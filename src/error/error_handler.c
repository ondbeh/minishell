/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:54:20 by obehavka          #+#    #+#             */
/*   Updated: 2025/01/20 16:18:37 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_handler(char *message, int status)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(status);
}
