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
    int arr[7] = {-1, 54, 53, 55, 52, 50, 66};
    int n = 6;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    print(arr, n);

    return 0;
}