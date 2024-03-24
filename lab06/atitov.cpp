#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<vector<int>> &arr, int exp)
{
    int n = arr.size();
    vector<vector<int>> output(n, vector<int>(10));
    vector<int> count(4, 0);

    for (int i = 0; i < n; ++i)
        count[arr[i][exp] % 4]++;

    for (int i = 1; i < 4; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i][exp] % 4] - 1] = arr[i];
        count[arr[i][exp] % 4]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radix_sort(vector<vector<int>> &vectors)
{
    for (int exp = 9; exp >= 0; --exp)
        counting_sort(vectors, exp);
}

int main()
{
    int num_vectors;
    cin >> num_vectors;
    vector<vector<int>> vectors(num_vectors, vector<int>(10));

    for (int i = 0; i < num_vectors; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> vectors[i][j];

    radix_sort(vectors);

    for (const auto &vec : vectors)
    {
        for (int i = 0; i < 10; ++i)
        {
            cout << vec[i] << ";";
        }
        cout << endl;
    }

    return 0;
}
