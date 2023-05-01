#include "solver.h"

#include <queue>
#include <unordered_set>

Solver::Solver(Matrix& matrix, Pacman& pacman)
    : num_steps_(0),
      moves_up_(0),
      moves_down_(0),
      moves_left_(0),
      moves_right_(0),
      matrix_(matrix),
      pacman_(pacman) {}

void Solver::solve() {
  std::queue<Node> bfs_queue;

  bfs_queue.push(pacman_.start_node);

  while (!bfs_queue.empty()) {
    int size = bfs_queue.size();
    for (int i = 0; i < size; i++) {
      Node current_node = bfs_queue.front();
      bfs_queue.pop();
    }
    num_steps_++;
  }
}

void Solver::print_solution() {
    
}
