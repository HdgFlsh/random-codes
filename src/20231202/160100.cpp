// luogu-p1191
// [ac]
#include <iostream>
#include <algorithm>
using namespace std;
long long r;
int n, m, st, l[160], s[160], c[160];
string g[160];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    for (int j = 0; j < n; j++)
        l[j] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (((j == 0) ? st = 0 : st), (g[i][j] == 'W' ? l[j] : l[j] = i);;)
                if ((st == 0 || l[s[st - 1]] > l[j]) ? (s[st++] = j, r += (c[st] = (st == 1) ? (j + 1) * (i - l[s[st - 1]]) : c[st - 1] + (j - s[st - 2]) * (i - l[s[st - 1]])), true) : (--st, false))
                    break;
    cout << r;
    return 0;
}