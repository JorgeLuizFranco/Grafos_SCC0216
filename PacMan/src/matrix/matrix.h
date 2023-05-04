#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "../node.h"

class Matrix {
    int n_;
    std::vector<std::vector<int>> grid_;

public:
    Matrix(int n);
    void read_input();
    void print_matrix();
    int get_element(Node node);
    bool is_in_limits(Node* node) const;
};

#endif // MATRIX_H
