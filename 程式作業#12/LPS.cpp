#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int n = str.length();
        int max_len = 0;
        vector<int> palindromes;

        // odd
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                if (r - l + 1 > max_len)
                {
                    max_len = r - l + 1;
                    palindromes.clear();
                    palindromes.push_back(l);
                }
                else if (r - l + 1 == max_len)
                {
                    palindromes.push_back(l);
                }
                l--;
                r++;
            }
        }

        // even
        for (int i = 0; i < n - 1; i++)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && str[l] == str[r])
            {
                if (r - l + 1 > max_len)
                {
                    max_len = r - l + 1;
                    palindromes.clear();
                    palindromes.push_back(l);
                }
                else if (r - l + 1 == max_len)
                {
                    palindromes.push_back(l);
                }
                l--;
                r++;
            }
        }

        if (max_len == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << max_len << " ";
            for (int i = 0; i < palindromes.size(); i++)
            {
                cout << str.substr(palindromes[i], max_len);
                if (i < palindromes.size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }

    return 0;
}
