/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:18:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/26 00:18:30 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	number_length(long long n)
{
	int			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
