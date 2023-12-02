// sdsyoj-1816
// [wip]
#include <iostream>
using namespace std;
long long n, m, k, a[2000006], p[2000006], q[2000006], c[2000006];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        q[i] = q[i - 1] + q[i];
        c[i] = c[i - 1] + 1;
        if (p[i] > m)
            p[i] -= p[i - c[i]];
    }
    for (int i = 0; i <= n; i++)
    {
    }
}
