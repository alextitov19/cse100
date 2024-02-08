#include <iostream>
using namespace std;

int *merge(int *leftarr, int *rightarr, int leftlen, int rightlen)
{
    int *arr = new int[leftlen + rightlen];
    int l = 0;
    int r = 0;
    for (int i = 0; i < leftlen + rightlen; i++)
    {
        if (l == leftlen)
        {
            arr[i] = rightarr[r];
            r++;
        }
        else if (r == rightlen)
        {
            arr[i] = leftarr[l];
            l++;
        }
        else
        {
            if (leftarr[l] < rightarr[r])
            {
                arr[i] = leftarr[l];
                l++;
            }
            else
            {
                arr[i] = rightarr[r];
                r++;
            }
        }
    }
    return arr;
}

int *mergeSort(int arr[], int len)
{
    if (len > 1)
    {
        int lenleft = len / 2;
        int lenright = len - lenleft;
        int leftarr[lenleft];
        int rightarr[lenright];
        int index = 0;
        // cout << "Left length = " << lenleft << " : ";
        for (int i = 0; i < lenleft; i++)
        {
            leftarr[i] = arr[index];
            index++;
            // cout << leftarr[i] << " ";
        }
        // cout << endl;

        // cout << "Right length = " << lenright << " : ";
        for (int i = 0; i < lenright; i++)
        {
            rightarr[i] = arr[index];
            index++;
            // cout << rightarr[i] << " ";
        }
        // cout << endl;

        int *splitLeft = mergeSort(leftarr, lenleft);
        int *splitRight = mergeSort(rightarr, lenright);
        return merge(splitLeft, splitRight, lenleft, lenright);
    }
    return arr;
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

    int *sorted = mergeSort(arr, arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        cout << sorted[i] << ";";
    }
}
