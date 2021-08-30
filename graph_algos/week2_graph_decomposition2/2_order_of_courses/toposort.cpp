#include <iostream>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<int> &used, vector<int> &order, int x)
{
  vector<int> stack;
  vector<int> orderstack;
  stack.push_back(x);
  int vertex = 0;
  while (stack.size() > 0)
  {
    vertex = stack.back();
    stack.pop_back();
    if (used[vertex] == 0)
    {
      used[vertex] = 1;
      for (int i = 0; i < adj[vertex].size(); i++)
      {
        stack.push_back(adj[vertex][i]);
      }
      orderstack.push_back(vertex);
    }
  }
  for (int i = orderstack.size() - 1; i >= 0; i--)
  {
    order.push_back(orderstack[i]);
  }
}

vector<int> toposort(vector<vector<int>> adj)
{
  vector<int> used(adj.size(), 0);
  vector<int> order;

  for (int i = 0; i < adj.size(); i++)
  {
    if (used[i] == 0)
    {
      dfs(adj, used, order, i);
    }
    for (int j = 0; j < order.size(); j++)
    {
      std::cout << order[j] << " ";
    }
    std::cout << "\n";
  }

  vector<int> rev_order(order.size(), 0);
  for (int i = 0; i < order.size(); i++)
  {
    rev_order[order.size() - 1 - i] = order[i];
  }

  std::cout << "\n";

  return rev_order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++)
  {
    std::cout << order[i] + 1 << " ";
  }
}
