
/**
 * TRABALHO 2 DE GRAFOS - PACMAN
 * 
 * ARTHUR QUEIROZ MOURA - 13671532
 * JORGE LUIZ FRANCO - 13695091 
*/

#include <vector>
#include <utility>
#include <iostream>
#include <queue>

using namespace std;

// Para armazenar as coordenadas, ficou mais fácil utilizar um pair<int, int>
using pii = pair<int, int>;

// 
void printa_solucao(const vector<vector<pii>> &pai, pii node_solution);

vector<pii> vizinhos(pii no_atual);

bool no_grid(pii node, int n)

vector<pii> cria_posicoes_fantasma(const vector<char> &movimentos_fantasma, pii inicio_fantasma, int n)

void atualiza_movimento(pii mov_filho, pii mov_pai, int &num_passos_, int &movimentos_cima_,
                 int &movimentos_baixo_, int &movimentos_esq_, int &movimentos_dir_);

void bfs(const vector<vector<int>> &grid, vector<vector<int>> &dist,
               vector<vector<pii>> &pai, pii inicio_pacman, int n);

void resolve(const vector<vector<int>> &grid,
           const vector<char> &movimentos_fantasma, pii inicio_fantasma,
           pii inicio_pacman, int n);

int main() {
  int n, m; // dimensao do tabuleiro, num de movimentos do fantasma
  cin >> n;

  pii inicio_fantasma, inicio_pacman; // (coordenadas)
  vector<char> movimentos_fantasma;
  vector<vector<int>> grid(n, vector<int>(n, 0));  // inicializo o vetor de grid

  // le o vetor de grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cin >> inicio_pacman.first >> inicio_pacman.second;
  cin >> inicio_fantasma.first >> inicio_fantasma.second;

  cin >> m;
  while (m--) {
    char direcao;
    cin >> direcao;
    movimentos_fantasma.push_back(direcao);
  }

  resolve(grid, movimentos_fantasma, inicio_fantasma, inicio_pacman, n);

  return 0;
}


void printa_solucao(const vector<vector<pii>> &pai, pii node_solution) {
  int numero_passos = 0, movimentos_cima = 0, movimentos_baixo = 0,
      movimentos_esquerda = 0, movimentos_direita = 0;
  auto [i, j] = node_solution;

  while (pai[i][j] != pii(-1, -1)) {
    pii father = pai[i][j];
    atualiza_movimento({i, j}, father, numero_passos, movimentos_cima,
                movimentos_baixo, movimentos_esquerda, movimentos_direita);
    i = father.first, j = father.second;
  }

  printf(
      "Número de passos: %d\nMovimentos para cima: %d\nMovimentos para baixo: "
      "%d\nMovimentos para esquerda: %d\nMovimentos para direita: %d",
      numero_passos, movimentos_cima, movimentos_baixo, movimentos_esquerda,
      movimentos_direita);
}

vector<pii> vizinhos(pii no_atual) {
  auto [i, j] = no_atual;

  const vector<pii> nodes = {pii(i, j + 1), pii(i, j - 1), pii(i + 1, j),
                             pii(i - 1, j)};

  return nodes;
}

bool no_grid(pii node, int n) {
  auto [i, j] = node;
  return i >= 0 && i < n && j >= 0 && j < n;
}

vector<pii> cria_posicoes_fantasma(const vector<char> &movimentos_fantasma, pii inicio_fantasma, int n) {
  vector<pii> posicoes_fantasma;

  pii posicao_atual = inicio_fantasma;
  posicoes_fantasma.push_back(posicao_atual);

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
  queue<pair<pii, int>> fila;  // fila que guarda {posicao,dist}
  fila.push({inicio_pacman,0});
  dist[inicio_pacman.first][inicio_pacman.second] = 0;

  while (!fila.empty()) {
    auto [no, dist_atual] = fila.front();
    fila.pop();

    for (auto [i, j] : vizinhos(no)) {
      if (no_grid({i, j}, n) and
          dist[i][j] == -1 and grid[i][j]!=1) {         // se estiver nos limites e não visitado
        dist[i][j] = dist_atual + 1;  //  atualizo a distância
        pai[i][j] = no;
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

  int min_dist = n * n + 2;
  pii min_pos;
  int n_posicoes= posicoes_fantasma.size();
  for (int i = 0; i < n_posicoes; i++) {
    auto [x, y] = posicoes_fantasma[i];
    if (dist[x][y] <= i and min_dist > dist[x][y] and dist[x][y]!=-1) {
      min_dist = dist[x][y];
      min_pos = {x, y};
    } else if (i == n_posicoes-1 and dist[x][y] != -1){
      min_dist = dist[x][y];
      min_pos = {x, y};
    }
  }

  if (min_dist == (n * n + 2)) {
    cout << "Não foi possível achar um caminho\n";
    return;
  }

  printa_solucao(pai,min_pos);
}

void atualiza_movimento(pii mov_filho, pii mov_pai, int &num_passos_, int &movimentos_cima_,
                 int &movimentos_baixo_, int &movimentos_esq_, int &movimentos_dir_) {
  auto [i1, j1] = mov_filho;
  auto [i2, j2] = mov_pai;
  int di = i2 - i1;
  int dj = j2 - j1;

  if (di == 1) {
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
