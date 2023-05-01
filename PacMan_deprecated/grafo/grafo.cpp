#include "grafo.h"

// A função geral de cada uma das funções desse arquivo está documentada
// no grafo.h

std::pair<int,int> pair_de_no(No a){
    return std::pair<int,int>(a.i,a.j);
}

void Grafo::adiciona_conexao(No no_a, No no_b){
    auto a= pair_de_no(no_a);
    auto b=pair_de_no(no_b);
    lista_adjacencias[a].push_back(b);
    lista_adjacencias[b].push_back(a);
}

std::vector<std::pair<int,int>> Grafo::vizinhanca(No node){
    return lista_adjacencias[pair_de_no(node)];
}

Grafo::Grafo() {}