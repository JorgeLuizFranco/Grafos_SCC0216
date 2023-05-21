#include "pacman.h"


void printa_solucao(const vector<vector<pii>> &pai, pii no_solucao) {
  // inicialmente as respostas estao zeradas
  // mas vou fazendo backtracking no vetor "pai" e atualizando essas
  // variaveis
  int numero_passos = 0, movimentos_cima = 0, movimentos_baixo = 0,
      movimentos_esquerda = 0, movimentos_direita = 0;
  auto [i, j] = no_solucao;
  
  // backtracking
  while (pai[i][j] != pii(-1, -1)) {
    pii pai_atual = pai[i][j];
    // Atualiza vars
    atualiza_movimento({i, j}, pai_atual, numero_passos, movimentos_cima,
                movimentos_baixo, movimentos_esquerda, movimentos_direita);
    i = pai_atual.first, j = pai_atual.second;
  }
  
  // Resposta final
  printf(
      "Número de passos: %d\nMovimentos para cima: %d\nMovimentos para baixo: "
      "%d\nMovimentos para esquerda: %d\nMovimentos para direita: %d",
      numero_passos, movimentos_cima, movimentos_baixo, movimentos_esquerda,
      movimentos_direita);
}

vector<pii> vizinhos(pii no_atual) {
  // ja explicado.
  auto [i, j] = no_atual;

  const vector<pii> nodes = {pii(i, j + 1), pii(i, j - 1), pii(i + 1, j),
                             pii(i - 1, j)};

  return nodes;
}

bool no_grid(pii node, int n) {
  // ja explicado.
  auto [i, j] = node;
  return i >= 0 && i < n && j >= 0 && j < n;
}

vector<pii> cria_posicoes_fantasma(const vector<char> &movimentos_fantasma, pii inicio_fantasma, int n) {
  vector<pii> posicoes_fantasma;

  pii posicao_atual = inicio_fantasma;
  posicoes_fantasma.push_back(posicao_atual);
  
  // pra cada passo do fantasma
  // colocar coordenada correspondente no vetor de movimentos
  for (char direcao : movimentos_fantasma) {

    switch (direcao) {
      case 'L': if (posicao_atual.second>0)
                  posicao_atual = {posicao_atual.first, posicao_atual.second - 1};
        break;
      case 'R': if (posicao_atual.second<n-1)
                  posicao_atual = {posicao_atual.first, posicao_atual.second + 1};
        break;
      case 'U': if (posicao_atual.first>0)
                  posicao_atual = {posicao_atual.first - 1, posicao_atual.second};
        break;
      case 'D': if (posicao_atual.first<n-1)
                  posicao_atual = {posicao_atual.first + 1, posicao_atual.second};
        break;
    }

    posicoes_fantasma.push_back(posicao_atual);
  }

  return posicoes_fantasma;
}

void bfs(const vector<vector<int>> &grid, vector<vector<int>> &dist,
               vector<vector<pii>> &pai, pii inicio_pacman, int n) {
  queue<pair<pii, int>> fila;  // fila que guarda {posicao,dist}, lembrando que posicao eh pair<int, int>
  fila.push({inicio_pacman,0});
  dist[inicio_pacman.first][inicio_pacman.second] = 0;

  while (!fila.empty()) {
    auto [no, dist_atual] = fila.front();
    fila.pop();

    for (auto [i, j] : vizinhos(no)) {
      if (no_grid({i, j}, n) and
          dist[i][j] == -1 and grid[i][j]!=1) {         // se estiver nos limites e não visitado
        dist[i][j] = dist_atual + 1;  //  atualizo a distância
        pai[i][j] = no; // marco de onde ele veio
        fila.push({pii(i, j), dist[i][j]});  // coloco na fila
      }
    }
  }

}

void resolve(const vector<vector<int>> &grid,
           const vector<char> &movimentos_fantasma, pii inicio_fantasma,
           pii inicio_pacman, int n) {
  
  vector<pii> posicoes_fantasma =
      cria_posicoes_fantasma(movimentos_fantasma, inicio_fantasma, n);

  
  /* seto a matriz de distâncias para -1, pois assim podemos usa la como vetor
   * de visitados também */
  vector<vector<int>> dist(n, vector<int>(n, -1));
  vector<vector<pii>> pai(n, vector<pii>(n, pii(-1, -1))); // pai[i][j] armazena de onde veio (i, j) na bfs

  bfs(grid, dist, pai, inicio_pacman, n);
  
  // valor inalcançável que serve para identificar no final se o caminhho foi encontrado
  int dist_min = n * n + 2;     
  // possível posição "mínima" de encontro ("melhor até agora")
  pii pos_min; 
  int n_posicoes = posicoes_fantasma.size();

  for (int i = 0; i < n_posicoes; i++) {
    auto [x, y] = posicoes_fantasma[i];
    // se for possível chegar em (x, y) primeiro que o fantasma
    if (dist[x][y] <= i and dist_min > dist[x][y] and dist[x][y] != -1) {
      dist_min = dist[x][y];
      pos_min = {x, y};
    // ja que o fantasma para na ultima pos, nao preciso chegar em (x, y)
    // primeiro que ele
    } else if (i == n_posicoes-1 and dist[x][y] != -1){
      dist_min = dist[x][y];
      pos_min = {x, y};
    }
  }

  if (dist_min == (n * n + 2)) {
    printf("Não foi possível achar um caminho\n");
    return;
  }

  printa_solucao(pai, pos_min);
}

void atualiza_movimento(pii mov_filho, pii mov_pai, int &num_passos_, int &movimentos_cima_,
                 int &movimentos_baixo_, int &movimentos_esq_, int &movimentos_dir_) {
  auto [i1, j1] = mov_filho;
  auto [i2, j2] = mov_pai;
  int di = i2 - i1;
  int dj = j2 - j1;

  if (di == 1) {
    // se for aqui, quer dizer por exemplo que se
    // filho = (x, y), temos pai = (x+1, y)
    // e isso quer dizer que ocorreu um movimento pra cima
    // o resto dos else if sao analogos
    movimentos_cima_++;
  } else if (di == -1) {
    movimentos_baixo_++;
  } else if (dj == 1) {
    movimentos_esq_++;
  } else if (dj == -1) {
    movimentos_dir_++;
  }

  num_passos_++;
}
