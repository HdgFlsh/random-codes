// sdsyoj-555 / luogu-p3400
// [tle] / [ac]
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long r;
int n, m, st, l[3005], s[3005], c[3005];
bool g[3005][3005];

struct fiostream
{
    int q;
};

template<typename T>
fiostream &operator>>(fiostream &input, T &r)
{
    char ch;
    r = 0;
    bool s = false;
    while ((ch = getchar()) < '0' || ch > '9')
        s |= ch == '-';
    do
        r = r * 10 + ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9');
    r *= (s ? -1 : 1);
    return input;
}

int main()
{
    fiostream fcin;
    fcin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fcin >> g[i][j];
    for (int j = 0; j < m; j++)
        l[j] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (((j == 0) ? st = 0 : st), (g[i][j] ? l[j] : l[j] = i);;)
                if ((st == 0 || l[s[st-1]] > l[j]) ? (s[st++] = j, r += (c[st] = (st == 1) ? (j + 1) * (i - l[s[st - 1]]) : c[st - 1] + (j - s[st - 2]) * (i - l[s[st - 1]])), true) : (--st, false))
                    break;
    cout << r;
    return 0;
}