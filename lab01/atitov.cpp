#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int *insertFunction(int *array, int value, int length)
{
    int *sortedArray = new int[length + 1];
    int j = 0;
    bool added = false;
    for (int i = 0; i < length; i++)
    {
        if (array[i] < value || added)
        {
            sortedArray[j] = array[i];
        }
        else
        {
            sortedArray[j] = value;
            j++;
            added = true;
            sortedArray[j] = array[i];
        }
        j++;
    }
    if (!added)
    {
        sortedArray[length] = value;
    }

    return sortedArray;
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

    for (int i = 0; i < arraySize; i++)
    {
        cout << "Array value at index " << i << " is " << arr[i] << endl;
    }

    int *sortedArray = new int[1];
    sortedArray[0] = arr[0];

    for (int i = 1; i < arraySize; i++)
    {
        sortedArray = insertFunction(sortedArray, arr[i], i);
        for (int j = 0; j <= i; j++)
        {
            cout << "Sorted array value at index " << j << " is " << sortedArray[j] << endl;
        }
    }
}
