/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: na-kannan <na-kannan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:00:00 by na-kannan         #+#    #+#             */
/*   Updated: 2025/01/01 10:00:00 by na-kannan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

// Main iter function template
// Works with any type of array and any function that accepts elements of that type
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    if (!array)
        return;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Overload for const arrays with function taking const reference
template <typename T, typename Func>
void iter(const T* array, size_t length, Func func) {
    if (!array)
        return;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif // ITER_HPP
