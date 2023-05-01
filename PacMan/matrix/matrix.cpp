#include "matrix.h"
#include <iostream>

Matrix::Matrix(int n) : n_(n), grid_(n, std::vector<int>(n)) {}

void Matrix::read_input() {
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < n_; j++) {
            std::cin >> grid_[i][j];
        }
    }
}

void Matrix::print_matrix() {
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < n_; j++) {
            std::cout << grid_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::get_element(Node node){
    return grid_[node.i][node.j];
}

bool Matrix::is_in_limits(Node node) const {
    return node.i >= 0 && node.i < n_ && node.j >= 0 && node.j < n_;
}

