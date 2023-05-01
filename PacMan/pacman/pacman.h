#ifndef PACMAN_H
#define PACMAN_H

#include <vector>

#include "../node.h"

class Pacman {
 public:
  Node start_node;

  Pacman(Node node);
  std::vector<Node> get_adjacent_nodes(Node current_node);
  
};

#endif  // PACMAN_H
