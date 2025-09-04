/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: na-kannan <na-kannan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:00:00 by na-kannan         #+#    #+#             */
/*   Updated: 2025/01/01 10:00:00 by na-kannan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Function to print the element
template <typename T>
void print(const T& x) {
    std::cout << x << std::endl;
}

// Function to set value to 42
template <typename T>
void setTo42(T& x) {
    x = 42;
}

// Test function for incrementing
template <typename T>
void increment(T& x) {
    x++;
}

// Non-template function for testing
void printInt(const int& x) {
    std::cout << "Int: " << x << std::endl;
}

int main() {
    // Test case that should produce the expected output
    // Based on review sheet: 0, 1, 2, 3, 4, 42, 42, 42, 42, 42
    std::cout << "=== Expected output test ===" << std::endl;
    int tab[] = {0, 1, 2, 3, 4};
    iter(tab, 5, print<int>);
    iter(tab, 5, setTo42<int>);
    iter(tab, 5, print<int>);
    
    std::cout << std::endl;
    
    // Additional comprehensive tests
    std::cout << "=== String array test ===" << std::endl;
    std::string strTab[] = {"Hello", "World", "42", "School"};
    iter(strTab, 4, print<std::string>);
    
    std::cout << std::endl;
    
    // Test with const array
    std::cout << "=== Const array test ===" << std::endl;
    const int constTab[] = {100, 200, 300};
    iter(constTab, 3, print<int>);
    
    std::cout << std::endl;
    
    // Test with float array
    std::cout << "=== Float array test ===" << std::endl;
    float floatTab[] = {1.1f, 2.2f, 3.3f, 4.4f};
    iter(floatTab, 4, print<float>);
    
    std::cout << std::endl;
    
    // Test with non-template function
    std::cout << "=== Non-template function test ===" << std::endl;
    int intTab[] = {10, 20, 30};
    iter(intTab, 3, printInt);
    
    std::cout << std::endl;
    
    // Test with modification function
    std::cout << "=== Increment test ===" << std::endl;
    int modTab[] = {1, 2, 3, 4, 5};
    std::cout << "Before increment:" << std::endl;
    iter(modTab, 5, print<int>);
    iter(modTab, 5, increment<int>);
    std::cout << "After increment:" << std::endl;
    iter(modTab, 5, print<int>);
    
    // Test with NULL pointer (should handle gracefully)
    std::cout << std::endl;
    std::cout << "=== NULL pointer test (should not crash) ===" << std::endl;
    int* nullPtr = NULL;
    iter(nullPtr, 5, print<int>);
    std::cout << "NULL pointer handled successfully" << std::endl;
    
    return 0;
}
