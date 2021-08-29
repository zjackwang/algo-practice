#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using std::queue;
using std::vector;

int bipartite(vector<vector<int>> &adj)
{
  // -1: unexplored, 0: white, 1: black
  vector<int> coloring(adj.size(), -1);
  queue<int> q;

  coloring[0] = 0;
  q.push(0);

  int vertex;
  while (q.size() > 0)
  {
    vertex = q.front();
    q.pop();

    for (int i = 0; i < adj[vertex].size(); i++)
    {
      if (coloring[adj[vertex][i]] == -1)
      {
        coloring[adj[vertex][i]] = coloring[vertex] == 0 ? 1 : 0;
        q.push(adj[vertex][i]);
      }
      else
      {
        if (coloring[adj[vertex][i]] == coloring[vertex])
          return 0;
      }
    }
  }

  return 1;
}

void test()
{
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
