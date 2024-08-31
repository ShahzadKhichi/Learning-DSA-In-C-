#include <iostream>
#include <vector>
using namespace std;
bool isPossibel(vector<int> &v, int n, int m, int mid)
{
    int pageSum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {

        if (pageSum + v[i] <= mid)
        {
            pageSum += v[i];
        }
        else
        {
            count++;
            if (count > m || v[i] > mid)
            {
                return false;
            }
            pageSum = v[i];
        }
    }
    return true;
}
int Allocator(vector<int> &v, int n, int m)
{
    int s, e = 0, mid, ans;
    ans = -1;
    s = 0;
    for (int i = 0; i < n; i++)
    {
        e += v[i];
    }
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (isPossibel(v, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Ans = " << Allocator(v, n, m) << endl;
    return 0;
}