#include <iostream>
using namespace std;

void printArr(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << ";";
        }
        cout << endl;
    }
}

void countingSort(int **arr, int size, int column)
{
    int counters[] = {0, 0, 0, 0};
    for (int i = 0; i < size; i++)
    {
        int index = arr[i][column];
        counters[index] += 1;
    }
    cout << counters[0] << " " << counters[1] << " " << counters[2] << " " << counters[3] << endl;
}

int main(int argc, char **argv)
{
    int size;
    cin >> size;
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[10];
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }

    countingSort(arr, size, 0);
    countingSort(arr, size, 1);
    countingSort(arr, size, 2);

    printArr(arr, size);
}
