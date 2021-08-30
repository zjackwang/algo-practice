#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

#define INF 10000000000

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  const int infinity = std::numeric_limits<int>::max();

  vector<long long> dists(adj.size(), INF);
  vector<int> prevs(adj.size(), -1);
  dists[s] = 0;

  auto compareFunc = [](pair<long long, int> lhs, pair<long long, int> rhs) { return lhs.first > rhs.first; };
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(compareFunc)> pq(compareFunc);
  for (int i = 0; i < adj.size(); i++)
  {
    if (i == s)
    {
      pair<long long, int> p(0, i);
      pq.push(p);
    }
    else
    {
      // -1 ==> dist is inf
      pair<long long, int> p(INF, i);
      pq.push(p);
    }
  }

  pair<long long, int> u;
  while (pq.size() > 0)
  {
    u = pq.top();
    pq.pop();
    std::cout << "Vertex: " << u.second << " Weight: " << u.first << std::endl;
    for (int i = 0; i < adj[u.second].size(); i++)
    {
      std::cout << std::endl;
      if (dists[u.second] + cost[u.second][i] < dists[adj[u.second][i]])
      {
        dists[adj[u.second][i]] = dists[u.second] + cost[u.second][i];
        prevs[adj[u.second][i]] = u.second;

        pair<long long, int> v(dists[adj[u.second][i]], adj[u.second][i]);
        pq.push(v);
      }
      for (int j = 0; j < dists.size(); j++)
      {
        std::cout << dists[j] << " ";
      }
    }
  }
  return dists[t] == INF ? -1 : dists[t];
}
int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
