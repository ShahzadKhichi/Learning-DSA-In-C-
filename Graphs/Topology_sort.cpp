#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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
void DFS(graph<int> &g, unordered_map<int, bool> &visited, stack<int> &ans, int node)
{

    visited[node] = 1;

    for (auto i : g.g[node])
    {
        if (!visited[i])
        {
            DFS(g, visited, ans, i);
        }
    }
    ans.push(node);
}
vector<int> solve(graph<int> &g)
{
    stack<int> component;
    vector<int> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.nodes.size(); i++)
    {
        if (!visited[g.nodes[i]])
        {
            DFS(g, visited, component, g.nodes[i]);
        }
    }
    while (!component.empty())
    {
        ans.push_back(component.top());
        component.pop();
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
    vector<int> ans = solve(g);
    cout << "DFS Traversal :  ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}