#include <bits/stdc++.h>
using namespace std;

#define MAXNUM 10000

int sum_arr[MAXNUM + 1] = {0};

long long get_sum(int x)
{
    if (x == 1)
        return 1;
    if (x <= MAXNUM && sum_arr[x])
        return sum_arr[x];

    long long sum = x + get_sum((x % 2) ? 3 * x + 1 : x / 2);

    if (x <= MAXNUM)
        sum_arr[x] = sum;

    return sum;
}



int main()
{
    for (int i = 1; i <= MAXNUM; i++)
        get_sum(i);

    int n;
    cin >> n;
    while (n--)
    {
        int lower, upper;
        cin >> lower >> upper;

        long long max_sum = 0, max_n = 0;
        for (int i = lower; i <= upper; i++)
        {
            long long sum = get_sum(i);
            if (sum > max_sum)
            {
                max_sum = sum;
                max_n = i;
            }
        }

        cout << max_sum << " " << max_n << endl;
    }

    return 0;
}
