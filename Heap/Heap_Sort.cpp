#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[7] = {-1, 54, 53, 66, 55, 52, 50};
    int n = 6;
    for (int i = 1; i <= n; i++)
    {
        heapify(arr, n, i);
    }
    heapSort(arr, n);
    cout << "printing in Sorted Order : ";
    print(arr, n);
    return 0;
}