/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: na-kannan <na-kannan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:00:00 by na-kannan         #+#    #+#             */
/*   Updated: 2025/01/01 10:00:00 by na-kannan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef> // for size_t

template <typename T>
class Array {
private:
    T*          _data;
    size_t      _size;

public:
    // Default constructor: Creates an empty array
    Array() : _data(NULL), _size(0) {}
    
    // Constructor with size: Creates an array of n elements initialized by default
    // Using new T() initializes the element to its default value (0 for ints, etc.)
    explicit Array(unsigned int n) : _data(NULL), _size(n) {
        if (n > 0) {
            _data = new T[n](); // The () initializes elements to default value
        }
    }
    
    // Copy constructor (deep copy)
    Array(const Array& other) : _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
    }
    
    // Assignment operator (deep copy)
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Delete old data
            if (_data != NULL) {
                delete[] _data;
            }
            
            // Copy new data
            _size = other._size;
            if (_size > 0) {
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            } else {
                _data = NULL;
            }
        }
        return *this;
    }
    
    // Destructor
    ~Array() {
        if (_data != NULL) {
            delete[] _data;
        }
    }
    
    // Subscript operator for non-const (read/write access)
    T& operator[](size_t index) {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _data[index];
    }
    
    // Subscript operator for const (read-only access)
    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw OutOfBoundsException();
        }
        return _data[index];
    }
    
    // Size member function
    size_t size() const {
        return _size;
    }
    
    // Custom exception class for out-of-bounds access
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index out of bounds";
        }
    };
};

#endif // ARRAY_HPP
