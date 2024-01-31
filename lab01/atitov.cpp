#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void insertFunction(int *array, int value)
{
    int length = sizeof(array) / 2;
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
        cout << "Sorted array" << sortedArray[i] << endl;
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

    insertFunction(arr, 5);
}
