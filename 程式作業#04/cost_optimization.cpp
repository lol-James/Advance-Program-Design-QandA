#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int m;
    unsigned int i, j;
    unsigned int min_cost = 0, T_cost = 0;

    while (cin >> m)
    {
        int land[m][m];

        min_cost = 0xffffffff;
        T_cost = 0;

        for (i = 0; i < m; i++)
            for (j = 0; j < m; j++)
                cin >> land[i][j];

        // T_down building
        for (i = 1; i <= m - 1; i++)
        {
            for (j = 1; j <= m - 2; j++)
            {
                T_cost = land[i][j] + land[i - 1][j - 1] + land[i - 1][j] + land[i - 1][j + 1];
                min_cost = T_cost < min_cost ? T_cost : min_cost;
            }
        }

        // T_up building
        for (i = 0; i <= m - 2; i++)
        {
            for (j = 1; j <= m - 2; j++)
            {
                T_cost = land[i][j] + land[i + 1][j - 1] + land[i + 1][j] + land[i + 1][j + 1];
                min_cost = T_cost < min_cost ? T_cost : min_cost;
            }
        }

        // T_left building
        for (i = 1; i <= m - 2; i++)
        {
            for (j = 0; j <= m - 2; j++)
            {
                T_cost = land[i][j] + land[i][j + 1] + land[i - 1][j + 1] + land[i + 1][j + 1];
                min_cost = T_cost < min_cost ? T_cost : min_cost;
            }
        }

        // T_rignt building
        for (i = 1; i <= m - 2; i++)
        {
            for (j = 1; j <= m - 1; j++)
            {
                T_cost = land[i][j] + land[i][j - 1] + land[i - 1][j - 1] + land[i + 1][j - 1];
                min_cost = T_cost < min_cost ? T_cost : min_cost;
            }
        }

        cout << min_cost << endl;
    }

    return 0;
}