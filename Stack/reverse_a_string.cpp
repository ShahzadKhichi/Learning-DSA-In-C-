#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverse(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    string ans = "";
    while (!s.empty())
    {
        char ch = s.top();
        s.pop();
        ans.push_back(ch);
    }
    return ans;
}
int main()
{
    string str;
    cout << "Enter a string : ";
    getline(cin, str);
    cout << "Reverse : " << reverse(str) << endl;
    return 0;
}