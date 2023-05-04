#include "fantasma.h"

Fantasma::Fantasma(Node* node) : start_node(node), current_node(node) {}

void Fantasma::insert_direction(char direction) {
    directions.push(direction);
}

Node Fantasma::direction_to_node(char dir) { 
    switch (dir)
    {
    case 'L':
        return Node(current_node->i-1,current_node->j);
    case 'R':
        return Node(current_node->i+1,current_node->j);        
    case 'U':
        return Node(current_node->i,current_node->j-1);        
    case 'D':
        return Node(current_node->i,current_node->j+1);                
    default:
        break;
    }
    return Node(-1,-1);
 }

void Fantasma::update_position() {
    
    if(directions.empty()) return;

    char direction = directions.front();
    directions.pop();

    Node n = direction_to_node(direction);
    current_node= &n;
}
