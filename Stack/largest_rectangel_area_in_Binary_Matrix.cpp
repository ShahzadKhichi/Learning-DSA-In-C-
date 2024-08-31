#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> next(vector<int> v, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && !s.empty() && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> pre(vector<int> v, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && !s.empty() && v[s.top()] >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int Area(vector<int> v, int n)
{
    int area = 0;
    vector<int> pr = pre(v, n);
    vector<int> ne = next(v, n);
    for (int i = 0; i < n; i++)
    {
        int h = v[i];
        if (ne[i] == -1)
        {
            ne[i] = n;
        }
        int w = ne[i] - pr[i] - 1;
        int newArea = w * h;
        area = max(newArea, area);
    }
    return area;
}
int solution(vector<vector<int>> v, int n, int m)
{
    int area = Area(v[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0)
            {
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }
        area = max(area, Area(v[i], m));
    }
    return area;
}
int main()
{
    int n;
    int m;

    cout << "Enter n : ";
    cin >> n;
    cout << "Enter m : ";
    cin >> m;
    cout << "Enter Elements : " << endl;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << "Area = " << solution(v, n, m) << endl;
    return 0;
}