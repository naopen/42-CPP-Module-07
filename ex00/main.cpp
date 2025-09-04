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
#include <string>
#include "whatever.hpp"

// Complex type for additional testing
class Complex {
private:
    int _value;
public:
    Complex(int v = 0) : _value(v) {}
    Complex(const Complex& other) : _value(other._value) {}
    Complex& operator=(const Complex& other) {
        if (this != &other)
            _value = other._value;
        return *this;
    }
    ~Complex() {}
    
    int getValue() const { return _value; }
    
    bool operator<(const Complex& other) const {
        return _value < other._value;
    }
    bool operator>(const Complex& other) const {
        return _value > other._value;
    }
    bool operator==(const Complex& other) const {
        return _value == other._value;
    }
    bool operator!=(const Complex& other) const {
        return _value != other._value;
    }
    bool operator<=(const Complex& other) const {
        return _value <= other._value;
    }
    bool operator>=(const Complex& other) const {
        return _value >= other._value;
    }
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "Complex(" << c.getValue() << ")";
    return os;
}

int main(void) {
    // Test from the subject
    std::cout << "=== Basic tests from subject ===" << std::endl;
    int a = 2;
    int b = 3;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    
    std::cout << std::endl;
    
    // Additional tests for complex types
    std::cout << "=== Complex type tests ===" << std::endl;
    Complex comp1(42);
    Complex comp2(84);
    
    std::cout << "Before swap: comp1 = " << comp1 << ", comp2 = " << comp2 << std::endl;
    ::swap(comp1, comp2);
    std::cout << "After swap: comp1 = " << comp1 << ", comp2 = " << comp2 << std::endl;
    std::cout << "min( comp1, comp2 ) = " << ::min(comp1, comp2) << std::endl;
    std::cout << "max( comp1, comp2 ) = " << ::max(comp1, comp2) << std::endl;
    
    std::cout << std::endl;
    
    // Test with equal values (should return the second one)
    std::cout << "=== Equal values test ===" << std::endl;
    int x = 5;
    int y = 5;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min( x, y ) should return y: " << &::min(x, y) << " == " << &y;
    std::cout << " : " << (&::min(x, y) == &y ? "OK" : "FAIL") << std::endl;
    std::cout << "max( x, y ) should return y: " << &::max(x, y) << " == " << &y;
    std::cout << " : " << (&::max(x, y) == &y ? "OK" : "FAIL") << std::endl;
    
    std::cout << std::endl;
    
    // Test with const values
    std::cout << "=== Const values test ===" << std::endl;
    const int ca = 10;
    const int cb = 20;
    std::cout << "const ca = " << ca << ", const cb = " << cb << std::endl;
    std::cout << "min( ca, cb ) = " << ::min(ca, cb) << std::endl;
    std::cout << "max( ca, cb ) = " << ::max(ca, cb) << std::endl;
    
    // Test with floats
    std::cout << std::endl;
    std::cout << "=== Float test ===" << std::endl;
    float f1 = 3.14f;
    float f2 = 2.71f;
    ::swap(f1, f2);
    std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
    std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;
    
    return 0;
}
