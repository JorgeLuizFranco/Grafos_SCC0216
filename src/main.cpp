
/**
 * TRABALHO 2 DE GRAFOS - PACMAN
 * 
 * ARTHUR QUEIROZ MOURA - 13671532
 * JORGE LUIZ FRANCO - 13695091 
*/

#include "pacman.h"

// n = dimensão da matriz nxn
// m = num de movimentos do fantasma
// inicio_fantasma e inicio_pacman sao coordenadas
// movimentos_fantasma eh autoexplicativo
// grid eh autoexplicativo
void le_entrada(int &n, int &m, pii &inicio_fantasma, pii &inicio_pacman,
                vector<char> &movimentos_fantasma, vector<vector<int>> &grid);


int main() {
  int n, m; // dimensao do tabuleiro, num de movimentos do fantasma

  pii inicio_fantasma, inicio_pacman; // (coordenadas)
  vector<char> movimentos_fantasma;
  vector<vector<int>> grid; 

  le_entrada(n, m, inicio_fantasma, inicio_pacman, movimentos_fantasma, grid);

  resolve(grid, movimentos_fantasma, inicio_fantasma, inicio_pacman, n);

  return 0;
}

void le_entrada(int &n, int &m, pii &inicio_fantasma, pii &inicio_pacman,
                vector<char> &movimentos_fantasma, vector<vector<int>> &grid) {
  // le dimensao da matriz
  scanf("%d", &n);

  grid.resize(n, vector<int>(n, 0));

  // le o vetor de grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  //le coordenadas
  scanf("%d %d", &inicio_pacman.first, &inicio_pacman.second);
  scanf("%d %d", &inicio_fantasma.first, &inicio_fantasma.second);

  // le o num de movimentos e os movimentos
  // do fantasma
  scanf("%d", &m);
  while (m--) {
    char direcao;
    scanf(" %c", &direcao);
    movimentos_fantasma.push_back(direcao);
  }
}