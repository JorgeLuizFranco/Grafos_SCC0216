#include "matrix/matrix.h"
#include "pacman/pacman.h"
#include "solver/solver.h"
#include "fantasma/fantasma.h"
#include <iostream>


int main() {
    int n;
    std::cin >> n;

    Matrix matrix(n);
    matrix.read_input();
    
    int a,b;
    std::cin>>a>>b;
    Node node_pacman= Node(a,b);
    Pacman pacman= Pacman(&node_pacman);

    std::cin>>a>>b;
    Node node_fantasma= Node(a,b);
    Fantasma fantasma= Fantasma(&node_fantasma);

    Solver solver= Solver(&matrix,&pacman,&fantasma);

    solver.solve();
    
    solver.print_solution();
    return 0;
}
