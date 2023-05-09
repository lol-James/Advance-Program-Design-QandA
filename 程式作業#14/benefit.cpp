#include <bits/stdc++.h>

using namespace std;

/**
 * int A[n];
 * int dp_max[n][n] // A[i] 到 A[j]的最大效益
 * if j-i < 2 : dp_max[i][j] = 0
 * else : dp_max[i][j] = max{dp_max[i][x] + dp_max[x][j] + A[i]*A[x]*A[j], ∀ i+1 <= x <= j-1}
 * 所求max即為dp[0][n-1] 
**/

int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        int A[m];
        for (int i = 0; i < m; ++i)
            cin >> A[i];

        unsigned int dp_max[m][m], dp_min[m][m];
        for (int i = 0; i < m; i++) // 初始化
        {
            for (int j = i; j < m; j++)
            {
                dp_max[i][j] = 0;
                dp_min[i][j] = 0xffffffff;
            }
        }

        for (int delta = 1; delta <= m - 1; ++delta) // delta = j - i
        {
            for (int i = 0; i < m - delta; ++i)
            {
                int j = i + delta;
                if (delta >= 2)
                    for (int x = i + 1; x <= j - 1; ++x)
                    {
                        dp_max[i][j] = max(dp_max[i][j], dp_max[i][x] + dp_max[x][j] + A[i] * A[x] * A[j]);
                        dp_min[i][j] = min(dp_min[i][j], dp_min[i][x] + dp_min[x][j] + A[i] * A[x] * A[j]);
                    }
                else
                    dp_max[i][j] = dp_min[i][j] = 0;
            }
        }
        cout << dp_max[0][m - 1] << " " << dp_min[0][m - 1] << "\n";
    }

    system("pause");
    return 0;
}
