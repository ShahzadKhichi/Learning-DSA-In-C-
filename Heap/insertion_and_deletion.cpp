#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
    }
    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            if (arr[index] > arr[index / 2])
            {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }
    void deleteRoot()
    {
        if (size == 0)
        {
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        int left = i * 2;
        int right = i * 2 + 1;
        while (i < size)
        {
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(3);
    h.insert(5);
    h.insert(2);
    h.insert(6);
    h.print();
    h.deleteRoot();
    h.print();
    h.deleteRoot();
    h.print();
    return 0;
}