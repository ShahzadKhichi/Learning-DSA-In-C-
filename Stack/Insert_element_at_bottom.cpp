#include <iostream>
#include <stack>
#include <string>
using namespace std;
void solve(stack<int> &s, int count, int size, int element)
{
    if (count == size)
    {
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    solve(s, count + 1, size, element);
    s.push(top);
}
void print(stack<int> s, int size)
{
    if (size <= 0)
    {
        return;
    }
    int top = s.top();
    s.pop();
    print(s, size - 1);
    cout << top << " ";
}
int main()
{
    stack<int> s;
    int size, n;
    cout << "Enter size : ";
    cin >> size;
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    cout << "Enter Element for bottom : ";
    cin >> n;
    solve(s, 0, size, n);
    cout << "with new Bottom   : ";
    print(s, size + 1);
    return 0;
}