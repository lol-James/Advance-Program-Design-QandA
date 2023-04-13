#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int a[1001][1001];

        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++)
                a[i][j] = 0;

        int num1, num2, count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num1 >> num2;

            if (a[num2][num1] == 0)
            {
                a[num1][num2]++;
            }
            else
            {
                a[num2][num1]--;
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}