#include "cost-computer.h"

const int INF = 1e9;

// given a graph (represented by a vector of vectors of pair<int, int>, which is explained in
// main.cpp) and a begginning vertex, this function changes the dist vector so that
// dist[x] is the smallest possible distance from start to x
// prev is also a vector that is altered.
// prev[x] is the vertex which goes to x in the path of shorted distance from start to x
void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist,
              vector<int>& prev, int num_nodes) {

    // Classical dijkstra algorithm
    vector<bool> processed(num_nodes, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) continue;

        processed[u] = true;

        for (auto& neighbor : graph[u]) {
            auto [v, weight] = neighbor;

            if (!processed[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// given the graph, it sets up the distance and previous vectors and runs dijkstra's algorithm using
// the function above. Then it finds the cost of a standard delievery
int calculateDeliveryStandardCost(const vector<vector<pair<int, int>>>& graph, int num_nodes) {
    vector<int> dist(num_nodes, INF);
    vector<int> prev(num_nodes, -1);
    dijkstra(graph, 0, dist, prev, num_nodes);

    int delivery_padrao_cost = 0;

    for (int i = 1; i < num_nodes; i++) { // Starting node is the source=0, so it is ignored
        delivery_padrao_cost += (dist[i] - dist[prev[i]]); // Distance from node prev[i] to node i
    }

    return delivery_padrao_cost - 1;
}

int calculateDeliveryCostVip(const vector<vector<pair<int, int>>>& graph, int num_nodes,
                             int city_pedro) {
    vector<int> dist(num_nodes, INF);
    vector<int> prev(num_nodes, -1); // prev[source=0] will always be -1
    dijkstra(graph, 0, dist, prev, num_nodes);

    int current_node = city_pedro;
    int num_cities_in_path = 0;

    while (prev[current_node] != -1) {
        current_node = prev[current_node]; // backtracking to initial city
        ++num_cities_in_path;
    }

    return dist[city_pedro] * (num_nodes - num_cities_in_path - 1);
}
