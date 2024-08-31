#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (v[j + 1] < v[j])
            {
                swap(v[j], v[j + 1]);
            }
        }
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
    BubbleSort(v, n);
    cout << "Sorted Arr     : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}