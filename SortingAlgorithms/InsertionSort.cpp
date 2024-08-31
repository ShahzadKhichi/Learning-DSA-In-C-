#include <iostream>
#include <vector>
using namespace std;
void Sort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (v[j] > temp)
            {
                v[j + 1] = v[j];
            }
            else
            {
                break;
            }
        }
        v[j + 1] = temp;
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
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
    Sort(v, n);
    cout << "Sorted Arr     : ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}