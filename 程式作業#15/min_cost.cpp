#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> upper, pair<int, int> lower) { return upper.first * lower.second < lower.first * upper.second; }

int main()
{
    long long n, cost, total_weight, i;
    while (cin >> n)
    {
        vector<pair<int, int>> data(n); // <w, f>
        for (i = 0; i < n; i++)
            cin >> data[i].first;
        for (i = 0; i < n; i++)
            cin >> data[i].second;
        sort(data.begin(), data.end(), compare);
        cost = total_weight = 0;
        for (i = 0; i < n - 1; i++) // 由上往下計算總成本
        {
            total_weight += data[i].first;
            cost += data[i + 1].second * total_weight;
        }
        cout << cost << endl;
    }

    return 0;
}