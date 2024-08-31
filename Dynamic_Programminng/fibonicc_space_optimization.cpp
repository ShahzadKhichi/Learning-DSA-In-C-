#include <iostream>
using namespace std;
int main()
{
    int n, pre1, pre2, curr;
    cout << "Enter n :";
    cin >> n;
    pre1 = 1;
    pre2 = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = pre1 + pre2;
        pre2 = pre1;
        pre1 = curr;
    }
    cout << "Nth number : " << pre1 << endl;
    return 0;
}