#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {

            cout << v[i][j] << " ";
            if ((j + 1) % n == 0)
            {
                cout << endl;
            }
        }
        cout << "next Result : " << endl;
    }
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x, y;
    y = row;
    x = col;
    while (x >= 0)
    {
        if (board[y][x] == 1)
        {
            return false;
        }
        x--;
    }
    y = row;
    x = col;
    while (x >= 0 && y >= 0)
    {
        if (board[y][x] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    y = row;
    x = col;
    while (x >= 0 && y < n)
    {
        if (board[y][x] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 1;
            solve(col + 1, board, ans, n);
            board[i][col] = 0;
        }
    }
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, board, ans, n);
    print(ans, n);
    return 0;
}