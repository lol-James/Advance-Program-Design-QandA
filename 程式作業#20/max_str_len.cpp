#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    int pos;
    while (cin >> s1 >> s2 >> pos)
    {
        if (s1.length() < s2.length())
        {
            string temp = s1;
            s1 = s2;
            s2 = temp;
        }
        int n = s1.length(), m = s2.length();
        int a[n + 1][m + 1];
        int count[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                count[i][j] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i < j || i - j > n - m)
                {
                    a[i][j] = -1;   // -1：無意義
                    continue;
                }
                if (i == 0) 
                {
                    a[i][j] = 0;
                    continue;
                }
                if (j == 0)
                {
                    a[i][j] = a[i - 1][j] + abs((s1[i - 1] - 'A' + 1) - pos);
                    count[i][j] = count[i - 1][j];
                    continue;
                }

                if (a[i - 1][j] != -1 && a[i - 1][j - 1] == -1)
                {
                    a[i][j] = a[i - 1][j] + abs((s1[i - 1] - 'A' + 1) - pos);
                    count[i][j] = count[i - 1][j];
                }
                else if (a[i - 1][j] == -1 && a[i - 1][j - 1] != -1)
                {
                    a[i][j] = a[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]);
                    count[i][j] = count[i - 1][j - 1];
                }
                else if (a[i - 1][j] == -1 && a[i - 1][j - 1] == -1)
                {
                    a[i][j] = -1;
                }
                else
                {   
                    if (a[i - 1][j] + abs((s1[i - 1] - 'A' + 1) - pos) > a[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]))
                    {   
                        a[i][j] = a[i - 1][j] + abs((s1[i - 1] - 'A' + 1) - pos);
                        count[i][j] = count[i - 1][j];
                    }
                    else if (a[i - 1][j] + abs((s1[i - 1] - 'A' + 1) - pos) < a[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]))
                    {
                        a[i][j] = a[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]);
                        count[i][j] = count[i - 1][j - 1];
                    }
                    else
                    {   
                        a[i][j] = a[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]);
                        count[i][j] = count[i - 1][j] + count[i - 1][j - 1];
                    }
                }
            }
        }

/*         for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << setw(4) << left << a[i][j]; 
            }
            cout << endl;
        }
        cout << "\n\n";
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << setw(4) << left << count[i][j]; 
            }
            cout << endl;
        }
        cout << "\n\n"; */

        cout << a[n][m] << " " << count[n][m] << endl;
    }

    return 0;
}