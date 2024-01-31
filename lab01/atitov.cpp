#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void insertFunction(int *array, int value, int length)
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
    for (int i = 0; i <= length; i++)
    {
        cout << "Sorted array value at index " << i << " is " << sortedArray[i] << endl;
    }
    return;
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

    insertFunction(sortedArray, arr[1], 1);
}
