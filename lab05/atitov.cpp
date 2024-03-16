#include <iostream>
using namespace std;

void swap(int *arr, int a, int b)
{
    int x = arr[a];
    arr[a] = arr[b];
    arr[b] = x;
}

int partition(int *arr, int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, r);
    return i;
}

int randomPartition(int *arr, int p, int r)
{
    // cout << "pivot before: " << arr[r] << endl;
    int i = rand() % (r - p + 1) + p;
    swap(arr, i, r);
    // cout << "pivot after: " << arr[r] << endl;
    return partition(arr, p, r);
}

void qsort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = randomPartition(arr, p, r);
        qsort(arr, p, q - 1);
        qsort(arr, q + 1, r);
    }
}

int main(int argc, char **argv)
{
    int arraySize = 0;
    cin >> arraySize;
    int *arr = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }

    qsort(arr, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << ";";
    }
}
