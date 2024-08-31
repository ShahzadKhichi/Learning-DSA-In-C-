#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int solution(vector<vector<int>> v, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    int a, b;
    while (s.size() > 1)
    {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        if (v[a][b])
        {
            s.push(b);
        }
        else if (v[b][a])
        {
            s.push(a);
        }
    }
    int ans = s.top();
    bool rowCheck = true;
    for (int i = 0; i < n; i++)
    {
        if (v[ans][i] != 0)
        {
            rowCheck = false;
        }
    }
    bool colCheck = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i][ans] != 1 && ans != i)
        {
            colCheck = false;
        }
    }
    if (colCheck && rowCheck)
    {
        return ans;
    }
    return -1;
}
int main()
{

    int n;
    vector<vector<int>> v(n);
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        v[i] = vector<int>(n);
        cout << i << " : ";
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << "Celebrity = " << solution(v, n) << endl;
    return 0;
}