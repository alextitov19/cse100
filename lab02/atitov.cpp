#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void mergeSort(int *arr, int len)
{
    if (len > 1)
    {
        int lenleft = len / 2;
        int lenright = len - lenleft;
        int *leftarr = new int[lenleft];
        int *rightarr = new int[lenright];

        for (int i = 0; i < lenleft; i++)
        {
            leftarr[i] = arr[i];
            cout << leftarr[i] << " ";
        }
        cout << endl;

        for (int i = lenleft; i < len; i++)
        {
            rightarr[i] = arr[i];
            cout << rightarr[i] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    // Populate the array
    int arraySize = 0;

    cin >> arraySize;
    int *arr = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, arraySize);
}
