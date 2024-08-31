#include <iostream>
#include <vector>
using namespace std;
int squareRoot(int n)
{
    int s, e, mid, ans;
    s = 0;
    e = n - 1;
    ans = 0;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
double Precesions(double sqr, int n, int preNum)
{
    double pre = 1.0;
    for (int i = 0; i < preNum; i++)
    {
        pre /= 10.0;
        for (double j = sqr; (j * j) < n; j += pre)
        {
            sqr = j;
        }
    }
    return sqr;
}
int main()
{
    int n, pre;
    cout << "Enter A Number : ";
    cin >> n;
    int sqr = squareRoot(n);
    cout << "Enter Presceions Number : ";
    cin >> pre;
    cout << "Sqaure root = " << Precesions(sqr, n, pre) << endl;
    return 0;
}