#include <iostream>
#include <vector>
using namespace std;
int pivot(vector<int> &v, int size)
{
    int s, e, mid;
    s = 0;
    e = size - 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] >= v[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return e;
}
int main()
{
    int n;
    cout << "Enter Size Of arr : ";
    cin >> n;
    cout << "Sorted Index                    : ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Enter elemens In Sorted Ordered : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Position of pivot = " << pivot(v, n) << endl;
    return 0;
}