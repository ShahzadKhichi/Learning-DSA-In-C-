#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isMove(vector<vector<int>> &v, int i, int j, vector<vector<int>> &visited, int n)
{
    if (i < n && i >= 0 && j < n && j >= 0 && visited[j][i] == 0 && v[j][i] == 1)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &v, vector<vector<int>> &visited, int n, string &str, vector<string> &ans, int x = 0, int y = 0)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(str);
        return;
    }
    int i, j;
    i = x;
    j = y + 1;
    visited[y][x] = 1;
    if (isMove(v, i, j, visited, n))
    {
        str.push_back('D');
        solve(v, visited, n, str, ans, i, j);
        str.pop_back();
    }

    i = x + 1;
    j = y;
    if (isMove(v, i, j, visited, n))
    {
        str.push_back('R');
        solve(v, visited, n, str, ans, i, j);
        str.pop_back();
    }
    i = x - 1;
    j = y;
    if (isMove(v, i, j, visited, n))
    {
        str.push_back('L');
        solve(v, visited, n, str, ans, i, j);
        str.pop_back();
    }
    i = x;
    j = y - 1;
    if (isMove(v, i, j, visited, n))
    {
        str.push_back('U');
        solve(v, visited, n, str, ans, i, j);
        str.pop_back();
    }
    visited[y][x] = 0;

    return;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;

    vector<vector<int>> v(n);
    cout << "Enter value : " << endl;

    for (int i = 0; i < n; i++)
    {
        v[i] = vector<int>(n);

        for (int j = 0; j < n; j++)
        {

            cin >> v[i][j];
        }
    }
    cout << "-------------------------------- " << endl;

    vector<vector<int>> visited(n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    vector<string> ans;
    string str = "";
    if (v[0][0] == 1)
        solve(v, visited, n, str, ans);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " , ";
    }
    cout << "]" << endl;

    return 0;
}