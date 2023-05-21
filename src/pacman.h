#include <vector>
#include <utility>
#include <stdio.h>
#include <queue>

using namespace std;

// Para armazenar as coordenadas, ficou mais fácil utilizar um pair<int, int>
using pii = pair<int, int>;

// pai[x][y] eh o cara que chegou em (x, y) pela bfs
// no_solucao eh o lugar em que se encontram
// faz backtracking e ve exatamente qual a saida
void printa_solucao(const vector<vector<pii>> &pai, pii no_solucao);

// dado (x, y) retorna { (x+1, y), (x-1, y), (x, y+1), (x, y-1) }
vector<pii> vizinhos(pii no_atual);

// ve se esta no grid (se x,y< 0 ou x,y>= n nao esta)
bool no_grid(pii node, int n);

// dado a entrada com os movimentos, cria um vetor de coordenadas por onde passou
vector<pii> cria_posicoes_fantasma(const vector<char> &movimentos_fantasma, pii inicio_fantasma, int n);

// Atualiza as variaveis de num_passos e de movimentos pra cada direção dada
// a direção antiga e a nova
void atualiza_movimento(pii mov_filho, pii mov_pai, int &num_passos_, int &movimentos_cima_,
                 int &movimentos_baixo_, int &movimentos_esq_, int &movimentos_dir_);

// Faz o algoritmo de busca em largura que faz com que dist indique o tempo de
// chegada em cada quadradinho
void bfs(const vector<vector<int>> &grid, vector<vector<int>> &dist,
               vector<vector<pii>> &pai, pii inicio_pacman, int n);

// Faz a bfs e depois resolve o problema
void resolve(const vector<vector<int>> &grid,
           const vector<char> &movimentos_fantasma, pii inicio_fantasma,
           pii inicio_pacman, int n);