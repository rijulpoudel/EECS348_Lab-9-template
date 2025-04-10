#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    std::size_t size;

public:
    //constructor with size
    Matrix(std::size_t N) : size(N), data(N, std::vector<int>(N, 0)) {}

    //constructor with predefined values
    Matrix(std::vector<std::vector<int>> nums) : data(nums), size(nums.size()) {}

    //matrix addition
    Matrix operator+(const Matrix &rhs) const {
        if (size != rhs.size)
            throw std::invalid_argument("Matrix sizes must match for addition.");
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    //matrix multiplication
    Matrix operator*(const Matrix &rhs) const {
        if (size != rhs.size)
            throw std::invalid_argument("Matrix sizes must match for multiplication.");
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                for (std::size_t k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    //setting a value in the matrix
    void set_value(std::size_t i, std::size_t j, int n) {
        if (i >= size || j >= size)
            throw std::out_of_range("Index out of bounds");
        data[i][j] = n;
    }

    //getting a value from the matrix
    int get_value(std::size_t i, std::size_t j) const {
        if (i >= size || j >= size)
            throw std::out_of_range("Index out of bounds");
        return data[i][j];
    }

    //getting size of the matrix
    int get_size() const {
        return static_cast<int>(size);
    }

    //sum of main diagonal 
    int sum_diagonal_major() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    //sum of secondary diagonal 
    int sum_diagonal_minor() const {
        int sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    //swaping two rows
    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 < size && r2 < size)
            std::swap(data[r1], data[r2]);
    }

    //swapping two columns
    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 < size && c2 < size) {
            for (std::size_t i = 0; i < size; ++i)
                std::swap(data[i][c1], data[i][c2]);
        }
    }

    //printing matrix nicely
    void print_matrix() const {
        for (const auto& row : data) {
            for (int val : row)
                std::cout << std::setw(6) << val;
            std::cout << "\n";
        }
    }
};

#endif // __MATRIX_HPP__
