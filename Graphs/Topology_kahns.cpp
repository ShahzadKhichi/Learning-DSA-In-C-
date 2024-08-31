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
void bfs(graph<int> &g, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;
    vector<int> indegree(g.nodes.size() + 1, 0);
    for (auto i : g.g)
    {

        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : g.g[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
}
vector<int> solve(graph<int> &g)
{
    vector<int> ans;
    unordered_map<int, bool> visited;

    bfs(g, visited, ans, g.nodes[0]);

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
    cout << "Kahn's Topology :  ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}