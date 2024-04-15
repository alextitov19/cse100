#include <iostream>
#include <vector>

using namespace std;

pair<int, vector<int>> rod_cutting(int n, vector<int> &prices)
{
    vector<int> revenue(n + 1, 0);
    vector<int> cuts(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        int max_revenue = INT_MIN;
        for (int j = 1; j <= i; ++j)
        {
            if (prices[j] + revenue[i - j] > max_revenue)
            {
                max_revenue = prices[j] + revenue[i - j];
                cuts[i] = j;
            }
        }
        revenue[i] = max_revenue;
    }

    int max_revenue = revenue[n];
    vector<int> optimal_cuts;
    while (n > 0)
    {
        optimal_cuts.push_back(cuts[n]);
        n -= cuts[n];
    }

    return make_pair(max_revenue, optimal_cuts);
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> prices[i];
    }

    auto result = rod_cutting(n, prices);

    cout << result.first << endl;
    for (int cut : result.second)
    {
        cout << cut << " ";
    }
    cout << "-1" << endl;

    return 0;
}
