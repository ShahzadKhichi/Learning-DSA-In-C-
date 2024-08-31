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
bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isRebundent(string expression)
{
    if (!solve(expression))
    {
        cout << "Invalid Expression : " << endl;
        return false;
    }
    stack<char> s;
    bool rebundent = false;
    for (int i = 0; i < expression.size(); i++)
    {
        rebundent = true;
        if (expression[i] == '(' || isOperator(expression[i]))
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            //  cout << "there" << endl;
            if (!s.empty())
            {
                //  cout << "there" << endl;
                while (s.top() != '(')
                {

                    if (isOperator(s.top()))
                    {
                        rebundent = false;
                    }
                    s.pop();
                }
            }
            if (rebundent)
            {
                return true;
            }
        }
    }
    return rebundent;
}
int main()
{
    string str;
    cout << "Enter expression : ";
    cin >> str;
    bool ans = isRebundent(str);
    if (ans)
    {
        cout << "Expression is Rebundent" << endl;
    }
    else
    {
        cout << "Expression Not Rebundent" << endl;
    }
    return 0;
}