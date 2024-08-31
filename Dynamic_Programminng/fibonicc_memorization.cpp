#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter a nth  Number : ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << "Nth number : " << dp[n] << endl;
    return 0;
}