#include <bits/stdc++.h>

using namespace std;

bool is_prime(unsigned long long int value);
unsigned long long int find_SBN(unsigned long long int value);

int main()
{
    unsigned long long int num;
    while (cin >> num)
        cout << find_SBN(num) << endl;

    return 0;
}

bool is_prime(unsigned long long int value)
{
    if (value == 1)
        return false;

    unsigned long long int sqrt_value = sqrt(value);
    for (unsigned long long int i = 2; i <= sqrt_value; i++)
        if (!(value % i))
            return false;

    return true;
}

unsigned long long int find_SBN(unsigned long long int value)
{
    bitset<32> value_bits(value);
    string value_str = value_bits.to_string();

    do
    {
        bitset<32> temp_bits(value_str);
        unsigned long long int temp = temp_bits.to_ullong();
        if (is_prime(temp))
            return temp;
    } while (prev_permutation(value_str.begin(), value_str.end()));

    return 0;
}
