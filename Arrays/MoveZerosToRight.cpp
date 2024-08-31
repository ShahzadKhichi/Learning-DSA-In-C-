#include <iostream>
#include <vector>
using namespace std;
void ZerosToRight(vector<int> &v, int n)
{
    int i = 0;
    int j = i + 1;
    while (j < n)
    {
        if (v[j] != 0 && v[i] == 0)
        {
            swap(v[i], v[j]);
            i++;
        }
        if (v[i] != 0)
        {
            i++;
        }
        j++;
    }
}
int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ZerosToRight(v, n);
    cout << "Sorted Arr     : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}