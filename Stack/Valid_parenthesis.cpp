#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool match(char ch, char top)
{
    if (ch == ')' && top == '(' ||
        ch == '}' && top == '{' ||
        ch == ']' && top == '[')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool solve(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else if (!s.empty() && expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (match(expression[i], s.top()))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            return false;
        }
        if (expression.size() - 1 != i && s.empty())
        {
            return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    string str;
    cout << "Enter expression : ";
    cin >> str;
    bool ans = solve(str);
    if (ans)
    {
        cout << "Valid Expression " << endl;
    }
    else
    {
        cout << "Invalid Expression " << endl;
    }
    return 0;
}