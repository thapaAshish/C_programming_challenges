#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> data;
void dfs(int u)
{
    visited[u] = true;
    for (auto a : adj[u])
    {
        if (!visited[a])
        {
            dfs(a);
        }
        data.push_back(a);
    }
}

void topologicalSorting(int k)
{
    for (int i = 1; i <= k; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(data.front(), data.back());
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int w;
        vector<int> d = {};
        for (int j = 0; j < w; j++)
        {
            cin >> d[j];
        }
        adj.push_back(d);
    }
}