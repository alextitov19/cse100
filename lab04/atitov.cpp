#include <iostream>
using namespace std;

void maxHeapify(int *arr, int i, int len)
{
    int left = i * 2 + 1;
    int right = left + 1;
    int largest = i;
    // cout << "I: " << i << " Left: " << arr[left] << " Right: " << arr[right] << endl;
    if (left <= len && arr[left] > arr[i])
    {
        largest = left;
    }
    if (right <= len && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int x = arr[largest];
        // cout << "Got x: " << x << endl;
        arr[largest] = arr[i];
        arr[i] = x;
        // for (int i = 0; i < len; i++)
        // {
        //     cout << arr[i] << ";";
        // }
        // cout << endl;
        maxHeapify(arr, largest, len);
    }
}

void buildMaxHeap(int *arr, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        maxHeapify(arr, i, len);
    }
}

void heapSort(int *arr, int len)
{
    int size = len - 1;
    buildMaxHeap(arr, size);
    for (int i = len - 1; i > 0; i--)
    {
        int max = arr[0];
        arr[0] = arr[i];
        arr[i] = max;
        size = size - 1;
        // cout << "Took out: " << max << endl;
        // for (int i = 0; i < len; i++)
        // {
        //     cout << arr[i] << ";";
        // }
        // cout << "Size: " << size << endl;
        maxHeapify(arr, 0, size);
    }
}
int main(int argc, char **argv)
{
    int len = 0;

    cin >> len;
    int *arr = new int[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ";";
    }
}
