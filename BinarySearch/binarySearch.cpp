#include <iostream>
using namespace std;
int binarySearch(int *arr, int size, int key)
{
    int start, end;
    start = 0;
    end = size - 1;
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
int main()
{
    int *arr;
    int n, key;
    cout << "Enter size of Sortef Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Key For search  : ";
    cin >> key;
    cout << "Index of " << key << " is " << binarySearch(arr, n, key) << endl;
    delete[] arr;
    return 0;
}