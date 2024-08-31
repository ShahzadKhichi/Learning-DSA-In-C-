#include <iostream>
#include <vector>
using namespace std;
int firsOcc(vector<int> &arr, int size, int key)
{
    int s, e, ans;
    s = 0;
    e = size - 1;
    ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOcc(vector<int> &arr, int size, int key)
{
    int s, e, ans;
    s = 0;
    e = size - 1;
    ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
pair<int, int> firstLastOcc(vector<int> &arr, int size, int key)
{
    pair<int, int> p;
    p.first = firsOcc(arr, size, key);
    p.second = lastOcc(arr, size, key);
    return p;
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
    cout << "Ente Key : ";
    cin >> key;
    pair<int, int> p = firstLastOcc(v, n, key);
    cout << p.first << " " << p.second << endl;

    return 0;
}