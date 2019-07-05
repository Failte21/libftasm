/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <lsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:34:29 by lsimon            #+#    #+#             */
/*   Updated: 2019/07/06 00:32:49 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void    ft_bzero(void *s, size_t n);
char    *ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_puts(char *s);
size_t  ft_strlen(const char *s);