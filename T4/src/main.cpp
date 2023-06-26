/**
 * TRABALHO 4 DE GRAFOS - TRANSPORTE DE COMPUTADORES
 *
 * ARTHUR QUEIROZ MOURA - 13671532
 * JORGE LUIZ FRANCO - 13695091
 */

#include "cost-computer.h"
#include <iostream>

void read_input(int& num_nodes, int& num_edges, int& city_pedro,
                vector<vector<pair<int, int>>>& graph);

void print_best_option(int num_nodes, int city_pedro, vector<vector<pair<int, int>>>& graph);

int main() {
    int num_nodes, num_edges, city_pedro;
    // graph[a] is a vector of pairs. { [...], {neig_i, w_i}, [...] } indicates that neig_i is a
    // neigbor of 'a' and the edge from 'a' to neig_i has weight w_i
    vector<vector<pair<int, int>>> graph;

    read_input(num_nodes, num_edges, city_pedro, graph);

    print_best_option(num_nodes, city_pedro, graph);

    return 0;
}

void read_input(int& num_nodes, int& num_edges, int& city_pedro,
                vector<vector<pair<int, int>>>& graph) {
    cin >> num_nodes >> num_edges;

    graph.resize(num_nodes, vector<pair<int, int>>()); // num_nodes empty pair<int, int> vectors

    for (int i = 0; i < num_edges; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    cin >> city_pedro;
}

void print_best_option(int num_nodes, int city_pedro, vector<vector<pair<int, int>>>& graph) {
    // Calculate delivery costs
    

    auto [delivery_padrao_cost, delivery_vip_cost] = calculateDeliveryCosts(graph,num_nodes,city_pedro);

    // Determine the best option
    string best_option;
    int best_cost;

    if (delivery_padrao_cost < delivery_vip_cost) {
        best_option = "PADRAO";
        best_cost = delivery_padrao_cost;
    } else if (delivery_vip_cost < delivery_padrao_cost) {
        best_option = "VIP";
        best_cost = delivery_vip_cost;
    } else {
        best_option = "NDA";
        best_cost = delivery_padrao_cost;
    }

    // Output the result
    cout << best_option << endl;
    cout << best_cost << endl;
}