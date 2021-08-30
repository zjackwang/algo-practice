#include <iostream>
#include <vector>
#include <unordered_set>

using std::pair;
using std::unordered_set;
using std::vector;

int number_of_components(vector<vector<int>> &adj)
{
  int res = 0;
  unordered_set<int> visited;
  vector<int> vertex_stack;

  int vertex = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    // Try to visit every vertex
    if (visited.find(i) == visited.end())
    {
      std::cout << i << std::endl;
      vertex_stack.push_back(i);

      // explore vertex
      while (vertex_stack.size() > 0)
      {
        vertex = vertex_stack.back();
        vertex_stack.pop_back();
        // visited or unvisited?
        if (visited.find(vertex) == visited.end())
        {
          std::cout << "-" << vertex << std::endl;

          visited.insert(vertex);
          // explore neighbors
          for (int j = 0; j < adj[vertex].size(); j++)
          {
            vertex_stack.push_back(adj[vertex][j]);
          }
        }
      }
      res++;
    }
  }

  return res;
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
  std::cout << std::endl;
  std::cout << number_of_components(adj);
}
