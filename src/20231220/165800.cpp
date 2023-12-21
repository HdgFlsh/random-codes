// sdsyoj-806
// [ac]
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
int n, m, k, l, r;
array<array<int, (int)1e5 + 5>, 32> q;
array<int, (int)1e5 + 5> a;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        q[0][i] = a[i] = i;
    for (int i = 0; i < m; i++)
        cin >> l >> r, reverse(q[0].begin() + l, q[0].begin() + r + 1);
    for (int j = 1; j <= 31; j++)
        for (int i = 1; i <= n; i++)
            q[j][i] = q[j - 1][q[j - 1][i]];
    for (int j = 31; j >= 0; j--)
        if (k & (1 << j))
            for (int i = 1; i <= n; i++)
                a[i] = q[j][a[i]];
    for (int i = 1; i <= n; i++)
        cout << a[i] << '\n';
    return 0;
}