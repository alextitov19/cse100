#include <iostream>
using namespace std;

tuple<int, int, int> findMaxCrossingSubarray(int *arr, int low, int mid, int high)
{
    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;
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
    int rightSum = INT_MIN;
    int maxRight = mid + 1;
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

tuple<int, int, int> findMaxSubarray(int *arr, int low, int high)
{
    if (high == low)
    {
        return make_tuple(low, high, arr[low]);
    }
    int mid = int((low + high) / 2);
    int leftLow, leftHigh, leftSum;
    tie(leftLow, leftHigh, leftSum) = findMaxSubarray(arr, low, mid);
    int rightLow, rightHigh, rightSum;
    tie(rightLow, rightHigh, rightSum) = findMaxSubarray(arr, mid + 1, high);
    int crossLow, crossHigh, crossSum;
    tie(crossLow, crossHigh, crossSum) = findMaxCrossingSubarray(arr, low, mid, high);
    if (leftSum >= rightSum && leftSum >= crossSum)
    {
        return make_tuple(leftLow, leftHigh, leftSum);
    }
    else if (rightSum >= leftSum && rightSum >= crossSum)
    {
        return make_tuple(rightLow, rightHigh, rightSum);
    }
    return make_tuple(crossLow, crossHigh, crossSum);
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
    tie(low, high, sum) = findMaxSubarray(arr, 0, arraySize - 1);
    cout << sum;
}
