#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using std::queue;
using std::vector;

int distance(vector<vector<int>> &adj, int s, int t)
{
  vector<int> dists(adj.size(), -1);
  queue<int> q;

  dists[s] = 0;
  q.push(s);

  // for (int i = 0; i < adj.size(); i++)
  // {
  //   for (int j = 0; j < adj[i].size(); j++)
  //   {
  //     std::cout << adj[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  int vertex;
  while (q.size() != 0)
  {
    vertex = q.front();
    q.pop();

    for (int i = 0; i < adj[vertex].size(); i++)
    {
      if (dists[adj[vertex][i]] == -1)
      {
        dists[adj[vertex][i]] = dists[vertex] + 1;
        q.push(adj[vertex][i]);
      }
    }
    // std::cout << q.size() << std::endl;
  }

  return dists[t];
}

void tests()
{
  vector<vector<int>> adj = {{1, 3, 2},
                             {0, 2},
                             {1, 0},
                             {0}};
  int source = 1, dest = 3;
  int expected = 2;

  int actual = distance(adj, source, dest);

  assert(actual == expected);
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);

  tests();
}
