#ifndef SOLVER_H
#define SOLVER_H
#include "../fantasma/fantasma.h"
#include "../matrix/matrix.h"
#include "../pacman/pacman.h"
#include <map>
#include <utility>
#include <iostream>

class Solver {

public:
  Solver(Matrix *matrix_, Pacman *pacman_, Fantasma *fantasma_);
  void solve();
  void print_solution();
  int num_steps_;
  int moves_up_;
  int moves_down_;
  int moves_left_;
  int moves_right_;
  Matrix *matrix;
  Pacman *pacman;
  Fantasma *fantasma;
  std::map<std::pair<int, int>, bool> visited;

private:
  bool has_solution;
  Node* last_node;
  Node* first_node;
  void visit(Node *node);
  bool is_visited(Node *node);
  std::map<std::pair<int, int>, std::pair<int, int>> parent;
  void set_parent(Node *son, Node *father);
  void update_moves();
  void clear();
  void update_move(std::pair<int, int> mov_son, std::pair<int, int> mov_parent);
};

#endif // SOLVER_H
