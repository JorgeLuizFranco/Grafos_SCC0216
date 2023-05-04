#include "pacman.h"

Pacman::Pacman(Node* node) : start_node(node) {}

std::vector<Node*> Pacman::get_adjacent_nodes(Node* current_node) {
    int i = current_node->i;
    int j = current_node->j;
    Node baixo = Node(i+1, j);
    Node cima = Node(i-1, j);
    Node dir = Node(i, j+1);
    Node esq = Node(i, j-1);   

    std::vector<Node*> nodes = {
        &baixo,
        &cima,
        &dir,
        &esq
    };
    
    return nodes;
}
