#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./main <input_file>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    std::size_t N;
    infile >> N;

    std::vector<std::vector<int>> data1(N, std::vector<int>(N));
    std::vector<std::vector<int>> data2(N, std::vector<int>(N));

    // Read Matrix 1
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            infile >> data1[i][j];

    // Read Matrix 2
    for (std::size_t i = 0; i < N; ++i)
        for (std::size_t j = 0; j < N; ++j)
            infile >> data2[i][j];

    Matrix m1(data1);
    Matrix m2(data2);

    std::cout << "Matrix 1:\n";
    m1.print_matrix();

    std::cout << "\nMatrix 2:\n";
    m2.print_matrix();

    std::cout << "\nMatrix Addition:\n";
    Matrix sum = m1 + m2;
    sum.print_matrix();

    std::cout << "\nMatrix Multiplication:\n";
    Matrix product = m1 * m2;
    product.print_matrix();

    std::cout << "\nSum of Major Diagonal in Matrix 1: " << m1.sum_diagonal_major() << "\n";
    std::cout << "Sum of Minor Diagonal in Matrix 1: " << m1.sum_diagonal_minor() << "\n";

    std::cout << "\nSwapping rows 0 and 1 in Matrix 1:\n";
    m1.swap_rows(0, 1);
    m1.print_matrix();

    std::cout << "\nSwapping columns 0 and 1 in Matrix 1:\n";
    m1.swap_cols(0, 1);
    m1.print_matrix();

    std::cout << "\nUpdating value at (0,0) in Matrix 1 to 999:\n";
    m1.set_value(0, 0, 999);
    m1.print_matrix();

    return 0;
}
