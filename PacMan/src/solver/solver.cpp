#include "solver.h"
#include <stdio.h>
#include <queue>

Solver::Solver(Matrix *matrix_, Pacman *pacman_, Fantasma *fantasma_)
    : num_steps_(0), moves_up_(0), moves_down_(0), moves_left_(0),
      moves_right_(0), matrix(matrix_), pacman(pacman_), fantasma(fantasma_) {}

void Solver::clear() {
  parent.clear();
  num_steps_ = 0;
  moves_up_ = 0;
  moves_down_ = 0;
  moves_left_ = 0;
  moves_right_ = 0;
}

bool equals(Node* a, Node* b){
  return a->i==b->i && a->j==b->j;
}

void Solver::solve() {
  clear();

  std::queue<Node *> bfs_queue;
  first_node = pacman->start_node;

  bfs_queue.push(pacman->start_node);

  while (!bfs_queue.empty()) {
    Node *no = bfs_queue.front();
    if (equals(no, fantasma->current_node)) {
      has_solution = true;
      last_node = no;
      return;
    }
    for (Node *u : pacman->get_adjacent_nodes(no)) {
      if (matrix->is_in_limits(u) && matrix->get_element(*u) != 1 &&
          !is_visited(u)) {

        visit(u);
        set_parent(u, no);

        bfs_queue.push(u);
      }
    }
    fantasma->update_position();
  }
  has_solution = false;
}

void Solver::visit(Node *node) {
  auto [i, j] = *node;
  visited[{i, j}] = true;
}

void Solver::print_solution() {
  if (!has_solution) {
    printf("Não foi possível achar um caminho\n");
    return;
  }

  update_moves();

  printf("Número de passos: %d\nMovimentos para cima: %d\nMovimentos para baixo: %d\nMovimentos para esquerda: %d\nMovimentos para direita: %d\n",num_steps_, moves_up_,
  moves_down_,
  moves_left_,
  moves_right_);
}

bool Solver::is_visited(Node *node) {
  auto [i, j] = *node;
  return visited[{i, j}];
}

void Solver::set_parent(Node *son, Node *father) {
  auto [si, sj] = *son;
  auto [fi, fj] = *father;
  parent[{si, sj}] = {fi, fj};
}

void Solver::update_moves() {
  auto [i, j] = *last_node;
  std::pair<int, int> first_pair = {first_node->i, first_node->j};
  std::pair<int, int> pair_father;
  do {

    pair_father = parent[{i, j}];

    update_move({i, j}, pair_father);

    i = pair_father.first;
    j = pair_father.second;

  } while (pair_father != first_pair);
}

void Solver::update_move(std::pair<int, int> mov_son,
                         std::pair<int, int> mov_parent) {
  auto [i1, j1] = mov_son;
  auto [i2, j2] = mov_parent;
  int di = i2 - i1;
  int dj = j2 - j1;

  if (di == 1) {
    moves_up_++;
  } else if (di == -1) {
    moves_down_++;
  } else if (dj == 1) {
    moves_left_++;
  } else if (dj == -1) {
    moves_right_++;
  }

  num_steps_++;
}

