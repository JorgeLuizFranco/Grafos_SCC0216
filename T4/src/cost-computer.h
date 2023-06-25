#pragma once
#include <queue> // needed in the .cpp for the priority queue
#include <utility>
#include <vector>

using namespace std;

// the functions are explained in the .cpp

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist,
              vector<int>& prev, int num_nodes);

int calculateDeliveryStandardCost(const vector<vector<pair<int, int>>>& graph, int num_nodes);

int calculateDeliveryCostVip(const vector<vector<pair<int, int>>>& graph, int num_nodes,
                             int city_pedro);
