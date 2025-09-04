/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: na-kannan <na-kannan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:00:00 by na-kannan         #+#    #+#             */
/*   Updated: 2025/01/01 10:00:00 by na-kannan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// swap: Swaps the values of two given parameters
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// min: Returns the smallest value, or the second one if equal
template <typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

// max: Returns the greatest value, or the second one if equal
template <typename T>
T const& max(T const& a, T const& b) {
    return (a > b) ? a : b;
}

#endif // WHATEVER_HPP
