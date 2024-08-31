#include <iostream>
#include <stack>
#include <string>
using namespace std;
int solution(string str)
{
    int a, b, ans = 0;
    if (str.size() % 2 == 1)
    {
        return -1;
    }
    else
    {
        stack<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '{')
            {
                s.push(str[i]);
            }
            else if (str[i] == '}')
            {
                while (!s.empty() && s.top() == '}')
                {
                    s.pop();
                }
                s.pop();
            }
        }
        if (s.empty())
        {
            return 0;
        }
        a = 0;
        b = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '{')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        ans = ((a + 1) / 2) + ((b + 1) / 2);
        return ans;
    }
}
int main()
{
    string str;
    cout << "Enter  string : ";
    cin >> str;
    cout << "Ans = " << solution(str) << endl;
    return 0;
}