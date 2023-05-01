#include "pacman.h"

Pacman::Pacman(Node node) : start_node(node) {}

std::vector<Node> Pacman::get_adjacent_nodes(Node current_node) {
    int i = current_node.i;
    int j = current_node.j;
    std::vector<Node> nodes = {
        {i+1, j},
        {i-1, j},
        {i, j+1},
        {i, j-1}
    };
    
    return nodes;
}
