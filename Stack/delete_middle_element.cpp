#include <iostream>
#include <stack>
#include <string>
using namespace std;
void solve(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    solve(s, count + 1, size);
    s.push(top);
}
void print(stack<int> s, int size)
{
    if (size <= 1)
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
    int size;
    cout << "Enter size : ";
    cin >> size;
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    solve(s, 0, size);
    cout << "without mid    : ";
    print(s, size);
    return 0;
}