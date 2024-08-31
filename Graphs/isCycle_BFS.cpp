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
bool isCylce(graph<int> &g, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node)
{
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : g.g[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
            else if (i != parent[front])
            {
                return true;
            }
        }
    }
    return false;
}
bool solve(graph<int> &g)
{

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    for (int i = 0; i < g.nodes.size(); i++)
    {
        if (!visited[g.nodes[i]])
        {
            bool ans = isCylce(g, visited, parent, g.nodes[i]);
            if (ans)
            {
                return ans;
            }
        }
    }
    return false;
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
        g.addEdge(m, e, 0);
    }
    g.print();
    cout << "isCylce  :  " << solve(g) << endl;

    return 0;
}