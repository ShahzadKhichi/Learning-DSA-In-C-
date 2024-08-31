#include <iostream>
#include <unordered_map>
#include <algorithm>
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
void bfs(graph<int> &g, unordered_map<int, bool> &visited, vector<int> &ans, int node, int t)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    unordered_map<int, int> parent;
    parent[node] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : g.g[front])
        {
            if (!visited[i])
            {
                parent[i] = front;
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    int curr = t;

    while (curr != node)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(curr);
    reverse(ans.begin(), ans.end());
}
vector<int> solve(graph<int> &g, int s, int t)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    bfs(g, visited, ans, s, t);
    return ans;
}
int main()
{
    int n, v, s, t;

    cout << "Enter number of edges : ";
    cin >> v;
    cout << "Enter number of Nodes : ";
    cin >> v;
    v++;
    graph<int> g;
    for (int j = 0; j < v; j++)
    {
        int e, m;
        cin >> m >> e;
        g.addEdge(m, e, 0);
    }
    cout << "Enter start : ";
    cin >> s;
    cout << "Enter end : ";
    cin >> t;
    g.print();

    vector<int> ans = solve(g, s, t);
    cout << "Shortest path : [ ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}