#include "union_find.h"

UnionFind::UnionFind(int size) {
  parent.resize(size);
  rank.resize(size, 0);
  for (int i = 0; i < size; i++) {
    parent[i] = i;
  }
}

int UnionFind::find(int element) {
  if (parent[element] != element) {
    parent[element] = find(parent[element]);  // Path compression
  }
  return parent[element];
}

void UnionFind::unite(int element1, int element2) {
  int root1 = find(element1);
  int root2 = find(element2);
  if (root1 != root2) {
    if (rank[root1] < rank[root2]) {
      parent[root1] = root2;
    } else if (rank[root1] > rank[root2]) {
      parent[root2] = root1;
    } else {
      parent[root2] = root1;
      rank[root1]++;
    }
  }
}

bool UnionFind::isConnected(int element1, int element2) {
  return find(element1) == find(element2);
}
