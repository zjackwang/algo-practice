#include <algorithm>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void explore(vector<vector<int>> &adj, vector<int> &visited, vector<int> &order, int x)
{
  vector<int> stack;
  stack.push_back(x);
  int vertex = 0;
  visited[vertex] = 1;
  while (stack.size() > 0)
  {
    vertex = stack.back();
    bool isTail = true;

    for (int i = 0; i < adj[vertex].size(); i++)
    {
      if (visited[adj[vertex][i]] == 0)
      {
        stack.push_back(adj[vertex][i]);
        visited[adj[vertex][i]] = 1;
        isTail = false;
      }
    }

    if (isTail)
    {
      order.push_back(vertex);
      stack.pop_back();
    }
    std::cout << "exploring " << vertex << std::endl;
  }
}

int number_of_strongly_connected_components(vector<vector<int>> adj)
{
  int result = 0;
  vector<vector<int>> rev_adj(adj.size(), vector<int>());
  for (int i = 0; i < adj.size(); i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      rev_adj[adj[i][j]].push_back(i);
    }
  }

  for (int i = 0; i < rev_adj.size(); i++)
  {
    for (int j = 0; j < rev_adj[i].size(); j++)
    {
      std::cout << rev_adj[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // Find source of rev_adj
  vector<int> post_order;
  vector<int> visited(adj.size(), 0);
  for (int i = 0; i < adj.size(); i++)
  {
    if (visited[i] == 0)
    {
      vector<int> orderstack;
      explore(rev_adj, visited, orderstack, i);
      for (int i = 0; i < orderstack.size(); i++)
      {
        post_order.push_back(orderstack[i]);
      }
    }
  }
  for (size_t i = 0; i < post_order.size(); i++)
  {
    std::cout << post_order[i] + 1 << " ";
  }
  std::cout << std::endl;

  // Explore rev_adj from source
  vector<int> used(adj.size(), 0);
  vector<int> temp;
  for (int i = post_order.size() - 1; i >= 0; i--)
  {
    std::cout << post_order[i] << " " << used[post_order[i]] << std::endl;
    if (used[post_order[i]] == 0)
    {
      explore(adj, used, temp, post_order[i]);
      result++;
    }
  }

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
