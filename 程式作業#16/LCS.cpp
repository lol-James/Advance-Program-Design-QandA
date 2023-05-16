#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;

    while (cin >> s1 >> s2)
    {
        s1 = "0" + s1;
        s2 = "0" + s2;
        int m = s2.length(), n = s1.length();
        string a[m][n];

        for (int i = 0; i < n; i++)
            if (s2[0] == s1[i])
                a[0][i] = s2[0];
            else
                a[0][i] = "0";

        for (int i = 0; i < m; i++)
            if (s2[i] == s1[0])
                a[i][0] = s1[0];
            else
                a[i][0] = "0";

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (s2[i] == s1[j])
                {
                    a[i][j] = a[i - 1][j - 1] + s1[j];
                }
                else
                {
                    if ((a[i][j - 1]).length() > (a[i - 1][j]).length())
                        a[i][j] = a[i][j - 1];
                    else if ((a[i][j - 1]).length() < (a[i - 1][j]).length())
                        a[i][j] = a[i - 1][j];
                    else
                        a[i][j] = stoull(a[i][j - 1]) < stoull(a[i - 1][j]) ? a[i - 1][j] : a[i][j - 1];
                }
            }
        }

        cout << stoull(a[m - 1][n - 1]) << endl;
    }

    return 0;
}