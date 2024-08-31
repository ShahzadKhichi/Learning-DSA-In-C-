#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> g;
    vector<T> nodes;
    void addEdge(T u, T n, bool direction)
    {
        g[u].push_back(n);
        nodes.push_back(u);
        if (!direction)
        {
            g[n].push_back(u);
        }
    }
    void print()
    {
        for (auto i : g)
        {
            cout << i.first << " ---> | ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << "| " << endl;
        }
        cout << endl;
    }
};
bool isCycle(graph<int> &g, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs, int node)
{

    visited[node] = 1;
    dfs[node] = 1;
    for (auto i : g.g[node])
    {
        if (!visited[i])
        {
            bool ans = isCycle(g, visited, dfs, i);

            if (ans)
            {
                return true;
            }
        }
        else if (dfs[i])
        {
            return true;
        }
    }
    dfs[node] = 0;
    return false;
}
bool solve(graph<int> &g)
{

    bool ans;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfs;
    for (int i = 0; i < g.nodes.size(); i++)
    {
        if (!visited[g.nodes[i]])
        {
            ans = isCycle(g, visited, dfs, g.nodes[i]);
            if (ans)
            {
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    int n, v;

    cout << "Enter number of edges : ";
    cin >> v;
    cout << "Enter number of Nodes : ";
    cin >> v;
    graph<int> g;
    for (int j = 0; j < v; j++)
    {
        int e, m;
        cin >> m >> e;
        g.addEdge(m, e, 1);
    }
    g.print();
    cout << "isCycle  :  " << solve(g) << endl;

    return 0;
}