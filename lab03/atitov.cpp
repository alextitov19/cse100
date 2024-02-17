#include <iostream>
using namespace std;

tuple<int, int, int> findMaxCrossingSubarray(int arr[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;
    int maxRight = mid + 1;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }
    return make_tuple(maxLeft, maxRight, leftSum + rightSum);
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
    int low, high, sum;
    tie(low, high, sum) = findMaxCrossingSubarray(arr, 0, int(arraySize / 2), arraySize - 1);
    cout << "Sum = " << sum << " Left = " << low << " Right = " << high << endl;
}
