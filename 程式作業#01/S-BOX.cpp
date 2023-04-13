#include <bits/stdc++.h>

using namespace std;

const int S_BOX_chart[4][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                                {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                                {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                                {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

int two_bits_to_decimal(char two_bits_binary[]);
int four_bits_to_decimal(string four_bits_binary);
int convert_by_S_BOX_chart(int row, int col);
void convert_and_output_binary_number(int num);
void S_BOX_convert(string binary_string);

int main()
{
    string binary_string;

    while (cin >> binary_string)
        S_BOX_convert(binary_string);

    return 0;
}

int two_bits_to_decimal(char two_bits_binary[])
{
    int sum = 0;
    if (two_bits_binary[0] == '1')
        sum += 2;

    if (two_bits_binary[1] == '1')
        sum += 1;

    return sum;
}

int four_bits_to_decimal(string four_bits_binary)
{
    int sum = 0, i;

    for (i = 0; i < 4; i++)
    {
        if (four_bits_binary[i] == '1')
            sum += pow(2, 3 - i);
    }

    return sum;
}

int convert_by_S_BOX_chart(int row, int col)
{
    return S_BOX_chart[row][col];
}

void convert_and_output_binary_number(int num)
{
    int ans[4] = {0}, i = 3;

    while (num)
    {
        ans[i--] = num % 2;
        num /= 2;
    }

    for (i = 0; i < 4; i++)
        cout << ans[i];
    cout << endl;
}

void S_BOX_convert(string binary_string)
{
    string four_bits_binary;
    char two_bits_binary[2];

    two_bits_binary[0] = binary_string[0];
    two_bits_binary[1] = binary_string[5];
    four_bits_binary = binary_string.substr(1, 4);

    int row = two_bits_to_decimal(two_bits_binary);
    int col = four_bits_to_decimal(four_bits_binary);

    convert_and_output_binary_number(convert_by_S_BOX_chart(row, col));
}