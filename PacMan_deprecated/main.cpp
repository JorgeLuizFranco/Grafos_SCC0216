/*
 * ARTHUR QUEIROZ MOURA
 * NUSP - 13671532
 *
 */


#include "grafo.h"

int main() {
    char nome_arquivo_entrada[100];
    scanf("%s", nome_arquivo_entrada);

    Grafo g = Grafo::grafo_de_arquivo(nome_arquivo_entrada);

    std::vector<int> ciclo = g.acha_ciclo_euleriano();

    // A função acha_ciclo_euleriano retorna um vetor vazio caso não haja
    // nenhum ciclo euleriano
    // Caso haja, retorna um vetor com os integrantes do ciclo
    if ((int)ciclo.size() == 0) {
        printf("Não\n");
    } else {
        printf("Sim\n");

        for (int i = 0; i < (int)ciclo.size(); i++) {
            printf("%d ", ciclo[i]);
        }

        printf("\n");
    }
}
