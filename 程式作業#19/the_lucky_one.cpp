#include <iostream>
using namespace std;
// 運用遞迴與回推來模擬
/**
 * 先假設編號從0開始
 * f(n, m, k)的幸運兒
 * 與玩一輪後剩下n-1個人剩下k-1回合時的幸運兒是同一個人 (f(n-1, m, k-1) + m) % n
 * 因為f(n, m, k)與f(n-1, m, k-1)的編號起始位置的人不同(相差m)所以+m
 * ex
 * 原有編號0-9 每4人殺一人，第一輪被殺掉的會是編號3
 * 此時重新編號，原編號4改為編號0，以此類推
*/
int f(int n, int m, int k) { return (k == 0) ? 0 : (f(n - 1, m, k - 1) + m) % n; }

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k) cout << f(n, m, k) + 1 << endl;
    
    return 0;
}