#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
public:
  UnionFind(int size);
  int find(int element);
  void unite(int element1, int element2);
  bool isConnected(int element1, int element2);

private:
  std::vector<int> parent;
  std::vector<int> rank;
};

#endif  // UNION_FIND_H
