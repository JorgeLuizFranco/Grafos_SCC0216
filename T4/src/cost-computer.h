#pragma once
#include <queue> // needed in the .cpp for the priority queue
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

// the functions are explained in the .cpp

pair<int,int> calculateDeliveryCosts(const vector<vector<pair<int, int>>>& graph, int num_nodes,
                             int city_pedro, vector<tuple<int,int,int>>& edges);
