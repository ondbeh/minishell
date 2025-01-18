/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:36:30 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/17 01:41:53 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"

int	builtin_env(t_list *env_list)
{
	t_env	*env;

	while (env_list)
	{
		env = (t_env *)env_list->content;
		env_list = env_list->next;
		printf("%s=%s\n", env->key, env->value);
	}
	return (0);
}
