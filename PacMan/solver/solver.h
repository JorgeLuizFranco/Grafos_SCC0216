#ifndef SOLVER_H
#define SOLVER_H
#include<utility>
#include<map>
#include "../matrix/matrix.h"
#include "../pacman/pacman.h"

class Solver {

 public:
  Solver(Matrix& matrix, Pacman& pacman);
  void solve();
  void print_solution();
  int num_steps_;
  int moves_up_;
  int moves_down_;
  int moves_left_;
  int moves_right_;
  Matrix& matrix_;
  Pacman& pacman_;
  std::map<std::pair<int,int>,bool>  visited;  

  void visit(Node node);

};

#endif  // SOLVER_H
