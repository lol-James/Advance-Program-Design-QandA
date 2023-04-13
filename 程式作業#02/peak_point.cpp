#include <bits/stdc++.h>

using namespace std;

int peak_point_value(int values[]);
int Lfind_zero_point(int values[], int peak_point_index);
int Rfind_zero_point(int values[], int peak_point_index);
int zero_point_value(int values[], int peak_point_index);

int main()
{
    int L, W, i, j, peak_point_index;
    int output1, output2;

    while (scanf("%d %d", &L, &W) != EOF)
    {
        int a[L][W], values[256] = {0};

        for (i = 0; i < L; i++)
            for (j = 0; j < W; j++)
                cin >> a[i][j];

        for (i = 0; i < L; i++)
            for (j = 0; j < W; j++)
                values[a[i][j]]++;

        output1 = peak_point_value(values);

        for (i = 255; i >= 0; i--)
        {
            if (values[i] == output1)
            {
                peak_point_index = i;
                break;
            }
        }

        output2 = zero_point_value(values, peak_point_index);

        cout << output1 << endl;
        cout << output2 << endl;
    }

    return 0;
}

int peak_point_value(int values[])
{
    int max = -1;

    for (int i = 0; i < 256; i++)
        if (values[i] > max)
            max = values[i];

    return max;
}

int Lfind_zero_point(int values[], int peak_point_index)
{
    int i;

    for (i = peak_point_index - 1; i >= 0; i--)
        if (values[i] == 0)
            return i;

    return -1;
}

int Rfind_zero_point(int values[], int peak_point_index)
{
    int i;

    for (i = peak_point_index + 1; i <= 255; i++)
        if (values[i] == 0)
            return i;

    return -1;
}

int zero_point_value(int values[], int peak_point_index)
{
    int Lindex = Lfind_zero_point(values, peak_point_index);
    int Rindex = Rfind_zero_point(values, peak_point_index);

    if (Lindex == -1 && Rindex == -1)
        return -1;
    else if (Lindex == -1 && Rindex != -1)
        return Rindex;
    else if (Rindex == -1 && Lindex != -1)
        return Lindex;
    else if ((peak_point_index - Lindex) <= (Rindex - peak_point_index))
        return Lindex;
    else
        return Rindex;
}