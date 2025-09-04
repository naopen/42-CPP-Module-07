/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:00:00 by na-kannan         #+#    #+#             */
/*   Updated: 2025/09/05 01:53:01 by na-kannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // for srand, rand
#include <ctime>   // for time
#include <string>
#include "Array.hpp"

// Complex type for testing
class Complex {
private:
    int _real;
    int _imag;
public:
    Complex() : _real(0), _imag(0) {}
    Complex(int r, int i) : _real(r), _imag(i) {}
    Complex(const Complex& other) : _real(other._real), _imag(other._imag) {}
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            _real = other._real;
            _imag = other._imag;
        }
        return *this;
    }
    ~Complex() {}

    int getReal() const { return _real; }
    int getImag() const { return _imag; }

    bool operator==(const Complex& other) const {
        return (_real == other._real && _imag == other._imag);
    }
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.getReal() << "+" << c.getImag() << "i";
    return os;
}

// Function to test const Array
void testConstArray(const Array<int>& arr) {
    std::cout << "Testing const Array access:" << std::endl;
    std::cout << "Size of const array: " << arr.size() << std::endl;
    if (arr.size() > 0) {
        std::cout << "First element (const access): " << arr[0] << std::endl;
    }

    // Test out of bounds access on const array
    try {
        std::cout << "Trying to access out of bounds on const array..." << std::endl;
        int value = arr[arr.size() + 10];
        (void)value; // Avoid unused variable warning
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    // TEST 1: Empty array construction (Review sheet requirement)
    std::cout << "=== TEST 1: Empty Array Construction ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    try {
        emptyArray[0] = 42; // Should throw exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception on empty array access: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // TEST 2: Array with specific size (Review sheet requirement)
    std::cout << "=== TEST 2: Array with Specific Size ===" << std::endl;
    Array<int> sizedArray(5);
    std::cout << "Array created with size: " << sizedArray.size() << std::endl;
    std::cout << "Default initialized values: ";
    for (size_t i = 0; i < sizedArray.size(); i++) {
        std::cout << sizedArray[i] << " ";
    }
    std::cout << std::endl;

    // Modify values
    for (size_t i = 0; i < sizedArray.size(); i++) {
        sizedArray[i] = i * 10;
    }
    std::cout << "After modification: ";
    for (size_t i = 0; i < sizedArray.size(); i++) {
        std::cout << sizedArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // TEST 3: Copy constructor and assignment operator
    std::cout << "=== TEST 3: Copy Constructor & Assignment ===" << std::endl;
    Array<int> original(3);
    for (size_t i = 0; i < original.size(); i++) {
        original[i] = i + 100;
    }

    Array<int> copyConstructed(original);
    Array<int> copyAssigned;
    copyAssigned = original;

    std::cout << "Original: ";
    for (size_t i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy constructed: ";
    for (size_t i = 0; i < copyConstructed.size(); i++) {
        std::cout << copyConstructed[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy assigned: ";
    for (size_t i = 0; i < copyAssigned.size(); i++) {
        std::cout << copyAssigned[i] << " ";
    }
    std::cout << std::endl;

    // Modify original to verify deep copy
    original[0] = 999;
    std::cout << "After modifying original[0] to 999:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "CopyConstructed[0]: " << copyConstructed[0] << std::endl;
    std::cout << "CopyAssigned[0]: " << copyAssigned[0] << std::endl;
    std::cout << std::endl;

    // TEST 4: Const array access (Review sheet requirement)
    std::cout << "=== TEST 4: Const Array Access ===" << std::endl;
    const Array<int> constArray(sizedArray);
    testConstArray(constArray);
    std::cout << std::endl;

    // TEST 5: Complex type array (Review sheet requirement)
    std::cout << "=== TEST 5: Complex Type Array ===" << std::endl;
    Array<Complex> complexArray(3);
    std::cout << "Complex array default values: ";
    for (size_t i = 0; i < complexArray.size(); i++) {
        std::cout << complexArray[i] << " ";
    }
    std::cout << std::endl;

    complexArray[0] = Complex(1, 2);
    complexArray[1] = Complex(3, 4);
    complexArray[2] = Complex(5, 6);

    std::cout << "After assignment: ";
    for (size_t i = 0; i < complexArray.size(); i++) {
        std::cout << complexArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // TEST 6: String array
    std::cout << "=== TEST 6: String Array ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "School";

    std::cout << "String array: ";
    for (size_t i = 0; i < strArray.size(); i++) {
        std::cout << "\"" << strArray[i] << "\" ";
    }
    std::cout << std::endl << std::endl;

    // TEST 7: Exception handling for out-of-bounds access
    std::cout << "=== TEST 7: Out-of-Bounds Exception Handling ===" << std::endl;
    Array<int> boundTest(10);

    try {
        std::cout << "Trying negative index [-1]..." << std::endl;
        boundTest[-1] = 42;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying index equal to size [10]..." << std::endl;
        boundTest[10] = 42;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying very large index [9999]..." << std::endl;
        boundTest[9999] = 42;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // TEST 8: Original evaluation test (MANDATORY for evaluation)
    std::cout << "=====================================" << std::endl;
    std::cout << "=== ORIGINAL EVALUATION TEST     ===" << std::endl;
    std::cout << "=== (Required for peer review)   ===" << std::endl;
    std::cout << "=====================================" << std::endl;

    #define MAX_VAL 750

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // SCOPE test
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    // Verify deep copy
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }

    // Test out of bounds access
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Exception for negative index: " << e.what() << '\n';
    }

    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Exception for MAX_VAL index: " << e.what() << '\n';
    }

    // Modify array
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    delete [] mirror;

    return 0;
}
