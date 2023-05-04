#ifndef FANTASMA_H
#define FANTASMA_H

#include <queue>
#include <vector>

#include "../node.h"

class Fantasma {
 public:
  Node* start_node;
  Node* current_node;
  std::queue<char> directions;

  Fantasma(Node* node);
  void insert_direction(char direction);
  void update_position();

 private:
  Node direction_to_node(char dir);
};

#endif  // FANTASMA_H
