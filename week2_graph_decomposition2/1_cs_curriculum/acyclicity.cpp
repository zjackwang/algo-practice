#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int acyclic(vector<vector<int>> &adj)
{
  // with set
  unordered_set<int> visited;

  // dfs
  vector<int> stack;
  int vertex = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    if (visited.find(i) == visited.end())
    {
      stack.push_back(i);
      visited.insert(i);

      unordered_set<int> isOnStack;
      isOnStack.insert(i);
      // for (int j = 0; j < adj[i].size(); j++)
      // {
      //   stack.push_back(adj[i][j]);
      // }

      while (stack.size() > 0)
      {
        vertex = stack.back();
        stack.pop_back();
        isOnStack.erase(vertex);

        // cout << vertex << "\n"
        //      << endl;

        //cycle if revisiting a vertex
        // if (visited.find(vertex) != visited.end())
        if (isOnStack.find(vertex) != isOnStack.end())
        {
          return 1;
        }

        for (int j = 0; j < adj[vertex].size(); j++)
        {
          // cout << adj[vertex][j] << endl;
          stack.push_back(adj[vertex][j]);
        }
      }

      // visited.erase(i);
    }
  }

  return 0;
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
  }

  // for (int i = 0; i < adj.size(); i++)
  // {
  //   for (int j = 0; j < adj[i].size(); j++)
  //   {
  //     std::cout << adj[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  std::cout << acyclic(adj);
}
