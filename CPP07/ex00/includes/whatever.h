/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:23:46 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 18:54:14 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

template<typename T>
void    swap(T &a, T &b)
{
    T   tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T &a, T &b)
{
    return (a < b ? a : b);
}

template<typename T>
T   max(T &a, T &b)
{
    return (a > b ? a : b);
}

#endif