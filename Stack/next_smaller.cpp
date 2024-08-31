#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> solution(vector<int> v, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= v[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(v[i]);
    }
    return ans;
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
    vector<int> ans = solution(v, n);
    cout << "ans : ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}