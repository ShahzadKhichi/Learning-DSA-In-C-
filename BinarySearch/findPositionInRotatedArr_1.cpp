#include <iostream>
#include <vector>
using namespace std;
int Pivot(vector<int> &v, int size)
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
int binarySearch(vector<int> &arr, int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int findPosition(vector<int> &v, int size, int key)
{
    int pivot = Pivot(v, size);
    if (key >= v[pivot] && key <= v[size - 1])
    {
        return binarySearch(v, pivot, size - 1, key);
    }
    else
    {
        return binarySearch(v, 0, pivot - 1, key);
    }
}
int main()
{
    int n, key;
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
    cout << "Enter Key : ";
    cin >> key;
    cout << "Position of Key = " << findPosition(v, n, key) << endl;
}