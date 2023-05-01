#pragma once

#include <vector>
#include <map>
#include <stdio.h>
#include <stdexcept>
#include <algorithm>
#include <utility>

typedef struct Node
{
    int i;
    int j;
} No;


class Grafo {
public:
    // Cada grafo possui um determinado numero de vertices
    // e uma lista de adjacências, que na verdade é um vetor de vetores 
    // tal que lista_adjacencias[v] é um vector<int> com todos os vizinhos de v

    int num_vertices;
    std::map<std::pair<int,int>,std::vector<std::pair<int,int>>> lista_adjacencias;
    
    // Construtor da classe grafo
    // 'descricao' é um vetor de pares de inteiros, em que cada
    // par desse vetor corresponde a um par de inteiros de uma linha do arquivo de entrada
    // Ou seja, se o arquivo de entrada for
    // 2 1
    // 0 1
    // então descrição é um vetor de dois elementos, sendo o primeiro o par 2,1 e o segundo, o par 0,1
    Grafo();
    
    void Grafo::adiciona_conexao(No a, No b);
    
    std::vector<std::pair<int,int>> Grafo::vizinhanca(No node);     

};
