#include "matrix/matrix.h"
#include <iostream>


int main() {
    int n;
    std::cin >> n;

    Matrix matrix(n);
    matrix.read_input();
    matrix.print_matrix();

    // Iterate over the matrix using get_element()
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix.get_element(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
