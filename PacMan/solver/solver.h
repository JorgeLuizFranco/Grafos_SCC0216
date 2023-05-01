#ifndef SOLVER_H
#define SOLVER_H

#include "matrix.h"
#include "pacman.h"

class Solver {
  int num_steps_;
  int moves_up_;
  int moves_down_;
  int moves_left_;
  int moves_right_;
  Matrix& matrix_;
  Pacman& pacman_;

 public:
  Solver(Matrix& matrix, Pacman& pacman);
  void solve();
  void print_solution();
};

#endif  // SOLVER_H
