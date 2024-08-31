#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int sum(vector<int> arr, int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[i];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else if (mini.top() < sum)
            {
                mini.pop();
                mini.push(sum);
            }
        }
    }
    return mini.top();
}

int main()
{
    vector<int> v;
    int n, k;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter values : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << "Enter k : ";
    cin >> k;
    cout << "Target sum : " << sum(v, n, k) << endl;
    return 0;
}