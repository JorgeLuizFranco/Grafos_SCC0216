#include "grafo.h"

// A função geral de cada uma das funções desse arquivo está documentada
// no grafo.h

Grafo::Grafo(std::vector<std::pair<int, int>> descricao) {
    // o primeiro par do vetor descrição contém o número de vértices e o de arestas
    num_vertices = descricao[0].first;

    // Adiciona vetores inicialmente vazios para a lista de adjacências
    // ou seja, por enquanto nenhum vértice tem vizinhos
    for (int i = 0; i < num_vertices; i++) {
        lista_adjacencias.push_back(std::vector<int>());
    }

    // de acordo com a quantidade de arestas, percorre o vetor 'descrição'
    // e vai colocando as interações entre os vértices na lista de adjacências
    for (int i = 1; i <= descricao[0].second; i++) {
        lista_adjacencias[descricao[i].first].push_back(descricao[i].second);
        lista_adjacencias[descricao[i].second].push_back(descricao[i].first);
    }
}

Grafo Grafo::grafo_de_arquivo(char* nome_arq) {
    // Se for NULL, gerar um run time error
    FILE* arq = fopen(nome_arq, "r");
    if (arq == NULL) {
        throw std::runtime_error("Erro ao abrir o arquivo.\n");
    }

    // Constrói um vetor de pares de inteiros 'descrição'
    // Vai lendo o arquivo e construindo esse vetor
    std::vector<std::pair<int, int>> descricao;
    int n_vertices, n_arestas;
    fscanf(arq, "%d %d", &n_vertices, &n_arestas);

    descricao.push_back(std::make_pair(n_vertices, n_arestas));

    int v_atual1, v_atual2;
    for (int i = 0; i < n_arestas; i++) {
        fscanf(arq, "%d %d", &v_atual1, &v_atual2);
        descricao.push_back(std::make_pair(v_atual1, v_atual2));
    }

    fclose(arq);
    
    // quando o vetor for construído, uso ele como argumento do construtor
    return Grafo(descricao);
}

std::vector<int> Grafo::acha_ciclo_euleriano() {
    std::vector<int> ciclo;
    for (int i = 0; i < num_vertices; i++) {
        // Se houver algum vértice com grau ímpar, não existe ciclo euleriano
        if (((int)lista_adjacencias[i].size()) % 2 == 1) {
            // nesse caso, retornar vetor de inteiros vazio
            return ciclo;
        }
    }

    // Se todos os vértices forem de grau par, então existe ciclo euleriano
    // Para achar esse ciclo, primeiro copiamos a lista de adjacências porque o algoritmo
    // empregado para detectar ciclos precisará modificar essa lista de adjacências

    std::vector<int> pilha;
    std::vector<std::vector<int > > copia_lista_adjacencias(num_vertices);
    
    for (int i = 0; i < num_vertices; i++) {
        // Para cada i, mudo o tamanho de copia_lista_adjacencias[i] para lista_adjacencias[i]
        copia_lista_adjacencias[i].resize(lista_adjacencias[i].size());
        // depois copio o conteúdo de lista_adjacencias[i] para copia_lista_adjacencias[i]
        std::copy(lista_adjacencias[i].begin(), lista_adjacencias[i].end(), copia_lista_adjacencias[i].begin());
        // depois, ordeno copia_lista_adjacencias[i]
        // isso fará com que, quando o algoritmo rode, ele sempre considerará o ciclo que leva ao vértice
        // de menor número
        std::sort(copia_lista_adjacencias[i].begin(), copia_lista_adjacencias[i].end());
    }
    
    // Agora, aplicamos um algoritmo de detecção de ciclos
    // Iniciamos com o vértice 0 e colocamos ele numa pilha

    // Escolha o vértice inicial 0
    int v_atual = 0;
    pilha.push_back(v_atual);

    while (!pilha.empty()) {
        // Enquanto a pilha não estiver vazia

        // Verifique se possui algum vizinho
        if ((int)copia_lista_adjacencias[v_atual].size() > 0) {
            // Se possuir, adicione à pilha, diga que o atual é esse vizinho e exclua
            // a aresta que os liga
            pilha.push_back(v_atual);
            int prox_v = copia_lista_adjacencias[v_atual][0];
            copia_lista_adjacencias[v_atual].erase(copia_lista_adjacencias[v_atual].begin());
            copia_lista_adjacencias[prox_v].erase(
                std::find(copia_lista_adjacencias[prox_v].begin(), copia_lista_adjacencias[prox_v].end(), v_atual)
            );
            v_atual = prox_v;
        } else {
            // quando eu não achar um vizinho, quer dizer que achei um ciclo
            // faça back-tracking até que eu ache alguém desse ciclo que tenha algum vizinho
            // Vou achar outro ciclo com esse vizinho e unirei os dois
            ciclo.push_back(v_atual);
            v_atual = pilha.back();
            pilha.pop_back();
        }
    }

    // Devido à lógica de back-tracking, é necessário reverter o vetor ciclo
    std::reverse(ciclo.begin(), ciclo.end());

    return ciclo;
}
