#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to perform matrix chain multiplication
void printSequence(vector<vector<int>> &brackets, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printSequence(brackets, i, brackets[i][j]);
        printSequence(brackets, brackets[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainMultiplication(vector<int> &dimensions)
{
    int n = dimensions.size() - 1;                      // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));       // Dynamic programming table
    vector<vector<int>> brackets(n, vector<int>(n, 0)); // Table to store optimal parenthesis placement

    // Initialize dp table with INT_MAX
    for (int i = 0; i < n; ++i)
        dp[i][i] = 0;

    // Compute minimum number of scalar multiplications
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }

    // Print minimum number of scalar multiplications
    cout << dp[0][n - 1] << endl;

    // Print matrix multiplication sequence
    printSequence(brackets, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> dimensions(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> dimensions[i];

    matrixChainMultiplication(dimensions);
    cout << endl;
    return 0;
}
