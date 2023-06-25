#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist, vector<int>& prev, int num_nodes) {
    vector<bool> processed(num_nodes, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u])
            continue;

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

int calculateDeliveryCostPadrao(const vector<vector<pair<int, int>>>& graph, int num_nodes) {
    vector<int> dist(num_nodes, INF);
    vector<int> prev(num_nodes, -1);
    dijkstra(graph, 0, dist, prev, num_nodes);

    int delivery_padrao_cost = 0;

    for (int i = 1; i < num_nodes; i++) { // Pulando nó de início (source=0)
        delivery_padrao_cost += (dist[i] - dist[prev[i]]); // Distancia ao nó i menos a distancia para o anterior
    }

    return delivery_padrao_cost - 1;
}

int calculateDeliveryCostVip(const vector<vector<pair<int, int>>>& graph, int num_nodes, int city_pedro) {
    vector<int> dist(num_nodes, INF);
    vector<int> prev(num_nodes, -1); // prev[source=0] sempre será -1
    dijkstra(graph, 0, dist, prev, num_nodes);

    int current_node = city_pedro;
    int num_cities_in_path = 0;

    while (prev[current_node] != -1) {
        current_node = prev[current_node];
        ++num_cities_in_path;
    }

    return dist[city_pedro] * (num_nodes - num_cities_in_path - 1);
}

int main() {
    int num_nodes, num_edges, city_pedro;
    cin >> num_nodes >> num_edges;

    vector<vector<pair<int, int>>> graph(num_nodes);

    for (int i = 0; i < num_edges; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    cin >> city_pedro;

    // Calculate delivery costs
    int delivery_padrao_cost = calculateDeliveryCostPadrao(graph, num_nodes);
    int delivery_vip_cost = calculateDeliveryCostVip(graph, num_nodes, city_pedro);

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

    return 0;
}
