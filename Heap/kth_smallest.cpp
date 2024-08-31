#include <iostream>
#include <queue>
using namespace std;
int solution(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ans = -1;
    for (int i = 0; i < k; i++)
    {
        ans = pq.top();
        pq.pop();
    }

    return ans;
}
int main()
{
    int arr[5] = {12, 3, 4, 5, 6};
    cout << "Ans :  " << solution(arr, 5, 1) << endl;
    return 0;
}