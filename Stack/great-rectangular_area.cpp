#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
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
int solution(vector<int> v, int n)
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
int main()
{
    int n;
    cout << "Size = ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "ans : " << solution(v, n) << endl;
    return 0;
}