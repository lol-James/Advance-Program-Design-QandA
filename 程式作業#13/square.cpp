#include <bits/stdc++.h>

using namespace std;

inline double sum(double a, double n) { return (a * (pow(4, n) - 1)) / 3.0; }

// 依照4個方向展開的正負號
const double dx[4] = {1, -1, -1, 1};
const double dy[4] = {1, 1, -1, -1};

int main()
{
    double a, b, d, N, x1, y1, n, ans1, ans2;

    while (cin >> a >> b >> d >> N)
    {
        if (a + d <= 0 || b + d <= 0)
        {
            cout << "0 0\n";
            continue;
        }

        queue<pair<double, double>> q;
        q.push({a, b});
        if (a > 0 && b > 0)
        {
            ans1 += a;
            ans2 += b;
        }
        else
        {
            ans1 = 0;
            ans2 = 0;
        }

        N++;
        while (N--)
        {
            d /= 2.0;

            vector<double> x;
            vector<double> y;

            while (!q.empty()) // 從queue取坐標出來
            {
                x.push_back(q.front().first);
                y.push_back(q.front().second);
                q.pop();
            }

            n = x.size();
            for (int k = 0; k < n; k++)
            {
                if (x[k] - 2.0 * d >= 0 && y[k] - 2.0 * d >= 0)
                {
                    ans1 = ans1 + sum(x[k], N + 2) - x[k]; // 避免重複計算 所以要 - x[k]
                    ans2 = ans2 + sum(y[k], N + 2) - y[k];
                    continue;
                }
                if (x[k] + 2.0 * d <= 0 || y[k] + 2.0 * d <= 0) // 一定不可能跑到(I)了
                    continue;

                for (int j = 0; j < 4; j++)
                {
                    x1 = (x[k] + dx[j] * d);
                    y1 = (y[k] + dy[j] * d);
                    if (x1 > 0 && y1 > 0)
                    {
                        ans1 += x1;
                        ans2 += y1;
                    }
                    q.push({x1, y1});
                }
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }

    system("pause");
    return 0;
}