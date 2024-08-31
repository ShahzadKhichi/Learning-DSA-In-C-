#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> g;
    void addEdge(T u, T n, bool direction)
    {
        g[u].push_back(n);
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
    return 0;
}