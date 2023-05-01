#pragma once

#include <vector>
#include <map>
#include <stdio.h>
#include <stdexcept>
#include <algorithm>
#include <queue>

typedef struct Node
{
    int i;
    int j;
} No;



class Fantasma {
public:
    // Cada grafo possui um determinado numero de vertices
    // e uma lista de adjacências, que na verdade é um vetor de vetores 
    // tal que lista_adjacencias[v] é um vector<int> com todos os vizinhos de v

    int num_vertices;
    std::queue<char> movimentos;
    
    // Construtor da classe grafo
    // 'descricao' é um vetor de pares de inteiros, em que cada
    // par desse vetor corresponde a um par de inteiros de uma linha do arquivo de entrada
    // Ou seja, se o arquivo de entrada for
    // 2 1
    // 0 1
    // então descrição é um vetor de dois elementos, sendo o primeiro o par 2,1 e o segundo, o par 0,1
    Grafo(std::vector<std::pair<int, int>> descricao);

    // A partir de uma string contendo o nome de um arquivo, lê esse arquivo e 
    // a partir dele obtém um vetor de pair<int, int> descrição. Esse outro vetor, por sua vez,
    // é usado como argumento do construtor acima
    static Grafo grafo_de_arquivo(char* nome_arq);

    No get_no_direcao(char direcao);

    // Retorna um vetor de inteiros com o ciclo euleriano desejado
    // O vetor é vazio caso não haja ciclo
    std::vector<int> acha_ciclo_euleriano();
};
