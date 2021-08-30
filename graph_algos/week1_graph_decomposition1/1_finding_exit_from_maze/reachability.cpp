#include <iostream>
#include <vector>
#include <unordered_set>

using std::pair;
using std::unordered_set;
using std::vector;

// dfs recursive
int explore_recursive(vector<vector<int>> &adj, unordered_set<int> visited, int v, int target)
{
  std::cout << v << std::endl;
  if (v == target)
    return 1;
  visited.insert(v);
  int found = 0;
  for (int neighbor = 0; neighbor < adj[v].size(); neighbor++)
  {
    if (visited.find(neighbor) == visited.end())
    {
      found = found || explore_recursive(adj, visited, adj[v][neighbor], target);
    }
  }
  return found;
}

int reach(vector<vector<int>> &adj, int x, int y)
{
  unordered_set<int> visited;
  vector<int> stack;
  stack.push_back(x);

  // dfs iterative
  int vertex = 0;
  while (stack.size() != 0)
  {
    vertex = stack.back();
    stack.pop_back();

    if (visited.find(vertex) == visited.end())
    {
      visited.insert(vertex);
      if (vertex == y)
      {
        return 1;
      }
      for (int i = 0; i < adj[vertex].size(); i++)
      {
        stack.push_back(adj[vertex][i]);
      }
    }
  }

  return 0;

  return explore_recursive(adj, visited, x, y);
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  for (int i = 0; i < adj.size(); i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      std::cout << adj[i][j] << " ";
    }
    std::cout << std::endl;
  }

  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
