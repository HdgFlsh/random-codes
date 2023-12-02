// luogu-p5300
// [wip]
#include <iostream>
#include <algorithm>
using namespace std;
long long r;
int n, m, st, l[1010], s[1010], c[1010];
bool g[1010][1010];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    for (int j = 0; j < n; j++)
        l[j] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (((j == 0) ? st = 0 : st), (g[i][j] ? l[j] : l[j] = i);;)
                if ((st == 0 || l[s[st - 1]] > l[j]) ? (s[st++] = j, r += (c[st] = (st == 1) ? (j + 1) * (i - l[s[st - 1]]) : c[st - 1] + (j - s[st - 2]) * (i - l[s[st - 1]])), true) : (--st, false))
                    break;
    cout << r << ' ';
    r = 0;
    for (int j = 0; j < n; j++)
        l[j] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (((j == 0) ? st = 0 : st), (g[i][j] ? l[j] = i: l[j]);;)
                if ((st == 0 || l[s[st - 1]] > l[j]) ? (s[st++] = j, r += (c[st] = (st == 1) ? (j + 1) * (i - l[s[st - 1]]) : c[st - 1] + (j - s[st - 2]) * (i - l[s[st - 1]])), true) : (--st, false))
                    break;
    cout << r;
    return 0;
}
// https://www.cnblogs.com/LMCC1108/p/10876712.html