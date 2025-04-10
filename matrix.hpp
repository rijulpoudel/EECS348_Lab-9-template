#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    std::size_t size;

public:
    Matrix(std::size_t N) : size(N), data(N, std::vector<T>(N, 0)) {}
    Matrix(const std::vector<std::vector<T>>& nums) : data(nums), size(nums.size()) {}

    Matrix operator+(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &rhs) const {
        Matrix result(size);
        for (std::size_t i = 0; i < size; ++i)
            for (std::size_t j = 0; j < size; ++j)
                for (std::size_t k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    void set_value(std::size_t i, std::size_t j, T n) {
        data.at(i).at(j) = n;
    }

    T get_value(std::size_t i, std::size_t j) const {
        return data.at(i).at(j);
    }

    int get_size() const {
        return static_cast<int>(size);
    }

    T sum_diagonal_major() const {
        T sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    T sum_diagonal_minor() const {
        T sum = 0;
        for (std::size_t i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    void swap_rows(std::size_t r1, std::size_t r2) {
        if (r1 < size && r2 < size)
            std::swap(data[r1], data[r2]);
    }

    void swap_cols(std::size_t c1, std::size_t c2) {
        if (c1 < size && c2 < size) {
            for (std::size_t i = 0; i < size; ++i)
                std::swap(data[i][c1], data[i][c2]);
        }
    }

    void print_matrix() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                std::cout << std::setw(6) << val;
            std::cout << "\n";
        }
    }
};

#endif
